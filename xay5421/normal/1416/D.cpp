#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
#define NDEBUG
#endif
#include<bits/stdc++.h>
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
const int N=300005;
int n,m,Q,p[N],hav[N],u[N],v[N],fa[N];
set<int>S[N];
int pp,lnk[N],nxt[N*2],to[N*2];
void ae(int k1,int k2){to[++pp]=k2,nxt[pp]=lnk[k1],lnk[k1]=pp;}
struct data{
	int o,x;
}q[500005];
int fd(int k1){return fa[k1]==k1?k1:fd(fa[k1]);}
void mer(int k1,int k2){
	k1=fd(k1),k2=fd(k2);
	if(k1!=k2){
		if(SZ(S[k1])<SZ(S[k2]))swap(k1,k2);
		for(auto x:S[k2])S[k1].insert(x);
		S[k2].clear();
		fa[k2]=k1;
	}
}
vector<int>md[500005];
void mer2(int k1,int k2,int t){
	k1=fd(k1),k2=fd(k2);
	if(k1!=k2){
		if(SZ(S[k1])<SZ(S[k2]))swap(k1,k2);
		for(auto x:S[k2])S[k1].insert(x);
		vector<int>&cur=md[t];
		cur.PB(k2);
		cur.PB(k1);
		for(auto x:S[k2])cur.PB(x);
		S[k2].clear();
		fa[k2]=k1;
	}
}
signed main(){
	rd(n),rd(m),rd(Q);
	rep(i,1,n)rd(p[i]),fa[i]=i,S[i].insert(p[i]);
	rep(i,1,m){
		int k1,k2;
		rd(k1),rd(k2);
		u[i]=k1,v[i]=k2;
		hav[i]=1;
	}
	rep(i,1,Q){
		rd(q[i].o),rd(q[i].x);
		if(q[i].o==2)hav[q[i].x]=0;
	}
	rep(i,1,m){
		if(hav[i])mer(u[i],v[i]);
	}
	per(i,Q,1){
		if(q[i].o==2){
			mer2(u[q[i].x],v[q[i].x],i);
		}
	}
	rep(_,1,Q){
		if(q[_].o==1){
			int k1=fd(q[_].x);
			if(SZ(S[k1])==0){
				puts("0");
			}else{
				pt(*--S[k1].end(),'\n');
				S[k1].erase(--S[k1].end());
			}
		}else{
			if(SZ(md[_])){
				vector<int>&cur=md[_];
				fa[cur[0]]=cur[0];
				for(int i=2;i<SZ(cur);++i){
					if(S[cur[1]].count(cur[i])){
						S[cur[1]].erase(cur[i]);
						S[cur[0]].insert(cur[i]);
					}
				}
			}
		}
	}
	return 0;
}