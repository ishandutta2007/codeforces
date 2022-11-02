#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<cmath>
#include<iostream>
#include<string>
using namespace std;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define LL long long
#define PII pair<int, int> 
#define PLL pair<LL, LL> 

int n, k;
int R[200005], in[200005];
vector<int> V[200005];
bool B[200005];
queue<int> Q;
vector<int> W[200005];

bool erase(int v)
{
	bool boo=0;
	for(int i=0; i<(int)W[v].size(); i++)
	{
		if((W[v][i]>0 && R[W[v][i]]==1) || (W[v][i]<0 && R[-W[v][i]]==2))
			boo=1;
		int qwe=abs(W[v][i]);
		if(R[abs(W[v][i])]==0)
		{
			boo=1;
			if(W[v][i]>0)
				R[abs(W[v][i])]=1;
			else
				R[abs(W[v][i])]=2;
			in[abs(V[qwe][0])]--;
			in[abs(V[qwe][1])]--;
			if(in[abs(V[qwe][0])]==1)
				Q.push(abs(V[qwe][0]));
			if(in[abs(V[qwe][1])]==1)
				Q.push(abs(V[qwe][1]));
			break;
		}
	}
	return boo;
}

int main()
{
	//ios_base::sync_with_stdio(0);
	scanf("%d%d", &n, &k);
	for(int i=1; i<=n; i++)
	{
		int a;
		scanf("%d", &a);
		for(int j=0; j<a; j++)
		{
			int b;
			scanf("%d", &b);
			W[i].PB(b);
			if(b<0)
				V[-b].PB(-i);
			else
				V[b].PB(i);
		}
		in[i]=a;
	}
	for(int i=1; i<=k; i++)
	{
		if(V[i].size()==0)
			R[i]=1;
		if(V[i].size()==1)
		{
			B[abs(V[i][0])]=1;
			if(V[i][0]>0)
				R[i]=1;
			else
				R[i]=2;
			//printf("heh %d %d\n", i, V[i][0]);
		}
		if(V[i].size()==2 && (LL)V[i][0]*(LL)V[i][1]>0)
		{
			B[abs(V[i][0])]=1;
			B[abs(V[i][1])]=1;
			if(V[i][0]>0)
				R[i]=1;
			else
				R[i]=2;
		}
	}
	for(int i=1; i<=n; i++)
	{
		if(!B[i] && in[i]==1)
		{
			Q.push(i);
			//printf("lol %d\n", i);
		}
	}
	/*while(!Q.empty())
	{
		int v=Q.front();
		Q.pop();
		if(!erase(v))
		{
			printf("NO\n");
			return 0;
		}
		else
			B[v]=1;
	}*/
	//printf("lol \n");
	for(int i=1; i<=n; i++)
	{
		while(!Q.empty())
		{
			int v=Q.front();
			Q.pop();
			if(B[v]==1)
				continue;
			//printf("qwe %d\n", v);
			if(!erase(v))
			{
				printf("NO\n");
				return 0;
			}
			else
				B[v]=1;
		}
		if(!B[i])
		{
			//printf("asd %d\n", i);
			if(!erase(i))
			{
				printf("NO\n");
				return 0;
			}
			else
				B[i]=1;
		}
	}
	printf("YES\n");
	for(int i=1; i<=k; i++)
	{
		if(R[i]<2)
			printf("1");
		else
			printf("0");
	}
	printf("\n");
	return 0;
}