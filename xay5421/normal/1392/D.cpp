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
const int N=400005;
int T,n;char s[N];
signed main(){
	rd(T);
	while(T--){
		rd(n);scanf("%s",s+1);
		int pos=-1;
		rep(i,2,n){
			if(s[i]!=s[i-1]){
				pos=i;
				break;
			}
		}
		if(pos==-1){
			pt((n+2)/3,'\n');
			continue;
		}
		rep(i,1,pos-1)s[i+n]=s[i];
//		rep(i,pos,n+pos-1)putchar(s[i]);puts("");
		int ans=0;
		rep(i,pos,n+pos-3){
			if(s[i]==s[i+1]&&s[i]==s[i+2]){
				if(i+3<=n+pos-1&&s[i+3]==s[i])s[i+2]=(s[i+2]=='L'?'R':'L');
				else s[i+1]=(s[i+1]=='L'?'R':'L');
				++ans;
			}
		}
		pt(ans,'\n');
	}
	return 0;
}