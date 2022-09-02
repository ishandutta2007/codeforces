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
const int N=30005;
int T,n,a[N],id[N],top,ans[N][3];
bool vis[N];
void push(int k1,int k2,int k3){
	if(k3)ans[++top][0]=k1,ans[top][1]=k2,ans[top][2]=k3;
}
signed main(){
	rd(T);
	while(T--){
		rd(n);
		int sum=0;
		rep(i,1,n)rd(a[i]),sum+=a[i];
		if(sum%n!=0){
			puts("-1");
			continue;
		}
		int mid=sum/n;
		top=0;
		rep(i,2,n){
			int x=(a[i]+i-1)/i*i-a[i];
			a[1]-=x,a[i]+=x;
			push(1,i,x);
			x=a[i]/i;
			a[i]-=i*x,a[1]+=i*x;
			push(i,1,x);
		}
		rep(i,2,n){
			a[1]-=mid,a[i]+=mid;
			push(1,i,mid);
		}
		rep(i,1,n)assert(a[i]==mid);
		pt(top,'\n');
		rep(i,1,top){
			pt(ans[i][0],' ');
			pt(ans[i][1],' ');
			pt(ans[i][2],'\n');
		}
	}
	return 0;
}