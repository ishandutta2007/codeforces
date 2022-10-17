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
typedef pair<int,int>pii;typedef vector<int>VI;typedef vector<pii>VP;
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int N=100005;
int n,m,l[N],sum[N],ans[N];
signed main(){
	rd(n),rd(m);
	rep(i,1,m)rd(l[i]);
	per(i,m,1)sum[i]=sum[i+1]+l[i];
	if(sum[1]<n||m-1+l[m]>n){
		puts("-1");
		return 0;
	}
	int now=n;
	rep(i,1,m){
		if(now-l[i]+1<1){
			puts("-1");
			return 0;
		}
		ans[++*ans]=now-l[i]+1;
		if(sum[i+1]>=now-1){
			--now;
		}else now=sum[i+1];
	}
	rep(i,1,*ans)pt(ans[i],' ');
	return 0;
}