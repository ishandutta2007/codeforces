#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int INF=(1e9);
const int maxn=(3e5)+10;
int n,m,tot,d[maxn][10],t[maxn];
ll cnt[1<<8],b[1<<8];
int pos[1<<8];
struct node {
	int x,y,z;
} a[maxn*10];
bool cmp(node A,node B) { return A.z>B.z; }
void FWT_or(ll *a,int N,int op) {
	int tmp;
	for (int i=1;i<N;i*=2) {
		tmp=i*2;
		for (int j=0;j<N;j+=tmp)
		for (int k=0;k<i;k++)
			if (op==1) a[i+j+k]+=a[j+k];
			else a[i+j+k]-=a[j+k];
	}
}
int main() {
//	freopen("1.txt","r",stdin);
	read(n); read(m);
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++) {
		read(d[i][j]);
		a[++tot]=(node){i,j,d[i][j]};
	}
	sort(a+1,a+tot+1,cmp);
	cnt[0]=n;
	int x,y;
	for (int I=1;I<=tot;I++) {
		x=a[I].x,y=a[I].y;
		cnt[t[x]]--;
		t[x]+=1<<(y-1);
		cnt[t[x]]++;
		pos[t[x]]=x;
		if (cnt[t[x]]==1) {
			for (int i=0;i<(1<<m);i++) b[i]=cnt[i];
			FWT_or(b,1<<m,1);
			for (int i=0;i<(1<<m);i++) b[i]=b[i]*b[i];
			FWT_or(b,1<<m,-1);
			if (b[(1<<m)-1]) {
				for (int i=0;i<(1<<m);i++)
					if (pos[i]&&(i|t[x])==(1<<m)-1) {
						printf("%d %d\n",x,pos[i]);
						return 0;
					}
			}
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