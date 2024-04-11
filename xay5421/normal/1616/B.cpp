#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int N=1000005;
int T,n;
char s[N];
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	rd(T);
	while(T--){
		rd(n);
		scanf("%s",s+1);
		int maxr=n;
		rep(i,1,n-1){
			if(s[i]<s[i+1]){
				maxr=i;
				break;
			}
		}
		rep(i,1,maxr-1)if(s[i]==s[i+1]&&s[i]==s[1]){
			maxr=i;
			break;
		}
		rep(i,1,maxr)putchar(s[i]);
		per(i,maxr,1)putchar(s[i]);
		puts("");
	}
	return 0;
}