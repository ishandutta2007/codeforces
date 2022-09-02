#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define int long long
#define LL long long
#define MP make_pair
#define PB push_back
#define EB emplace_back
#define X first
#define Y second
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
typedef pair<int,int>PII;
typedef vector<int>VI;
typedef vector<PII>VII;
template<typename T>void umin(T&x,const T&y){if(y<x)x=y;}
template<typename T>void umax(T&x,const T&y){if(x<y)x=y;}
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int N=200005;
int n,m,deg[N];
bool vis[N];
bool ban[N],pd[N];
vector<int>G[N],H[N];
char s[N];
void sol(int k1){
	if(ban[k1])return;
	ban[k1]=1;
	for(auto x:H[k1]){
		sol(x);
	}
	H[k1].clear();
}
void sol2(int k1){
	if(pd[k1])return;
	pd[k1]=1;
	for(auto x:G[k1]){
		sol2(x);
	}
	G[k1].clear();
}
signed main(){
	rd(n),rd(m);
	rep(i,1,m){
		int k1,k2;
		rd(k1),rd(k2);
		G[k1].PB(k2);
		++deg[k2];
		H[k2].PB(k1);
	}
	queue<int>q;
	rep(i,1,n)if(deg[i]==0)q.push(i);
	while(SZ(q)){
		int k1=q.front();
		vis[k1]=1;
		q.pop();
		for(auto x:G[k1])if(!--deg[x]){
			q.push(x);
		}
	}
	rep(i,1,n)if(!vis[i])puts("-1"),exit(0);
	int ans=0;
	rep(i,1,n){
		if(!ban[i]&&!pd[i]){
			s[i]='A';
			++ans;
		}else s[i]='E';
		sol(i);
		sol2(i);
	}
	pt(ans,'\n');
	puts(s+1);
	return 0;
}