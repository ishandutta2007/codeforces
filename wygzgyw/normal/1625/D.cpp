// wygzgyw
#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
template <typename T> void write(T t) {
	if (t<0) { putchar('-'); write(-t); return; }
	if (t>9) write(t/10);
	putchar('0'+t%10);
}
template <typename T> void writeln(T t) { write(t); puts(""); }
#define MP make_pair
const int maxn=(3e5)+10;
int n,a[maxn],x;
bool mk[maxn];
int tot,ch[maxn*30][2];
int rt,id[maxn*30];
void insert(int x,int i) {
	int now=rt;
	for (int j=30;j>=0;j--) {
		int t=(x>>j&1);
		if (!ch[now][t]) ch[now][t]=++tot;
		now=ch[now][t]; id[now]=i;
	}
}
void solve(int now,vector<int> A) {
	if ((int)A.size()==0) return;
	if ((int)A.size()==1) { mk[A[0]]=1; return; }
	assert(now>=0);
	vector<int> C[2];
	C[0].clear(),C[1].clear();
	for (int &i : A) C[a[i]>>now&1].push_back(i);
		/*printf("now=%d\n",now);
		for (int &i : C[0]) printf("%d ",i); puts("");
		for (int &i : C[1]) printf("%d ",i); puts("");
		puts("");*/
	if (x>>now&1) {
		if ((int)C[0].size()==0||(int)C[1].size()==0) {
			mk[A[0]]=1; return;
		}
		rt=++tot;
		for (int &i : C[0]) insert(a[i],i);
		for (int &i : C[1]) {
			int now=rt,fd=0,flag=1;
			for (int j=30;j>=0;j--) {
				int t=(a[i]>>j&1);
				if (x>>j&1) {
					if (!id[ch[now][t^1]]) { flag=0; break; }
					now=ch[now][t^1];
				} else {
					if (id[ch[now][t^1]]) {
						fd=id[ch[now][t^1]]; break;
					} now=ch[now][t];
				}
			}
			if (flag) {
				if (!fd) fd=id[now];
				mk[i]=mk[fd]=1; return;
			}
		}
		mk[A[0]]=1;
		return;
	}
	solve(now-1,C[0]),solve(now-1,C[1]);
}
int main() {
	read(n),read(x);
	if (x==0) { printf("%d\n",n); for (int i=1;i<=n;i++) printf("%d ",i); puts(""); return 0; }
	for (int i=1;i<=n;i++) read(a[i]);
	vector<int> A;
	for (int i=1;i<=n;i++) A.push_back(i);
	solve(30,A);
	int cnt=0;
	for (int i=1;i<=n;i++) if (mk[i]) cnt++;
	if (cnt<2) { puts("-1"); return 0; }
	printf("%d\n",cnt);
	for (int i=1;i<=n;i++) if (mk[i]) printf("%d ",i); puts("");
	return 0;
	if (n<=1000) {
		for (int i=1;i<=n;i++) for (int j=i+1;j<=n;j++) if (mk[i]&&mk[j]) assert((a[i]^a[j])>=x);
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