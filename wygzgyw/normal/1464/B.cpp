#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int maxn=(1e5)+10;
int n;
char s[maxn];
ll x,y,s1,s2,ans,tmp;
int main() {
	//freopen("1.txt","r",stdin);
	scanf("%s",s+1);
	n=strlen(s+1);
	read(x),read(y);
	if (x<y) {
		for (int i=1;i<=n;i++) if (s[i]!='?') s[i]^=1;
		swap(x,y);
	}
	int c0=0,c1=0,all0,all1;
	for (int i=1;i<=n;i++) {
		if (s[i]=='1') c1++,s1+=c0;
		else c0++,s2+=c1;
	}
	ans=x*s1+y*s2;
	all0=c0,all1=c1;
	c0=0,c1=0;
	for (int i=1;i<=n;i++) {
		if (s[i]=='?') {
			c0++;
			s1-=all1-c1;
			s2-=c1;
			s1+=c0-1;
			s2+=all0-c0;
			all0--,all1++,c0--,c1++;
		} else {
			if (s[i]=='0') c0++;
			else c1++;
		}
		//printf("%lld %lld\n",s1,s2);
		tmp=x*s1+y*s2;
		ans=min(ans,tmp);
	}
	printf("%lld\n",ans);
	return 0;
}
/*
  0. Enough array size? Enough array size? Enough array size? Interger overflow?
  
  1. Think TWICE, Code ONCE!
  Are there any counterexamples to your algo?
    
  2. Be careful about the BOUNDARIES!
  N=1? P=1? Something about 0?
    
  3. Do not make STUPID MISTAKES!
  Time complexity? Memory usage? Precision error?
*/