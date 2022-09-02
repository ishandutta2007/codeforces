#include<bits/stdc++.h>
#define int long long
#define LL long long
#define MP make_pair
#define PB push_back
#define ALL(x) (x).begin(),(x).end()
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
typedef pair<int,int>pii;typedef vector<int>VI;typedef vector<pii>VP;
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int N=200005;
int n,mx,a[N],b[N];
signed main(){
	rd(n);
	rep(i,1,n)rd(b[i]);
	rep(i,1,n){
		a[i]=b[i]+mx;
		mx=max(mx,a[i]);
	}
	rep(i,1,n)pt(a[i],' ');
	return 0;
}