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
const int N=1005;
int n,m,ret,a[N],b[N];
void qry(const VI&v){
	printf("%d ",SZ(v));
	for(auto&x:v)printf("%d ",x);
	printf("\n");
	fflush(stdout);
	scanf("%d",&ret);
}
signed main(){
	scanf("%d",&n);
	int x=2,mx=0;
	rep(i,1,n-2){
		if(n/i*(i-1)+n%i-(n%i!=0)-i+1>mx){
			x=i,mx=n/i*(i-1)+n%i-(n%i!=0)-i+1;
		}
	}
	while(1){
		int cnt=0;
		rep(i,1,n)if(a[i])++cnt;
		if(cnt>=mx)break;
		VI v;
		rep(i,1,n-1)if(i%x!=0&&!a[i])a[i]=1,v.PB(i);
		if(SZ(v)==0)break;
		qry(v);
		rep(i,ret,ret+SZ(v)-1)a[(i-1)%n+1]=0;
	}
	puts("0");
	return 0;
}