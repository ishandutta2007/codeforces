#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int mod=(1e9)+7;
const int maxn=(2e5)+10;
int T,n,len,ans,tmp,m2[maxn];
int op,jc[maxn],ivjc[maxn],iv[maxn],mi[maxn];
char s[maxn];
int C(int x,int y) {
	if (x<y||y<0) return 0;
	return (ll)jc[x]*ivjc[y]%mod*ivjc[x-y]%mod;
}
void update(int &x,int y) { x+=y; if (x>=mod) x-=mod; }
map<int,int> M; int now,cnt;
int f[450][maxn/2];
void insert(int len) {
	if (M[len]) return;
	M[len]=++cnt;
	f[cnt][len]=1;
	for (int i=len+1;i<=100000;i++) {
		f[cnt][i]=(ll)26*f[cnt][i-1]%mod;
		update(f[cnt][i],(ll)mi[i-len]*C(i-1,len-1)%mod);
	}
}
int main() {
	//freopen("1.txt","r",stdin);
	jc[0]=iv[0]=ivjc[0]=jc[1]=iv[1]=ivjc[1]=1;
	for (int i=2;i<maxn;i++) {
		jc[i]=(ll)jc[i-1]*i%mod;
		iv[i]=(ll)(mod-mod/i)*iv[mod%i]%mod;
		ivjc[i]=(ll)ivjc[i-1]*iv[i]%mod;
	}
	mi[0]=1; for (int i=1;i<maxn;i++) mi[i]=(ll)mi[i-1]*25%mod;
	m2[0]=1; for (int i=1;i<maxn;i++) m2[i]=(ll)m2[i-1]*26%mod;
	read(T);
	scanf("%s",s+1); len=strlen(s+1); insert(len);
	while (T--) {
		read(op);
		if (op==1) { scanf("%s",s+1); len=strlen(s+1); insert(len); }
		else {
			now=M[len];
			read(n);
			printf("%d\n",f[now][n]);
		}
	}
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