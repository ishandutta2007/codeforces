#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
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
const int N=200005;
int n;
signed main(){
	rd(n);
	pt(n*3+4,'\n');
	printf("%d %d\n",0,0);
	rep(i,1,n+1)printf("%d %d\n%d %d\n%d %d\n",i-1,i,i,i,i,i-1);
	return 0;
}