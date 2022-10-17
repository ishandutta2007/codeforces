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
int T,d,m;
signed main(){
	rd(T);
	while(T--){
		rd(d),rd(m);
		int pos=-1;
		per(i,30,0)if(d>>i&1){pos=i;break;}
		int ans=1;
		rep(i,0,pos-1){
			ans=1LL*ans*((1LL<<i)+1)%m;
		}
		ans=1LL*ans*(d-(1LL<<pos)+1+1)%m;
		pt((ans+m-1)%m,'\n');
	}
	return 0;
}