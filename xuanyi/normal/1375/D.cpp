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
const int N=1005;
int T,n,a[N];bool vis[N];
int Mex(){
	rep(i,0,n-1){
		vis[a[i]]=1;
	}
	int res=0;while(vis[res])++res;
	rep(i,0,n-1){
		vis[a[i]]=0;
	}
	return res;
}
signed main(){
	rd(T);
	while(T--){
		rd(n);
		rep(i,0,n-1)rd(a[i]);
		VI ans;
		rep(i,1,n*2){
			bool flg=1;
			rep(i,0,n-2)if(a[i]>a[i+1])flg=0;
			if(flg)break;
			int num=Mex();
			if(num==n){
				rep(i,0,n-1)if(a[i]!=i){
					rep(j,0,n-1)if(a[j]==i){
//						D("fuck\n");
						ans.PB(j),a[j]=num;
						goto qaq;
					}
					assert(0);
				}
			}else{
				ans.PB(num);
				a[num]=num;
			}
			qaq:;
		}
		pt(SZ(ans),'\n');
		for(auto x:ans)pt(x+1,' ');puts("");
	}
	return 0;
}