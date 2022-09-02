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
int n,D,m,a[N],b[N],pre[N];
signed main(){
	rd(n),rd(D),rd(m);
	rep(i,1,n){
		int x;
		rd(x);
		if(x<=m)b[++*b]=x;
		a[i]=x;
	}
	sort(a+1,a+1+n,[&](int x,int y){return x>y;});
	sort(b+1,b+1+*b);
	b[*b+1]=0;
	rep(i,1,n)pre[i]=pre[i-1]+a[i];
	int ans=0,sum=0;
	per(i,*b+1,1){
		if(b[i]>m){
			break;
		}
		sum+=b[i];
		ans=max(ans,sum+pre[min(n-*b,(n-(*b-i+1)+D)/(D+1))]);
	}
	pt(ans,'\n');
	return 0;
}