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
const int N=300005;
int T,n,K;
char s[N];
signed main(){
	rd(T);
	while(T--){
		rd(n),rd(K);
		scanf("%s",s+1);
		bool f=1;
		int cnt0=0,cnt1=0,cnt2=0;
		for(int i=1;i<=K;++i){
			int lst='?';
			for(int j=i;j<=n;j+=K){
				if(lst=='?')lst=s[j];
				else if(lst!=s[j]&&s[j]!='?'){
					f=0;
				}
			}
			if(lst=='0')++cnt0;
			if(lst=='1')++cnt1;
			if(lst=='?')++cnt2;
		}
		f&=min(cnt0,cnt1)+cnt2>=max(cnt0,cnt1);
		puts(f?"YES":"NO");
	}
	return 0;
}