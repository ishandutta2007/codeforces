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
typedef pair<int,int>PII;typedef vector<int>VI;typedef vector<PII>VII;
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int N=100005;
int n,a[N],b[N],bin[N],tot;
signed main(){
	rep(i,1,6)rd(a[i]);
	rd(n);
	vector<pair<int,int> >v;
	rep(i,1,n){
		rd(b[i]);
		rep(j,1,6)v.EB(b[i]-a[j],i);
	}
	sort(v.begin(),v.end());
	int j=0;
	int ans=1e18;
	rep(i,0,SZ(v)-1){
		while(tot<n&&j<SZ(v)){
			if(++bin[v[j].Y]==1){
				++tot;
			}
			++j;
		}
		if(tot==n&&i<j){
			ans=min(ans,v[j-1].X-v[i].X);
		}
		if(--bin[v[i].Y]==0){
			--tot;
		}
	}
	pt(ans,'\n');
	return 0;
}