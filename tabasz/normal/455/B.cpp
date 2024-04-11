#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<math.h>
#include<queue>
#include<iostream>
#include<map>
#include<string>
using namespace std;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define LL long long
#define D double

string S[100005];
vector<int> V[100005];
int B[2][100005];
int T[26][100005];

bool DFS(int ind, int v)
{
	if(B[ind][v]==0)
	{
		bool b=0;
		for(int i=0; i<26; i++) if(T[i][v]>0 && !DFS(ind, T[i][v])) b=1;
		if(b) B[ind][v]=1;
		else B[ind][v]=-1;
	}
	if(B[ind][v]==1) return true;
	else return false;
}

int main()
{
	int n, k, num=1;
	scanf("%d%d", &n, &k);
	for(int i=0; i<n; i++) cin>> S[i];
	for(int i=0; i<n; i++)
	{
		int v=0;
		for(int j=0; j<(int)S[i].size(); j++)
		{
			if(T[(int)S[i][j]-(int)'a'][v]==0)
			{
				T[(int)S[i][j]-(int)'a'][v]=num;
				num++;
			}
			v=T[(int)S[i][j]-(int)'a'][v];
		}
	}
	for(int i=0; i<num; i++)
	{
		bool b=0;
		for(int j=0; j<26; j++) if(T[j][i]>0) b=1;
		if(!b)
		{
			B[0][i]=-1;
			B[1][i]=1;
		}
	}
	DFS(0, 0);
	DFS(1, 0);
	if(B[0][0]==-1)
	{
		printf("Second\n");
		return 0;
	}
	if(B[1][0]==1)
	{
		printf("First\n");
		return 0;
	}
	if(k%2==1) printf("First\n");
	else printf("Second\n");
	return 0;
}