// author: xay5421
// created: Tue Nov  9 16:11:04 2021
#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
#define DEBUG 0
using namespace std;
const int N=1005;
int n,dep[N],fa[N];
char s[N];
#if DEBUG
int g[N][N];
vector<int>ask(vector<int>v){
	vector<int>res(n);
	rep(i,0,n-1){
		rep(j,0,n-1){
			if(g[i+1][j+1]<=v[i]){
				res[j]=1;
			}
		}
	}
	return res;
}
#else
vector<int>ask(vector<int>v){
	printf("? ");
	rep(i,0,n-1)printf("%d ",v[i]);
	puts("");
	fflush(stdout);
	vector<int>res(n);
	scanf("%s",s);
	rep(i,0,n-1)res[i]=s[i]-'0';
	return res;
}
#endif
vector<int>vs[N];
int main(){
	scanf("%d",&n);
#if DEBUG
	memset(g,63,sizeof(g));
	rep(i,2,n){
		int k1,k2;
		scanf("%d%d",&k1,&k2);
		g[k1][k2]=g[k2][k1]=1;
	}
	rep(k,1,n)rep(i,1,n)if(i!=k)rep(j,1,n)if(j!=k&&j!=i)g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
#endif
	int logn=0;
	while((1<<logn)<n)++logn;
	int cur=0;
	vector<vector<int> >all(1,vector<int>{});
	rep(i,0,n-1)all[0].pb(i);
	vs[0].pb(0);
	per(i,logn-1,0){
		vector<vector<int> >nall0;
		vector<vector<int> >nall1;
		{
			cur=0;
			vector<int>qs(n);
			for(int j=0;j<n;j+=1<<(i+1)){
				if(++cur&1){
					for(auto x:vs[j]){
						qs[x]=1<<i;
					}
				}
			}
			vector<int>res1=ask(qs);
			for(auto&x:qs)if(x)--x;
			vector<int>res2=ask(qs);
			for(int j=0;j<SZ(all);j+=2){
				vector<int>f0,f1;
				for(auto x:all[j]){
					if(res1[x]!=res2[x]){
						dep[x]=(j<<(i+1))+(1<<i);
						vs[dep[x]].pb(x);
					}else if(res1[x]){
						f0.pb(x);
					}else{
						f1.pb(x);
					}
				}
				nall0.pb(f0),nall0.pb(f1);
			}
		}
		{
			cur=0;
			vector<int>qs(n);
			for(int j=0;j<n;j+=1<<(i+1)){
				if((cur++)&1){
					for(auto x:vs[j]){
						qs[x]=1<<i;
					}
				}
			}
			vector<int>res1=ask(qs);
			for(auto&x:qs)if(x)--x;
			vector<int>res2=ask(qs);
			for(int j=1;j<SZ(all);j+=2){
				vector<int>f0,f1;
				for(auto x:all[j]){
					if(res1[x]!=res2[x]){
						dep[x]=(j<<(i+1))+(1<<i);
						vs[dep[x]].pb(x);
					}else if(res1[x]){
						f0.pb(x);
					}else{
						f1.pb(x);
					}
				}
				nall1.pb(f0),nall1.pb(f1);
			}
		}
		all.clear();
#define i ii
		int i=0,j=0;
		while(i<SZ(nall0)||j<SZ(nall1)){
			if(i<SZ(nall0)){
				all.pb(nall0[i++]);
			}
			if(i<SZ(nall0)){
				all.pb(nall0[i++]);
			}
			if(j<SZ(nall1)){
				all.pb(nall1[j++]);
			}
			if(j<SZ(nall1)){
				all.pb(nall1[j++]);
			}
		}
#undef i
	}
	rep(rem,0,2){
		rep(bit,0,logn-1){
			vector<int>qs(n);
			for(int i=rem;i<n;i+=3){
				for(auto x:vs[i])if(x>>bit&1){
					qs[x]=1;
				}
			}
			vector<int>res=ask(qs);
			for(int i=(rem+1)%3;i<n;i+=3){
				for(auto x:vs[i])if(res[x]){
					fa[x]|=1<<bit;
				}
			}
		}
	}
	printf("!\n");
	rep(i,1,n-1)printf("%d %d\n",fa[i]+1,i+1);
	fflush(stdout);
	return 0;
}