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
int n,a[N];
signed main(){
	rd(n);
	rep(i,1,n)rd(a[i]);
	if(n==1){
		puts("1 1");
		puts("0");
		puts("1 1");
		puts("0");
		puts("1 1");
		pt(-a[1],'\n');
		return 0;
	}
	printf("%lld %lld\n",1LL,n-1);
	rep(i,1,n-1){
		int x=a[i]/n;
		if(x*n>a[i])--x;
		int num=a[i]-x*n;
		assert(num>=0);
		int k=(n-1)*num;
		a[i]+=k;
		assert(a[i]%n==0);
		pt((n-1)*num,i==n-1?'\n':' ');
	}
	printf("%lld %lld\n",n,n);
	pt(-a[n],'\n'),a[n]=0;
	printf("%lld %lld\n",1LL,n);
	rep(i,1,n){
		pt(-a[i],i==n?'\n':' ');
	}
	return 0;
}