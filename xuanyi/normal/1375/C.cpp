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
const int N=300005;
int T,n,a[N];
signed main(){
	rd(T);
	while(T--){
		rd(n);{
			VI b;
			rep(i,1,n){
				rd(a[i]);
				if(b.empty()||b.back()>a[i]){
					b.PB(a[i]);
				}else{
					if(SZ(b)==1){
						continue;
					}else{
						int lst=-1;
						while(SZ(b)>1&&b.back()<a[i])lst=b.back(),b.pop_back();
						if(b.back()>=a[i])b.PB(lst);
					}
				}
			}
			puts(SZ(b)==1?"YES":"NO");
		}
	}
	return 0;
}