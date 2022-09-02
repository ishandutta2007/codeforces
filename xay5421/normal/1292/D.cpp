#include<bits/stdc++.h>
#define int long long
using namespace std;
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int N=1000005;
typedef pair<int,int> pii;
int n,len,tot=1,a[5005],p[5005],b[N],val[N],f[N],sz[N];bool ban[5005];vector<pii>G[N];
void pre(){
	ban[0]=ban[1]=1;
	for(int i=2;i<=5000;++i){
		if(!ban[i])p[++*p]=i;
		for(int j=1;j<=*p&&i*p[j]<=5000;++j){
			ban[i*p[j]]=1;
			if(i%p[j]==0)break; 
		}
	}
}
int count(int a,int b){
	int res=0;
	while(a){
		res+=a/b;
		a/=b;
	}
	return res;
}
int sol(int l,int now){
	int res=0;
	for(int i=now;i>=1;--i)res+=count(l,p[i]);
	return res;
}
void cut(int now,int l,int r,int fa){
	if(l==r){G[fa].push_back(make_pair(l,sol(b[l],now)));/*,fprintf(stderr,"%d %d %d\n",fa,l,sol(b[l],now));*/return;}
	if(now<1)return;
	if(count(b[r],p[now])==0){
		cut(now-1,l,r,fa);
		return;
	}
	int nowfa=fa,lst=0;
	for(int i=l;i<=r;){
		int j=i+1;
		while(j<=r&&count(b[i],p[now])==count(b[j],p[now]))++j;
		++tot;
		G[nowfa].push_back(make_pair(tot,count(b[i],p[now])-lst));
//		fprintf(stderr,"%d %d %d\n",tot,count(b[i],p[now])-lst);
		nowfa=tot;
		lst=count(b[i],p[now]);
		cut(now-1,i,j-1,tot);
		i=j;
	}
}
void dfs(int k1,int k2){
	sz[k1]=val[k1],f[k1]=0;
	for(auto j:G[k1])if(j.first!=k2){
		dfs(j.first,k1);
		sz[k1]+=sz[j.first];
		f[k1]+=f[j.first]+j.second*sz[j.first];
	}
}
void dfs2(int k1,int k2){
	for(auto j:G[k1])if(j.first!=k2){
		f[j.first]=f[k1]-j.second*sz[j.first]+j.second*(n-sz[j.first]);
		dfs2(j.first,k1);
	}
}
signed main(){
	pre();
	rd(n);
	for(int i=1;i<=n;++i){
		int x;rd(x);if(x==0)++x;++a[x];
	}
	for(int i=0;i<=5000;++i){
		if(a[i]>0)b[++len]=i,val[len]=a[i];
	}
	tot=len+1;
	cut(*p,1,len,tot);
	dfs(len+1,0);
	dfs2(len+1,0);
	int ans=0x3f3f3f3f3f3f3f3fll;
	for(int i=1;i<=tot;++i)ans=min(ans,f[i]);
	pt(ans,'\n');
	return 0;
}