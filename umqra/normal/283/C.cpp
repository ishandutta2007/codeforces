#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int mod = (int)1e9 + 7;
const int N = 310;

int add(int a, int b)
{
	return (a + b < mod ? a + b : a + b - mod);
}

int to[N];     
int a[N];
int dp[(int)1e6];
bool used[N][(int)1e5 + 10];
int cost[N];
bool usedG[N];
bool magic[N];
int cheat[(int)1e6];
int locUsed[(int)1e6];
int cc = 1;
int ind = 0;

void dfs(int v, int sum = 0)
{
	if (v == -1)
		return;
	if (to[v] == -1)
		magic[ind] = 1;
	a[ind++] = sum + cost[v];      
	dfs(to[v], sum + cost[v]);
}       

bool check(int v, int t)
{                                 
	if (v == t)
		return false;
	if (v == -1)
		return true;	
	return check(to[v], t);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
#endif

	fill(to, to + N, -1);
	int n, q, t;
	scanf("%d%d%d", &n, &q, &t);

	for (int i = 0; i < n; i++)
		scanf("%d", &cost[i]);

	for (int i = 0; i < q; i++)
	{
		int b, c;
		scanf("%d%d", &b, &c);
		b--, c--;
		to[b] = c;        
		usedG[c] = 1;
	}

	for (int i = 0; i < n; i++)
		if (!check(to[i], i))
		{
			puts("0");
			return 0;
		}

	for (int i = 0; i < n; i++)
	{
		if (!usedG[i])
			dfs(i);
	}
                                                
	dp[0] = 1;
	used[0][0] = 1;
//	for (int i = 0; i < ind; i++)
//		cout << a[i] << ' ';
//	cout << endl;
                   

	for (int i = 0; i < ind; i++)
	{                                       
//		for (int s = 0; s <= t; s++)
//			if (used[i][s])
//				cout << s << ":" << dp[s] << ' ';
//		cout << endl;
		cc++;
		for (int s = 0; s <= t; s++)
		{
			if (used[i][s])
			{
				cheat[s] = dp[s];   
				locUsed[s] = cc;
			}
			else
				cheat[s] = 0;
			dp[s] = 0;
		}                        
		for (int s = 0; s <= t - a[i]; s++)   
		{
			if (used[i][s])
			{
				dp[s + a[i]] = add(dp[s + a[i]], add(cheat[s], dp[s]));
				used[i + 1][s + a[i]] = 1;     
				used[i][s + a[i]] = 1;
			}                  
		}                            
		if (magic[i])
		{
			for (int s = 0; s <= t; s++)
				if (locUsed[s] == cc)
				{
					dp[s] = add(dp[s], cheat[s]);
					used[i + 1][s] = 1;
				}	
		}
	}
	
//	for (int i = 0; i <= t; i++)
//		 if (used[ind][i])
//		 	cout << i << ":" << dp[i] << ' ';
//	cout << endl;

	printf("%d", dp[t]);


	return 0;
}