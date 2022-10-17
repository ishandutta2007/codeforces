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
const int N=1005;
int n,a[N],b[N],c[N],len,ans[1005*1005][2];
void push(int x,int y){
	if(x>y)swap(x,y);
	assert(c[x]>c[y]);
	ans[++len][0]=x,ans[len][1]=y;
	swap(a[x],a[y]);
}
signed main(){
	rd(n);rep(i,1,n)rd(a[i]),b[i]=c[i]=a[i];sort(b+1,b+1+n);
	rep(i,1,n){
		VI d;
		rep(j,i,n){
			if(c[i]>c[j]){
				d.PB(j);
			}
		}
//		for(auto x:d)D(">>> %d\n",x);
		sort(ALL(d),[&](int k1,int k2){return c[k1]<c[k2]||(c[k1]==c[k2]&&k1<k2);});
		for(int j=SZ(d)-1;j>=0;--j)push(i,d[j]);
	}
	pt(len,'\n');
	rep(i,1,len)pt(ans[i][0],' '),pt(ans[i][1],'\n');
	return 0;
}