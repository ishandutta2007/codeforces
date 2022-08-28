//CF 830E
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
vector<int> v[111111];
int n,m,s[111111],vis[111111],b[111111];
int l,p[111111],f,ans[111111];
void print(){
	f=1;
	printf("YES\n");
	int i;
	for(i=1;i<n;i=i+1)
		printf("%d ",ans[i]);
	printf("%d\n",ans[n]);
}
void s4(int x){
	int i;
	ans[x]=2;
	for(i=0;i<4;i=i+1)
		ans[v[x][i]]=1;
	print();
}
void cyc(int x){
	int i;
	i=l;
	while(p[i]!=x){
		ans[p[i]]=1;
		i--;
	}
	ans[x]=1;
	print();
}
void s3s3(int x){
	int i,t;
	t=p[1];
	for(i=0;i<3;i=i+1)
		ans[v[t][i]]=1;
	t=x;
	for(i=0;i<3;i=i+1)
		ans[v[t][i]]=1;
	for(i=1;i<=l;i=i+1)
		ans[p[i]]=2;
	print();
}
void sv(int x,int y,int z){
	int i,t;
	t=y*z;
	for(i=1;i<=y;i=i+1){
		ans[x]=t;
		x=p[x];
		t-=z;
	}
}
void s3_222(int u,int x,int y,int z){
	ans[u]=3;
	sv(x,2,1);
	sv(y,2,1);
	sv(z,2,1);
	print();
}
void s3_133(int u,int x,int y,int z){
	ans[u]=4;
	sv(x,1,2);
	sv(y,3,1);
	sv(z,3,1);
	print();
}
void s3_125(int u,int x,int y,int z){
	ans[u]=6;
	sv(x,1,3);
	sv(y,2,2);
	sv(z,5,1);
	print();
}
void dfs1(int u,int fa)
{
	if(f)
		return;
	int i;
	vis[u]=1;
	b[u]=1;
	l++;
	p[l]=u;
	for(i=0;i<s[u];i=i+1){
		if(f)
			return;
		if(v[u][i]==fa)
			continue;
		if(b[v[u][i]]){
			cyc(v[u][i]);
			return;
		}
		dfs1(v[u][i],u);
	}
	p[l]=0;
	l--;
	b[u]=0;
}
void dfs2(int u,int fa)
{
	if(f)
		return;
	int i;
	vis[u]=1;
	l++;
	p[l]=u;
	if(l>1&&s[u]>=3){
		s3s3(u);
		return;
	}
	for(i=0;i<s[u];i=i+1){
		if(f)
			return;
		if(v[u][i]!=fa)
			dfs2(v[u][i],u);
	}
	p[l]=0;
	l--;
}
int dfs3(int u,int fa)
{
	int i,x;
	p[u]=0;
	x=0;
	for(i=0;i<s[u];i=i+1)
		if(v[u][i]!=fa){
			x=max(x,dfs3(v[u][i],u));
			p[u]=v[u][i];
		}
	return x+1;
}/**/
int main()
{
	int T,i,j,x,y,z;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(i=0;i<=n;i=i+1){
			v[i].clear();
			s[i]=0;
			vis[i]=0;
			p[i]=0;
			ans[i]=0;
			b[i]=0;
		}
		l=0;
		f=0;
		
		for(i=1;i<=m;i=i+1){
			scanf("%d%d",&x,&y);
			v[x].push_back(y);
			v[y].push_back(x);
			s[x]++;
			s[y]++;
		}
		
		for(i=1;i<=n&&!f;i=i+1)
			if(s[i]>=4)
				s4(i);
		if(f)
			continue;
		
		for(i=1;i<=n&&!f;i=i+1){
			if(!vis[i])
				dfs1(i,0);
		}
		if(f)
			continue;
		
		for(i=0;i<=n;i=i+1){
			vis[i]=0;
			p[i]=0;
			b[i]=0;
		}
		l=0;
		
		for(i=1;i<=n&&!f;i=i+1){
			if(!vis[i]&&s[i]>=3)
				dfs2(i,0);
		}
		if(f)
			continue;
		
		for(i=0;i<=n;i=i+1){
			vis[i]=0;
			p[i]=0;
			b[i]=0;
		}
		l=0;
		
		for(i=1;i<=n&&!f;i=i+1){
			if(s[i]>=3){
				x=dfs3(v[i][0],i);
				y=dfs3(v[i][1],i);
				z=dfs3(v[i][2],i);
				if(x>y){
					swap(v[i][0],v[i][1]);
					swap(x,y);
				}
				if(y>z){
					swap(v[i][1],v[i][2]);
					swap(y,z);
				}
				if(x>y){
					swap(v[i][0],v[i][1]);
					swap(x,y);
				}
				//cout<<x<<y<<z<<endl;
				//cout<<v[i][0]<<v[i][1]<<v[i][2]<<endl;
				if(x>=2)
					s3_222(i,v[i][0],v[i][1],v[i][2]);
				else{
					if(y>=3)
						s3_133(i,v[i][0],v[i][1],v[i][2]);
					if(y==2&&z>=5)
						s3_125(i,v[i][0],v[i][1],v[i][2]);
				}/**/
			}
		}
		if(f)
			continue;
		
		printf("NO\n");
	}
	return 0;
}
/*
1
10 8
1 2
2 3
3 4
4 5
5 6
1 7
7 8
1 9
*/