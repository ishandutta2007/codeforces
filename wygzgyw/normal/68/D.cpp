#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
int h,q,sz;
map<int,int> s;
char t[10];
void add(int x,int y) {
	while (x) s[x]+=y,x/=2;
}
double solve(int x,int mx) {
	if (s[x]<=mx) return mx;
	double res=solve(x*2,max(mx,s[x]-s[x*2]))+solve(x*2+1,max(mx,s[x]-s[x*2+1]));
	return res*0.5;
}
int main() {
	//freopen("1.txt","r",stdin);
	read(h); read(q);
	int x,y;
	while (q--) {
		scanf("%s",t+1);
		if (t[1]=='a') {
			read(x); read(y);
			add(x,y);
		} else {
			printf("%.10lf\n",solve(1,0));
		}
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