#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; int f=1; char ch=getchar();
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=(2e5)+10;
int T,n,k,ans,l,r,len;
char s[maxn];
int main() {
	//freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		ans=0;
		read(n); read(k);
		scanf("%s",s+1);
		for (int i=1,j;i<=n;) {
			j=i+1;
			while (j<=n&&s[j]=='0') j++;
			if (s[i]=='1') l=k; else l=0;
			if (j<=n&&s[j]=='1') r=k; else r=0;
			len=j-i;
			if (l==k) len--;
			len-=l+r;
			if (len>0) ans+=(len+k)/(k+1);
			i=j;
		}
		printf("%d\n",ans);
	}
	return 0;
}