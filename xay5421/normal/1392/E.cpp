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
const int N=55;
int n,a[N][N];
signed main(){
	cin>>n;
	int tt=0;
	per(j,n,1)if(~j&1){
		per(i,n,1)a[i][j]=1LL<<(tt+n-i);
		tt+=2;
	}
	rep(i,1,n){
		rep(j,1,n){
			printf("%lld%c",a[i][j],j==n?'\n':' ');
		}
	}
	fflush(stdout);
	int Q;cin>>Q;
	while(Q--){
		int num;cin>>num;
		printf("1 1\n");
		int pos=-1;
		per(i,60,0)if(num>>i&1){
			pos=i;
			break;
		}
		int x=1,y=1;
		while(x<n||y<n){
			if(x==n)++y;
			else if(y==n)++x;
			else{
				if(y&1){
					if(pos>=0&&(1LL<<pos)==a[x][y+1])++y,--pos;else ++x;
				}else{
					if(pos>=0&&(1LL<<pos)==a[x+1][y])++x,--pos;else ++y;
				}
				for(;pos>=0&&(~num>>pos&1);--pos);
			}
			printf("%lld %lld\n",x,y);
		}
		fflush(stdout);
	}
	return 0;
}