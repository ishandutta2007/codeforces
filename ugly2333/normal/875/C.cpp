//CF 875C
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
const int N = 111111;
vector<int> a[N];
vector<int> v[N];
int ans[N],vis[N],s[N],ss;
void dfs(int u){
	vis[u]=1;
	int i,s,x;
	s=v[u].size();
	for(i=0;i<s;i=i+1){
		x=v[u][i];
		if(ans[x]==2){
			cout<<"No\n";
			exit(0);
		}
		ans[x]=1;
		if(!vis[x])
			dfs(x);
	}
}
int main()
{
	int n,m,i,j,l,x,y,t;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i=i+1){
		t=0;
		scanf("%d",&l);
		a[i].push_back(l);
		for(j=1;j<=l;j=j+1){
			scanf("%d",&x);
			a[i].push_back(x);
			if(i==1||j>a[i-1][0])
				continue;
			y=a[i-1][j];
			if(!t&&x!=y){
				v[x].push_back(y);
				t=j;
				if(x<y){
					if(ans[x]==1||ans[y]==2){
						cout<<"No\n";
						return 0;
					}
					ans[x]=2;
					ans[y]=1;
				}
			}
		}
		if(i>1&&!t&&a[i-1][0]>a[i][0]){
			cout<<"No\n";
			return 0;
		}
			
	}
	for(i=1;i<=m;i=i+1){
		if(ans[i]==1&&!vis[i])
			dfs(i);
	}
	for(i=1;i<=m;i=i+1){
		if(ans[i]==1)
			s[++ss]=i;
	}
	cout<<"Yes\n"<<ss<<endl;
	for(i=1;i<=ss;i=i+1)
		cout<<s[i]<<' ';
	return 0;
}
/*
2 2
2 2 1
1 2
*/