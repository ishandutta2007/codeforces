#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
int T;
int n,l,r,pos,mid,x,res;
vector<int> ans;
bool check(int mid,int pos) {
	printf("? %d %d\n",mid,1);
	for (int i=1;i<=mid;i++) printf("%d ",i); puts("");
	printf("%d\n",pos);
	fflush(stdout);
	scanf("%d",&x);
	if (x) return 1;
	return 0;
}
int main() {
	scanf("%d",&T);
	while (T--) {
		scanf("%d",&n);
		for (int i=2;i<=n;i++) {
			printf("? %d %d\n",i-1,1);
			for (int j=1;j<i;j++) printf("%d ",j); puts("");
			printf("%d\n",i);
			fflush(stdout);
			scanf("%d",&x);
			if (x) { pos=i; break; }
		}
		ans.clear();
		l=1,r=pos-1;
		while (l<=r) {
			mid=(l+r)>>1;
			if (check(mid,pos)) res=mid,r=mid-1;
			else l=mid+1;
		}
		for (int i=1;i<pos;i++) if (i!=res) ans.push_back(i);
		for (int i=pos+1;i<=n;i++) {
			printf("? %d %d\n",1,1);
			printf("%d\n%d\n",i,pos);
			fflush(stdout);
			scanf("%d",&x);
			if (!x) ans.push_back(i);
		}
		printf("! %d ",(int)ans.size());
		for (int i=0;i<ans.size();i++) printf("%d ",ans[i]); puts("");
		fflush(stdout);
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