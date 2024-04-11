#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=(1e4)+10;
int T,n,sum,a[maxn];
struct node { int x,y,z; };
vector<node> ans;
void move(int x,int y,int z) {
	ans.push_back((node){x,y,z});
	a[x]-=x*z,a[y]+=x*z;
}
int main() {
	//freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		read(n); ans.clear(); sum=0;
		for (int i=1;i<=n;i++) read(a[i]),sum+=a[i];
		if (sum%n!=0) { puts("-1"); continue; }
		for (int i=2;i<=n;i++) {
			if (a[i]%i==0) move(i,1,a[i]/i);
			else move(1,i,i-a[i]%i),move(i,1,a[i]/i);
		}
		for (int i=2;i<=n;i++) move(1,i,sum/n);
		printf("%d\n",(int)ans.size());
		for (int i=0;i<ans.size();i++) printf("%d %d %d\n",ans[i].x,ans[i].y,ans[i].z);
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