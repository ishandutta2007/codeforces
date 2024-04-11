#include<bits/stdc++.h>
#define D(...) fprintf(stderr,__VA_ARGS__)
#define int long long
#define LL long long
#define MP make_pair
#define PB push_back
#define fi first
#define se second
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
typedef pair<int,int>PII;typedef vector<int>VI;typedef vector<PII>VII;
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int N=200005;
int n,a[N],h[N],f[N][2];
int pp,lnk[N],nxt[N*2],to[N*2];
int ans=0X3F3F3F3F3F3F3F3FLL;
void ae(int k1,int k2){to[++pp]=k2,nxt[pp]=lnk[k1],lnk[k1]=pp;}
int get(int k1,int k2){
	int res=min(k1,k2);
	k1-=res,k2-=res;
	return res+k1+k2;
}
void dfs(int k1,int k2){
	int cnt[3]={0,0,0};
	int sum[3]={0,0,0};
	VII cur;
	for(int i=lnk[k1];i;i=nxt[i])if(to[i]!=k2){
		dfs(to[i],k1);
		if(h[k1]==h[to[i]]){
			cur.PB({f[to[i]][0],f[to[i]][1]});
		}
		else if(h[k1]<h[to[i]]){
			sum[0]+=f[to[i]][0],++cnt[0];
		}else{
			sum[1]+=f[to[i]][1],++cnt[1];
		}
	}
	sort(ALL(cur),[&](PII k1,PII k2){return k1.fi-k1.se<k2.fi-k2.se;});
	int now=0;
	for(auto x:cur)now+=x.se;
	int tmp=0X3F3F3F3F3F3F3F3FLL;
	rep(i,0,SZ(cur)){
		if(cnt[0]+i>0)f[k1][0]=min(f[k1][0],sum[0]+sum[1]+now+a[k1]*get(cnt[0]+i-1,cnt[1]+SZ(cur)-i));
		if(cnt[1]+SZ(cur)-i>0)f[k1][1]=min(f[k1][1],sum[0]+sum[1]+now+a[k1]*get(cnt[0]+i,cnt[1]+SZ(cur)-i-1));
		tmp=min(tmp,sum[0]+sum[1]+now+a[k1]*get(cnt[0]+i,cnt[1]+SZ(cur)-i));
		if(i<SZ(cur))now+=cur[i].fi,now-=cur[i].se;
	}
	if(k1==1)ans=min(ans,tmp);
	f[k1][0]=min(f[k1][0],tmp);
	f[k1][1]=min(f[k1][1],tmp);
	f[k1][0]+=a[k1];
	f[k1][1]+=a[k1];
}
signed main(){
	memset(f,63,sizeof(f));
	rd(n);
	rep(i,1,n)rd(a[i]);
	rep(i,1,n)rd(h[i]);
	rep(i,1,n-1){
		int k1,k2;rd(k1),rd(k2);
		ae(k1,k2),ae(k2,k1);
	}
	dfs(1,0);
//	rep(i,1,n){
//		D("f[%lld]={%lld,%lld}\n",i,f[i][0],f[i][1]);
//	}
	ans=min({ans,f[1][0],f[1][1]});
	pt(ans,'\n');
	return 0;
}