#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
#define NDEBUG
#endif
#include<bits/stdc++.h>
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
const int N=55;
int T,n,a[N];
signed main(){
	rd(T);
	while(T--){
		rd(n);
		vector<int>A,B;
		int s1=0,s2=0,zero=0;
		rep(i,1,n){
			rd(a[i]);
			if(a[i]>0)A.PB(a[i]),s1+=a[i];
			else if(a[i]<0)B.PB(a[i]),s2+=a[i];
			else ++zero;
		}
		if(s1+s2!=0){
			puts("Yes");
			if(s1+s2>0){
				rep(i,0,SZ(A)-1)printf("%lld ",A[i]);
				rep(i,0,SZ(B)-1)printf("%lld ",B[i]);
			}else{
				rep(i,0,SZ(B)-1)printf("%lld ",B[i]);
				rep(i,0,SZ(A)-1)printf("%lld ",A[i]);
			}
			while(zero--)printf("0 ");
			puts("");
		}else{
			puts("No");
		}
	}
	return 0;
}