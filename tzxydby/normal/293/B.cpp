#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007ll
#define REP(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
int filled[1010][1010];
int a[20][20];
int b[20][20];
int X,Y,K;
int p[20];
int exist[20];
long long count_matchings()
{
	REP(i,K)
		p[i]=-1;
	REP(i,K)
		exist[i]=false;
	REP(i,X)
		REP(j,Y)
	if(filled[i][j]!=-1)
	{
		int x=filled[i][j];
		int y=a[i][j];
		if(p[y]!=-1&&p[y]!=x)
			return 0;
		p[y]=x;
	}
	REP(i,X)REP(j,Y)
		exist[a[i][j]]=true;
	REP(i,K)REP(j,i)
		if(p[i]==p[j]&&p[i]!=-1)	
			return 0;
	int n=K,k=0;
	REP(i,K)
	{
		if(p[i]!=-1)	
			n--;
		if(p[i]==-1&&exist[i])	
			k++;
	}
	long long ans=1;
	REP(i,k)
		ans=ans*(n-i)%MOD;
	return ans;
}
bool check(int x,int y)
{
	b[x][y]=0;
	if(x!=0)	
		b[x][y]|=b[x-1][y];
	if(y!=0)	
		b[x][y]|=b[x][y-1];
	if(b[x][y]&(1<<a[x][y]))	
		return false;
	b[x][y]|=(1<<a[x][y]);
	return true;
}
long long dfs(int x,int y,int used)
{
	if(x==X)	
		return count_matchings();
	int x2=x,y2=y+1;
	if(y2==Y)	
		x2++,y2=0;
	long long ans=0;
	for(int i=0;i<used+1;i++)
	if(i<K)
	{
		a[x][y]=i;
		if(check(x,y))
		{
			ans+=dfs(x2,y2,max(used,i+1));
			if(ans>=MOD)	
				ans-=MOD;	
		}
		a[x][y]=-1;
	}
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	cin>>X>>Y>>K;
	for(int i=0;i<X;i++)
		for(int j=0;j<Y;j++)
			cin>>filled[i][j],filled[i][j]--;
	if(X+Y-1>K)
	{
		cout<<0<<endl;
		return 0;
	}
	long long ans=0;
	ans=dfs(0,0,0);
	cout<<ans<<endl;
	return 0;
}