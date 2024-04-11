#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int in(){
	int x;
	scanf("%d",&x);
	return x;
}
const int N=1e6+5;
int n,m;
vector<int> e[N];
int h[N],hf[N];
void dfs1(int x,int fa){
	for(int y:e[x]){
		if(y==fa)continue;
		dfs1(y,x);
		h[x]=max(h[x],h[y]);
	}
	h[x]+=1;
}
void dfs2(int x,int fa){
	int mx1=hf[x],mx2=0;
	for(int y:e[x]){
		if(y==fa)continue;
		if(h[y]>mx1)mx2=mx1,mx1=h[y];
		else mx2=max(mx2,h[y]);
	}
	for(int y:e[x]){
		if(y==fa)continue;
		if(h[y]==mx1)hf[y]=mx2+1;
		else hf[y]=mx1+1;
		dfs2(y,x);
	}
}
int c1[N],c2[N];
void add1(int p,int v){
	if(p>1)c1[p]=max(c1[p],v);	
}
void add2(int p,int v){
	if(p>1)c2[p]=max(c2[p],v);
}
int c3[N];
void add3(int p,int v){
	for(int i=p;i>=1;i-=i&-i)c3[i]=max(c3[i],v);	
}
int get3(int p){
	int s=0;
	for(int i=p;i<=m;i+=i&-i)s=max(s,c3[i]);
	return s;	
}
void clear(int p){
	for(int i=p;i>=1;i-=i&-i)c3[i]=0;	
}
vector<int> v1;
void solve(int x,int fa){
	vector<int> v;
	for(int y:e[x]){
		if(y==fa)continue;
		v.push_back(h[y]);
	}
	v.push_back(hf[x]);
	sort(v.begin(),v.end());
	int sz=v.size();
	for(int i=0;i<sz;i++){
		add3(v[i]*2,sz-i);
		v1.push_back(v[i]<<1); 
	}
}
void dfs3(int x,int fa){
	vector<int> v;
	v.push_back(hf[x]);
	for(int y:e[x]){
		if(y==fa)continue;
		v.push_back(h[y]);
	}
	sort(v.begin(),v.end());
	int sz=v.size();
	for(int i=0;i+1<sz;i++){
		add1(v[i]*2-1,sz-i);
		if(v[i+1]>v[i])add1(v[i]*2+1,sz-i);
		add2(v[i]*2,sz-i);
	}
	for(int y:e[x]){
		if(y==fa)continue;
		solve(y,x);	
	}
	for(int x:v)v1.push_back(x<<1);
	sort(v1.begin(),v1.end());
	int p=0; 
	for(int i:v1){
		if(i==0)continue;
		for(;p<sz&&v[p]<i>>1;p++);
		add2(i,get3(i)+sz-p-2);
	}
	for(int x:v1)clear(x);
	v1.clear();
	for(int y:e[x])
		if(y!=fa)dfs3(y,x); 
}
int main(){
	n=in(),m=n<<1;
	for(int i=1;i<n;i++){
		int x=in(),y=in();
		e[x].push_back(y);
		e[y].push_back(x);	
	}
	dfs1(1,0);
	dfs2(1,0);
	dfs3(1,0);
	int ans1=0;
	for(int i=1;i<=n;i++)ans1=max(ans1,1+(int)e[i].size());
	printf("%d ",ans1);
	for(int i=m;i>=1;i--){
		c1[i]=max(c1[i],c1[i+1]);
		c2[i]=max(c2[i],c2[i+1]);	
	}
	for(int i=2;i<=n;i++){
		int ans=i&1?c1[i]:c2[i];
		printf("%d ",max(ans,1));	
	}
	return 0;
}