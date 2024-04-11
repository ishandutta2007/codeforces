//CF1654D
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
const int N = 222222;
const int MO = 998244353;
int gcd(int x,int y){
	if(!y)
		return x;
	return gcd(y,x%y);
}
void ad(int&x,int y){
	x+=y;
	if(x>=MO)
		x-=MO;
}
int mul(int x,int y){
	return (LL)x*y%MO;
}
int fpow(int x,int y=MO-2){
	int z=1;
	while(y){
		if(y&1)
			z=mul(z,x);
		x=mul(x,x);
		y>>=1;
	}
	return z;
}
int n,a[N],b[N],c[N];
vector<int> v[N],h[N];
void ins(int x){//cout<<"I"<<x<<endl;
	for(int i=2;i*i<=x;i++){
		while(x%i==0){
			b[i]++;
			x/=i;
		}
	}
	if(x>1)
		b[x]++;
}
void del(int x){//cout<<"D"<<x<<endl;
	for(int i=2;i*i<=x;i++){
		while(x%i==0){
			b[i]--;
			x/=i;
			c[i]=min(c[i],b[i]);
		}
	}
	if(x>1){
		b[x]--;
		c[x]=min(c[x],b[x]);
	}
}
void dfs(int u,int fa){
	int i,x;
	for(i=0;i<v[u].size();i++)
		if(v[u][i]==fa)
			a[u]=mul(a[u],fpow(h[u][i])),ins(h[u][i]);
	for(i=0;i<v[u].size();i++){
		x=v[u][i];
		if(x!=fa){
			a[x]=mul(a[u],h[u][i]);
			dfs(x,u);
		}
	}
}
void dfs2(int u,int fa){
	int i,x,o;
	for(i=0;i<v[u].size();i++)
		if(v[u][i]==fa)
			o=h[u][i];
	if(u!=1)
		del(o);
	for(i=0;i<v[u].size();i++){
		x=v[u][i];
		if(x!=fa){
			ins(h[u][i]);
			dfs2(x,u);
			del(h[u][i]);
		}
	}
	if(u!=1)
		ins(o);
}
int main()
{
	int T,i,x,y,z,w,g;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(i=1;i<n;i++){
			scanf("%d%d%d%d",&x,&y,&z,&w);
			v[x].push_back(y);
			h[x].push_back(w);
			v[y].push_back(x);
			h[y].push_back(z);
		}
		a[1]=1;
		dfs(1,0);
		x=0;
		for(i=1;i<=n;i++)
			ad(x,a[i]);//,cout<<mul(a[i],32);
		for(i=1;i<=n;i++)
			c[i]=b[i];
		dfs2(1,0);
		y=1;
		for(i=2;i<=n;i++){
			y=mul(y,fpow(i,b[i]-c[i]));
		}//cout<<y<<endl;
		printf("%d\n",mul(x,y));
		for(i=1;i<=n;i++)
			v[i].clear(),h[i].clear();
	}
	return 0;
}