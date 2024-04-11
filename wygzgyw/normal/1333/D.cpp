#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=3010;
int n,K,tot,N;
char s[maxn];
int L[maxn*maxn],R[maxn*maxn],ans[maxn*maxn];
int main() {
//	freopen("1.txt","r",stdin);
	read(n); read(K);
	scanf("%s",s+1);
	while (1) {
		tot++; L[tot]=R[tot-1]+1; R[tot]=L[tot]-1;
		for (int i=1;i<n;i++) if (s[i]=='R'&&s[i+1]=='L') ans[++R[tot]]=i;
		if (L[tot]>R[tot]) { tot--; break; }
		for (int i=L[tot];i<=R[tot];i++)
			swap(s[ans[i]],s[ans[i]+1]);
	//	printf("%s\n",s+1);
	}
//	for (int i=1;i<=R[tot];i++) printf("%d ",ans[i]); printf("\n");
	if (tot>K||R[tot]<K) { printf("-1\n"); return 0; }
	int pos=1,res=K-tot;
	for (int i=1;i<=tot;i++) {
		if (!res) break;
		for (int j=L[i];j<=R[i];j++) {
			printf("1 %d\n",ans[j]);
			if (j<R[i]) res--;
			if (!res) {
				printf("%d ",R[i]-j);
				for (int k=j+1;k<=R[i];k++)
					printf("%d ",ans[k]);
				printf("\n");
				pos=i+1;
				break;
			}
		}
		if (!res) break;
	}
	for (int i=pos;i<=tot;i++) {
		printf("%d ",R[i]-L[i]+1);
		for (int j=L[i];j<=R[i];j++) printf("%d ",ans[j]); printf("\n");
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