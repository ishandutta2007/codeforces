//CF 842C
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
const int N = 222222;
int gcd(int x,int y){
	int r;
	if(x<y)
		swap(x,y);
	if(!y)
		return x;
	while(x%y){
		r=x%y;
		x=y;
		y=r;
	}
	return y;
}
int a[N],ans[N],b[N],j;
vector<int> v[N];
void dfs1(int u,int fa){
	int i,s,t;
	s=v[u].size();
	for(i=0;i<s;i=i+1){
		t=v[u][i];
		if(t!=fa){
			ans[t]=gcd(a[t],ans[u]);
			dfs1(t,u);
		}
	}
}
void dfs2(int u,int fa){
	int i,s,t;
	s=v[u].size();
	if(b[u]<2){
		if(ans[u]<j)
			ans[u]=j;
	}
	else
		return;
	for(i=0;i<s;i=i+1){
		t=v[u][i];
		if(t!=fa){
			b[t]+=b[u];
			dfs2(t,u);
		}
	}
}
int main()
{
	int n,i,x,y,t;
	scanf("%d",&n);
	for(i=1;i<=n;i=i+1)
		scanf("%d",a+i);
	for(i=1;i<n;i=i+1){
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	t=a[1];
	a[1]=0;
	ans[1]=0;
	dfs1(1,0);
	a[1]=t;
	ans[1]=t;
	for(j=1;j<=t;j=j+1){
		if(t%j)
			continue;
		for(i=1;i<=n;i=i+1){
			if(a[i]%j)
				b[i]=1;
			else
				b[i]=0;
		}
		dfs2(1,0);
		//for(i=1;i<=n;i=i+1)
		//	if(b[i]<2&&ans[i]<j)
		//		ans[i]=j;
	}
	ans[1]=t;
	for(i=1;i<=n;i=i+1)
		printf("%d ",ans[i]);
	printf("\n");
	return 0;
}
/*
4
6 10 15 1
1 2
2 3
3 4

6 10 5 1
*/