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
int a[4],b[4];
void mysort(){
	if(a[3]<a[2]){
		swap(a[2],a[3]);
		swap(b[2],b[3]);
	}
	if(a[2]<a[1]){
		swap(a[1],a[2]);
		swap(b[1],b[2]);
	}
	if(a[3]<a[2]){
		swap(a[2],a[3]);
		swap(b[2],b[3]);
	}
}
void go(int x){
	printf("%lld\n",x),fflush(stdout);
	int y;scanf("%lld",&y);
	if(y==0)exit(0);
	rep(i,1,3)if(b[i]==y){
		a[i]+=x;
	}
	mysort();
	rep(i,1,3){
		rep(j,1,3)if(b[j]==i)D("%lld ",a[j]);
	}
	D("\n");
}
signed main(){
	rd(a[1]),rd(a[2]),rd(a[3]);
	b[1]=1,b[2]=2,b[3]=3;
	puts("First"),fflush(stdout);
	go(1e10);
	const int INF=a[3];
	go(INF+INF-a[1]-a[2]);
	go(a[2]-a[1]);
	return 0;
}