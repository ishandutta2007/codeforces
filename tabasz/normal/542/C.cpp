#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
#include<set>
#include<map>
#include<iostream>
#include<ctime>
#include<queue>
using namespace std;
#define F first
#define S second
#define MP make_pair
#define LL long long
#define PB push_back
#define PII pair<int, int>

int n, d;
int T[202], in[202], R[202];
bool vis[202];
queue<int> Q;

LL nww(LL a, LL b)
{
	return (a/__gcd(a, b))*b;
}

int DFS(int v)
{
	if(T[v]==0) return 1;
	vis[v]=1;
	if(vis[T[v]]) return 1;
	return DFS(T[v])+1;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin>> n;
	for(int i=1; i<=n; i++)
	{
		int a;
		cin>> a;
		if(a!=i)
		{
			in[a]++;
			T[i]=a;
		}
	}
	for(int i=1; i<=n; i++)
	{
		if(in[i]==0 && T[i]!=0)
		{
			Q.push(i);
		}
	}
	while(!Q.empty())
	{
		int v=Q.front();
		vis[v]=1;
		Q.pop();
		if(T[v]!=0)
		{
			R[T[v]]=max(R[T[v]], R[v]+1);
			d=max(d, R[T[v]]);
			//printf("   %d %d\n", v, d);
			in[T[v]]--;
			if(in[T[v]]==0) Q.push(T[v]);
		}
	}
	LL res=1;
	for(int i=1; i<=n; i++)
	{
		if(!vis[i])
		{
			res=nww(res, (LL)DFS(i));
		}
	}
	//printf("%lld %lld\n", res, d);
	LL tmp=res;
	while(res<d) res+=tmp;
	//if(res%2==0 && res/2>=d) res/=2;
	cout<< res << '\n';
	return 0;
}