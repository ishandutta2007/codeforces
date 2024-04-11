//CF 299D
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
const int N = 11;
const int mod = 1e9+7;
int n,m,k;
LL ans;
int a[N][N],f[N][N][N],mp[N];
int cnt(int mc){
	int i,j,s,t;
	LL res;
	for(i=1;i<=mc;i=i+1)
		for(j=i+1;j<=mc;j=j+1)
			if(mp[i]&&mp[j]&&mp[i]==mp[j])
				return 0;
	res=1;
	s=0;
	for(i=1;i<=mc;i=i+1)
		if(!mp[i])
			s++;
	t=k-mc+s;
	for(i=1;i<=s;i=i+1){
		res=(res*t)%mod;
		t--;
	}
	//cout<<res<<endl;
	return res%mod;
}
void dfs(int x,int y,int mc)
{
	//cout<<x<<y<<mc<<endl;
	int c,i,j,t;
	if(x>n){
		ans=(ans+cnt(mc))%mod;
		return;
	}
	for(c=1;c<=min(k,mc+1);c=c+1){
		if(f[x][y][c]||mp[c]&&a[x][y]&&a[x][y]!=mp[c])
			continue;
		for(i=x;i<=n;i=i+1)
			for(j=y;j<=m;j=j+1)
				f[i][j][c]++;
		t=mp[c];
		if(!t)
			mp[c]=a[x][y];
		if(y==m)
			dfs(x+1,1,max(c,mc));
		else
			dfs(x,y+1,max(c,mc));
		for(i=x;i<=n;i=i+1)
			for(j=y;j<=m;j=j+1)
				f[i][j][c]--;
		mp[c]=t;
	}
}
int main()
{
	int i,j;
	cin>>n>>m>>k;
	if(n+m>k+1){
		cout<<"0\n";
		return 0;
	}
	for(i=1;i<=n;i=i+1)
		for(j=1;j<=m;j=j+1)
			cin>>a[i][j];
	memset(f,0,sizeof(f));
	memset(mp,0,sizeof(mp));
	ans=0;
	dfs(1,1,0);
	cout<<ans<<endl;
	return 0;
}
/*
3 3 10
0 0 2
2 0 0
0 3 10

*/