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
const int N=100005;
int T,n,l,a[N];
double t1[N],t2[N];
signed main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	rd(T);
	while(T--){
		rd(n),rd(l);
		rep(i,1,n)rd(a[i]);
		a[n+1]=l;
		a[0]=0;
		t1[0]=0;
		rep(i,1,n+1){
			t1[i]=t1[i-1]+1.*(a[i]-a[i-1])/i;
		}
		t2[n+1]=0;
		per(i,n,0){
			t2[i]=t2[i+1]+1.*(a[i+1]-a[i])/(n-i+1);
		}
		double ans=1e100;
		rep(i,0,n){
			if(t1[i]<t2[i]&&t1[i+1]>=t2[i+1]){
				double t=min(t1[i],t2[i+1]);
				double v1=i+1;
				double v2=n-i+1;
				double p1=a[i]+v1*(t-t1[i]);
				double p2=a[i+1]-v2*(t-t2[i+1]);
				double len=p2-p1;
				ans=t+len/(v1+v2);
				break;
			}
		}
		printf("%.20f\n",ans);
	}
	return 0;
}