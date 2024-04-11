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
int T,n;char s[N],t[N];
signed main(){
	rd(T);
	while(T--){
		rd(n);scanf("%s%s",s+1,t+1);
		VI ans;
		int ind=0;
		for(int i=n;i>=1;--i){
			int num=(n-i)&1;
			if(i%2==n%2){
				if((s[1+ind]^num)==t[i])ans.PB(1);
			}else{
				if((s[n-ind]^num)==t[i])ans.PB(1);
				++ind;
			}
			ans.PB(i);
		}
		pt(SZ(ans),' ');for(auto x:ans)pt(x,' ');puts("");
	}
	return 0;
}