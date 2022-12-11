#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstdlib>
using namespace std;
   
const int N = (int)1e6;
const int DX[] = {0, 1, 0, -1};
const int DY[] = {1, 0, -1, 0};
         
char ansC[N];
int ansA[N], ansB[N];
char table[501][501];
bool used[501][501];        
    
int n, m;
int ind;

bool check(int a, int b)
{
	if (a < 0 || b < 0 || a >= n || b >= m || table[a][b] == '#')
		return false;
	return true;
}
  
void dfs(int a, int b, bool flag = true)
{
	ansC[ind] = 'B';
    ansA[ind] = a;
    ansB[ind++] = b;

	used[a][b] = 1;
	for (int i = 0; i < 4; i++)
	{
		int x = a + DX[i];
		int y = b + DY[i];
		if (check(x, y) && !used[x][y])
		{
			dfs(x, y, false);
		}
	}
	if (!flag)
	{               
		ansC[ind] = 'D';
		ansA[ind] = a;
	    ansB[ind++] = b;
	
		ansC[ind] = 'R';
		ansA[ind] = a;
	    ansB[ind++] = b;
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
#endif
             

	scanf("%d%d\n", &n, &m);
	for (int i = 0; i < n; i++)
	{
		for (int s = 0; s < m; s++)
			scanf("%c", &table[i][s]);
		scanf("\n");
	}

	for (int i = 0; i < n; i++)
		for (int s = 0; s < m; s++)
		{
			if (!used[i][s] && check(i, s))
				dfs(i, s);  
		}

	printf("%d\n", ind);
	for (int i = 0; i < ind; i++)
		printf("%c %d %d\n", ansC[i], ansA[i] + 1, ansB[i] + 1);

	return 0;
}