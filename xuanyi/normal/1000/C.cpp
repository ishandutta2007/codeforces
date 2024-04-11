#include <cstdio>
#include <algorithm>
using namespace std;
typedef unsigned long long ull;

const int MAXN=200005;

int n;
ull l[MAXN],r[MAXN],t[MAXN<<1],ans[MAXN];
int s[MAXN<<1],cnt[MAXN<<1],cnt2[MAXN<<1];

template <typename T>
inline void read(T &x){
	int ch,fl=0;
	while (ch=getchar(),ch<48 || 57<ch) fl^=!(ch^45); x=(ch&15);
	while (ch=getchar(),47<ch && ch<58) x=(x<<1)+(x<<3)+(ch&15);
	if (fl) x=-x;
}

template <typename T>
inline void print(T x){
	if (x<0) x=-x,putchar('-');
	if (x>9) print(x/10);
	putchar(x%10+48);
}

int main(){
	read(n);
	for (int i=1;i<=n;++i) read(l[i]),read(r[i]),t[++t[0]]=l[i],t[++t[0]]=r[i];
	sort(t+1,t+1+t[0]);
	t[0]=unique(t+1,t+1+t[0])-t-1;
	for (int i=1,a,b;i<=n;++i){
		a=lower_bound(t+1,t+1+t[0],l[i])-t;
		b=lower_bound(t+1,t+1+t[0],r[i])-t;
		s[a]++,s[b+1]--;
		cnt[a]++,cnt2[b]++;
	}
	for (int i=1;i<=t[0];++i) s[i]+=s[i-1]; ++ans[s[t[0]]];
	for (int i=1;i<t[0];++i){
		ans[s[i]]++,ans[s[i]+s[i+1]-cnt[i+1]-cnt2[i]>>1]+=t[i+1]-t[i]-1;
	}
	for (int i=1;i<=n;++i) print(ans[i]),putchar(' ');
	return 0;
}