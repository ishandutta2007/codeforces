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
const int N=100005;
int T,n,a,b,da,db,dep[N];
vector<int>G[N];
void dfs(int k1,int k2){
	for(auto j:G[k1])if(j!=k2)dep[j]=dep[k1]+1,dfs(j,k1);
}
bool sol(){
	if(da>=db)return 1;
	if(db<=da*2)return 1;
	dep[a]=0,dfs(a,0);
	if(dep[b]<=da)return 1;
	int rt1=max_element(dep+1,dep+1+n)-dep;
	dep[rt1]=0,dfs(rt1,0);
	int rt2=max_element(dep+1,dep+1+n)-dep;
	int d=dep[rt2];
	if(d<=da*2){
		return 1;
	}
	return 0;
}
signed main(){
	rd(T);
	while(T--){
		rd(n),rd(a),rd(b),rd(da),rd(db);
		rep(i,1,n)G[i].clear();
		rep(i,1,n-1){
			int k1,k2;rd(k1),rd(k2);
			G[k1].PB(k2),G[k2].PB(k1);
		}
		puts(sol()?"Alice":"Bob");
	}
	return 0;
}