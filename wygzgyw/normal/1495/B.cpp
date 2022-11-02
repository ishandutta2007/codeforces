#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=(1e5)+10;
int n,ans,p[maxn],up[maxn],dwn[maxn];
int lup[maxn],rup[maxn],ldwn[maxn],rdwn[maxn];
int Pre[maxn],Suf[maxn];
bool check(int x,int y) {
	int flag;
	if (x<y) {
		if (ldwn[x]) {
			flag=1;
			if (max(rup[y],lup[y])>=ldwn[x]) flag=0;
			if (flag) return 1;
		}
		flag=1;
		if ((y-x)&1) flag=0;
		if (rdwn[x]<=rup[y]) flag=0;
		return flag;
	}
	if (rdwn[x]) {
		flag=1;
		if (max(rup[y],lup[y])>=rdwn[x]) flag=0;
		if (flag) return 1;
	}
	flag=1;
	if ((x-y)&1) flag=0;
	if (ldwn[x]<=lup[y]) flag=0;
	return flag;
	
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n);
	for (int i=1;i<=n;i++) read(p[i]);
	for (int i=1;i<=n;i++) {
		if (i>1&&p[i-1]<p[i]) ldwn[i]=ldwn[i-1]+1;
		if (i>1&&p[i-1]>p[i]) lup[i]=lup[i-1]+1;
	}
	for (int i=n;i>=1;i--) {
		if (i<n&&p[i]<p[i+1]) rup[i]=rup[i+1]+1;
		if (i<n&&p[i]>p[i+1]) rdwn[i]=rdwn[i+1]+1;
	}
	for (int i=2;i<n;i++) {
		if (p[i-1]<p[i]&&p[i]>p[i+1]) up[i]=1;
		if (p[i-1]>p[i]&&p[i]<p[i+1]) dwn[i]=1;
	}
	if (p[1]>p[2]) up[1]=1; else dwn[1]=1;
	if (p[n-1]>p[n]) dwn[n]=1; else up[n]=1;
	
	for (int i=1;i<=n;i++) Pre[i]=max(Pre[i-1],max(lup[i],rup[i]));
	for (int i=n;i>=1;i--) Suf[i]=max(Suf[i+1],max(lup[i],rup[i]));
	
	for (int i=2;i<n;i++) if (up[i]) {
		int nxt=rdwn[i]+i,pre=i-ldwn[i],flag=1;
		if (nxt-2>i&&!check(i,nxt-2)) flag=0;
		if (nxt-1>i&&!check(i,nxt-1)) flag=0;
		if (nxt>i&&!check(i,nxt)) flag=0;
		if (pre+2<i&&!check(i,pre+2)) flag=0;
		if (pre+1<i&&!check(i,pre+1)) flag=0;
		if (pre<i&&!check(i,pre)) flag=0;
		if (max(Pre[pre-1],Suf[nxt+1])>=max(ldwn[i],rdwn[i])) flag=0;
		if (flag) {
		//	printf("%d\n",i);
			ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}
/*
  0. Enough array size? Enough array size? Enough array size? Integer overflow?
  
  1. Think TWICE, Code ONCE!
  Are there any counterexamples to your algo?
    
  2. Be careful about the BOUNDARIES!
  N=1? P=1? Something about 0?
    
  3. Do not make STUPID MISTAKES!
  Time complexity? Memory usage? Precision error?
*/