#include<bits/stdc++.h>
#define D(...) fprintf(stderr,__VA_ARGS__)
//#define int long long
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
const int N=100005,INF=0X3F3F3F3F;
int T,n,a,b,len,dep[N];VI G[N],nd;bool vis[N],ban[N],ok;
int getdis(int k1,int k2,int k3){
	if(k1==k3){
		nd.PB(k1);
		ban[k1]=1;
		vis[k1]=1;
		return 1;
	}
	for(auto j:G[k1])if(j!=k2){
		int t=getdis(j,k1,k3);
		if(t!=-INF){
			nd.PB(k1);
			ban[k1]=1;
			vis[k1]=1;
			return t+1;
		}
	}
	return-INF;
}
struct data{
	PII mx1,mx2,mx3;
	void init(){
		mx1=mx2=mx3=MP(-INF,-INF);
	}
	void push(PII x){
		if(x>mx1)mx3=mx2,mx2=mx1,mx1=x;
		else if(x>mx2)mx3=mx2,mx2=x;
		else if(x>mx3)mx3=x;
	}
}num[N];
void dfs1(int k1,int k2){
	num[k1].init();
	bool yz=1;
	for(auto j:G[k1])if(j!=k2&&!ban[j]){
		dfs1(j,k1);
		num[k1].push(MP(num[j].mx1.fi+1,j));
		yz=0;
	}
	if(yz){
		num[k1].push(MP(1,k1));
	}
}
void dfs2(int k1,int k2,int k3){
	data tmp=num[k1];
	tmp.push(MP(k3,k2));
	if(tmp.mx3.fi>=len)ok=1;
	for(auto j:G[k1])if(j!=k2&&!ban[j]){
		dfs2(j,k1,max(k3+1,num[k1].mx1.se==j?num[k1].mx2.fi+1:num[k1].mx1.fi+1));
	}
}
void getdep(int k1,int k2){
	dep[k1]=0;
	for(auto j:G[k1])if(!vis[j]&&j!=k2){
		getdep(j,k1);
		dep[k1]=max(dep[k1],dep[j]+1);
	}
}
signed main(){
	rd(T);
	while(T--){
		rd(n),rd(a),rd(b);nd.clear();
		rep(i,1,n)G[i].clear(),vis[i]=0,ban[i]=0;
		rep(i,1,n-1){
			int k1,k2;rd(k1),rd(k2);
			G[k1].PB(k2),G[k2].PB(k1);
		}
		len=getdis(b,0,a);
//		for(auto j:nd)printf("|%d ",j);puts("");
//		getdep(a,0);
//		getdep(b,0);
//		rep(i,0,dep[a])ban[lsta=nd[i]]=0;
//		rep(i,0,dep[b])ban[lstb=nd[SZ(nd)-1-i]]=0;
		int lsta=a,lstb=b;
		int i=0,j=0,da=0,db=0;
		while(1){
			int dda=da,ddb=db;
			while(i<SZ(nd)&&i<=da){
				int k1=nd[i];
				ban[lsta=k1]=0;
				getdep(k1,0);
				db=max(db,dep[k1]-i);
				++i;
			}
			while(j<SZ(nd)&&j<=db){
				int k1=nd[SZ(nd)-1-j];
				ban[lstb=k1]=0;
				getdep(k1,0);
				da=max(da,dep[k1]-j);
				++j;
			}
			if(dda==da&&ddb==db)break;
		}
		ok=0;
		dfs1(lsta,0);
		dfs2(lsta,0,-INF);
		dfs1(lstb,0);
		dfs2(lstb,0,-INF);
		puts(ok?"YES":"NO");
	}
	return 0;
}