//CF 956A
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
typedef double DB;
const int N = 111;
int n,m,s,a[N][N],b[N],vis[N];
char ch[N];
void dfs(int u){
	int i;
	vis[u]=1;
	b[++s]=u;
	for(i=1;i<=n+m;i=i+1)
		if((!vis[i])&&a[u][i])
			dfs(i);
}
int main()
{
	int i,j,k;
	cin>>n>>m;
	for(i=1;i<=n;i=i+1){
		cin>>ch;
		for(j=1;j<=m;j=j+1)
			if(ch[j-1]=='#')
				a[i][n+j]=1,a[n+j][i]=1;
	}
	for(i=1;i<=n+m;i=i+1){
		if(!vis[i]){
			s=0;
			dfs(i);
			for(j=1;j<=s;j=j+1)
				for(k=1;k<=s;k=k+1)
					if(b[j]<=n&&b[k]>n&&(!a[b[j]][b[k]])){
						cout<<"No";
						return 0;
					}
		}
	}
	cout<<"Yes";
	return 0;
}