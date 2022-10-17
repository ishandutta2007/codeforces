#include <cstdio>
#include <cstring>

template <typename T>
inline void read(T &x){
	int ch,fl=0;
	while (ch=getchar(),ch<48 || 57<ch) fl^=!(ch^45); x=(ch&15);
	while (ch=getchar(),47<ch && ch<58) x=(x<<1)+(x<<3)+(ch&15);
	if (fl) x=-x;
}

template <typename T>
inline void write(T x){
	if (x<0) x=-x,putchar('-');
	if (x>9) write(x/10);
	putc(x%10+48);
}

int n,res,ans;
char s[200005];

int main(){
	scanf("%s",s);
	n=strlen(s);
	for (int i=n;i<(n<<1);i++) s[i]=s[i-n];
	res=1;
	for (int i=1;i<(n<<1);i++){
		if (s[i]!=s[i-1]) res++;
		else res=1;
		if (res>ans) ans=res;
	}
	if (ans>n) ans=n;
	printf("%d\n",ans);
	return 0;
}