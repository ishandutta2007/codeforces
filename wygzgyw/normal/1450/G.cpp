#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int INF=0x7f7f7f7f;
int n,a,b,cnt,l[1<<20],r[1<<20];
char s[5010],bk[30];
map<char,int> M;
int S[1<<20],f[1<<20];
vector<char> ans;
int main() {
	//freopen("1.txt","r",stdin);
	read(n),read(a),read(b); scanf("%s",s+1); int x;
	memset(l,INF,sizeof(l));
	for (int i=1;i<=n;i++) {
		x=M[s[i]]; if (!x) M[s[i]]=++cnt,bk[cnt]=s[i],x=cnt;
		l[1<<(x-1)]=min(l[1<<(x-1)],i);
		r[1<<(x-1)]=i;
		S[1<<(x-1)]++;
	}
	for (int t=1;t<(1<<cnt);t++)
	for (int i=0;i<cnt;i++) if (t&(1<<i)) {
		S[t]=S[t-(1<<i)]+S[1<<i];
		l[t]=min(l[t-(1<<i)],l[1<<i]);
		r[t]=max(r[t-(1<<i)],r[1<<i]);
	}
	f[0]=1;
	for (int t=1;t<(1<<cnt);t++) {
		int pre=0;
		for (int i=0;i<cnt;i++) if (t&(1<<i)) {
			pre+=(1<<i);
			if (f[t-pre]&&f[pre]) f[t]=1;
			if (f[t-(1<<i)]&&a*(r[t]-l[t]+1)<=b*S[t]) f[t]=1;
			if (f[t]) break;
		}
	//	printf("%d %d %d %d\n",t,l[t],r[t],S[t]);
	}
	for (int i=0;i<cnt;i++) if (f[(1<<cnt)-1-(1<<i)]) ans.push_back(bk[i+1]);
	sort(ans.begin(),ans.end());
	printf("%d ",(int)ans.size());
	for (char ch : ans) printf("%c ",ch);
	puts("");
	
	return 0;
}
/*
  REMEMBER:
  1. Think TWICE, Code ONCE!
  Are there any counterexamples to your algo?
    
  2. Be careful about the BOUNDARIES!
  N=1? P=1? Something about 0?
    
  3. Do not make STUPID MISTAKES!
  Array size? Integer overflow? Time complexity? Memory usage? Precision error?
*/