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
int T,n,K;
char s[N];
signed main(){
	rd(T);
	while(T--){
		rd(n),rd(K);
		scanf("%s",s+1);
		vector<int>v;
		for(int i=1,j;i<=n;i=j){
			j=i+1;
			while(j<=n&&s[i]==s[j])++j;
			if(i>1&&j<=n&&s[i]=='L'){
				v.PB(j-i);
			}
		}
		int W=0,L=0;
		rep(i,1,n)if(s[i]=='W')++W;else ++L;
		if(L<=K){
			pt(n*2-1,'\n');
			continue;
		}
		sort(v.begin(),v.end());
		int res=W==0?-1:0;
		rep(i,1,n){
			res+=(s[i]=='W')+(s[i]=='W'&&s[i-1]=='W');
		}
		rep(i,0,SZ(v)-1){
			if(v[i]<=K){
				K-=v[i];
				res+=v[i]*2;
				++res;
			}else break;
		}
		res+=K*2;
		pt(max(0LL,res),'\n');
	}
	return 0;
}