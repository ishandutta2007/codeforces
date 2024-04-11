#include <cstdio>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
typedef long long ll;
const int MOD=998244353;

template <typename T>
void read(T &x){
	int fl=0,ch;
	while (ch=getchar(),ch<48||57<ch) fl^=!(ch^45); x=(ch&15);
	while (ch=getchar(),47<ch&&ch<58) x=(x+(x<<2)<<1)+(ch&15);
	if (fl) x=-x;
}

template <typename T>
void print(T x){
	if (x<0) x=-x,putchar('-');
	if (x>9) print(x/10);
	putchar(x%10+48);
}

template <typename T>
void print(T x,int ch){
	print(x),putchar(ch);
}

int n,x=1,y=1;
char s[200005];
ll ans;
bool flag=1;

int main(){
	read(n);
	scanf("%s",s);
	for (int i=1;i<n;++i) flag&=s[i]==s[i-1];
	if (flag){print((ll)n*(n+1)/2%MOD,'\n');return 0;}
	for (int i=0;i<n;++i){x+=s[i]==s[0];if (s[i]!=s[0]) break;}
	for (int i=n-1;i>=0;--i){y+=s[i]==s[n-1];if (s[i]!=s[n-1]) break;}
	if (s[0]==s[n-1]){print((ll)x*y%MOD,'\n');return 0;}
	else print(((ll)x+y-1)%MOD,'\n');
	return 0;
}