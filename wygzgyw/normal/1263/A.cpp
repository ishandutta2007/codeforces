#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
int T,d[4],a,b,c,x,ans;
int main() {
	//freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		read(d[1]); read(d[2]); read(d[3]);
		sort(d+1,d+4);
		a=d[1],b=d[2],c=d[3];
		
		x=max(0,(a+b-c+1)/2);
		ans=min(c,a+b-x*2)+x;
		x=max(0,(a+b-c)/2);
		ans=max(ans,min(c,a+b-x*2)+x);
		printf("%d\n",ans);
	}
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