#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
int T,n,pos[1000],L,R;
char s[210];
char ans[2010];
bool flag;
int main() {
	//freopen("1.txt","r",stdin);
	read(T);
	int x,tmp;
	while (T--) {
		for (int i='a';i<='z';i++) pos[i]=0;
		scanf("%s",s+1);
		n=strlen(s+1);
		L=100,R=100;
		ans[L]=s[1];
		pos[s[1]]=L;
		x=L;
		flag=1;
		for (int i=2;i<=n;i++) {
			if (!pos[s[i]]) {
				if (L>x-1) L--,ans[L]=s[i],pos[s[i]]=L,x=L;
				else if (R<x+1) R++,ans[R]=s[i],pos[s[i]]=R,x=R;
				else { flag=0; break; }
			} else {
				if (abs(x-pos[s[i]])==1) {
					x=pos[s[i]];
				} else { flag=0; break; }
			}
		}
		if (!flag) printf("NO\n");
		else {
			printf("YES\n");
			for (int i=L;i<=R;i++) printf("%c",ans[i]);
			for (int i='a';i<='z';i++)
				if (!pos[i]) printf("%c",i);
			printf("\n");
		}
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