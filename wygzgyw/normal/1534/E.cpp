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
int n,k;
int sum,a[510];

int main() {
	scanf("%d %d",&n,&k);
	if (n%2==1&&k%2==0) { puts("-1"); return 0; }
	for (int i=1;i<=n;i++) {
		a[i]=1; sum++;
	}
	int mx=1;
	while (sum%k!=0||mx>sum/k) {
		int id=0;
		for (int i=1;i<=n;i++) if (!id||a[i]<a[id]) id=i;
		a[id]+=2,sum+=2; mx=max(mx,a[id]);
	}
	vector<pair<int,int> > now; int ans=0,x;
	while (sum) {
		printf("? "); now.clear();
		for (int i=1;i<=n;i++) now.push_back(MP(a[i],i));
		sort(now.begin(),now.end()); reverse(now.begin(),now.end());
		for (int i=0;i<k;i++) {
			printf("%d ",now[i].second);
			a[now[i].second]--; sum--;
		}
		printf("\n"); fflush(stdout);
		scanf("%d",&x); ans^=x;
	}
	printf("! %d\n",ans); fflush(stdout);
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