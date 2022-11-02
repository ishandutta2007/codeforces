#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int mod=(1e9)+7;
const int maxn=(1e6)+200;
int n,q,m,mi[maxn];
char s[maxn],t[maxn],w[maxn];
int cnt[26][maxn];
int ans;
void update(int &x,int y) { x+=y; if (x>=mod) x-=mod; }
void solve(int l,int r,string &A) {
	if (l>r) return;
	if (A.size()==1) {
		update(ans,(cnt[A[0]-'a'][r]-(ll)cnt[A[0]-'a'][l-1]*mi[r-l+1]%mod+mod)%mod);
		return;
	}
	int len=A.size(),flag;
	for (int op=0;op<=1;op++) {
		flag=1;
		for (int i=op;i<len;i+=2) if (A[i]!=t[l]) { flag=0; break; }
		if (flag) {
			string B="";
			for (int i=op^1;i<len;i+=2) B+=A[i];
			solve(l+1,r,B);
		}
	}
}
int main() {
	//freopen("1.txt","r",stdin);
	scanf("%d %d",&n,&q);
	scanf("%s",s),m=strlen(s);
	s[m]='*';
	for (int i=m+1;i<maxn;i++) s[i]=s[i-m-1];
	scanf("%s",t+1);
	mi[0]=1;
	for (int i=1;i<maxn;i++) mi[i]=(ll)mi[i-1]*2%mod;
	for (int i=1;i<=n;i++) {
		for (int j=0;j<26;j++) cnt[j][i]=(ll)cnt[j][i-1]*2%mod;
		update(cnt[t[i]-'a'][i],1);
	}
	bool flag; int k,len;
	while (q--) {
		scanf("%d %s",&k,w);
		len=strlen(w);
		ans=0;
		for (int i=0;i<=m;i++) {
			flag=1;
			for (int j=0;j<len;j++)
				if (s[i+j]!='*'&&s[i+j]!=w[j]) { flag=0; break; }
			if (flag) {
				string A="";
				for (int j=0;j<len;j++) if (s[i+j]=='*') A+=w[j];
				if (A.size()) solve(1,k,A);
				else update(ans,mi[k]);
			}
		}
		printf("%d\n",ans);
	}
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