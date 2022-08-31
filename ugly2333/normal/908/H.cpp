//CF908H
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
typedef double DB;
const int N = 55;
char ch[N];
int n,m,a[N][N],f[N],c[N],e[N][N],p[N][N],s[N];
bool t[N];
vector<int> b[N];
int fnd(int x){
	if(f[x]==x)
		return x;
	return f[x]=fnd(f[x]);
}
void dfs(int u){
	int i;
	for(i=1;i<=m;i=i+1)
		if(e[u][i])
			t[s[i]]=1;
	for(i=1;i<=m;i=i+1)
		if(!t[i])
			break;
	s[u]=i;
	memset(t,0,sizeof(t));
	for(i=1;i<=m;i=i+1)
		if(e[u][p[u][i]]&&!s[p[u][i]])
			dfs(p[u][i]);
}
int main()
{
	int i,j,x,ans;
	scanf("%d",&n);
	for(i=1;i<=n;i=i+1){
		scanf("%s",ch+1);
		for(j=1;j<=n;j=j+1){
			if(ch[j]=='-')
				a[i][j]=-1;
			if(ch[j]=='O')
				a[i][j]=0;
			if(ch[j]=='X')
				a[i][j]=1;
			if(ch[j]=='A')
				a[i][j]=2;
		}
	}
	for(i=1;i<=n;i=i+1)
		f[i]=i;
	for(i=1;i<=n;i=i+1)
		for(j=1;j<=n;j=j+1)
			if(a[i][j]==2)
				f[fnd(i)]=fnd(j);
	for(i=1;i<=n;i=i+1)
		b[fnd(i)].push_back(i);
	for(i=1;i<=n;i=i+1){
		if(b[i].size()<=1)
			continue;
		m++;
		for(j=0;j<b[i].size();j=j+1)
			c[b[i][j]]=m;
	}
	for(i=1;i<=n;i=i+1){
		for(j=1;j<=n;j=j+1){
			if(!c[i]||!c[j])
				continue;
			if(a[i][j]==1){
				if(c[i]==c[j]){
					cout<<-1;
					return 0;
				}
				e[c[i]][c[j]]=1;
				e[c[j]][c[i]]=1;
			}
		}
	}
	for(i=1;i<=m;i=i+1)
		for(j=1;j<=m;j=j+1)
			p[i][j]=j;
	ans=N;
	for(i=1;i<=11111;i=i+1){
		for(j=1;j<=m;j=j+1)
			random_shuffle(p[j]+1,p[j]+m+1);
		for(j=1;j<=m;j=j+1)
			if(!s[j])
				dfs(j);
		x=0;
		for(j=1;j<=m;j=j+1)
			x=max(x,s[j]),s[j]=0;
		ans=min(ans,x);
	}
	cout<<n-1+ans;
	return 0;
}