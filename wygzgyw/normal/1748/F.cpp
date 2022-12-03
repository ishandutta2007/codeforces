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
int n;
bitset<410> a[410];
vector<int> ans;
void add(int x) {
	a[x]^=a[(x+1)%n];
	ans.push_back(x);
}
void solve(int x,int y) {
	int m=(y-x+n)%n;
	int l=0,r=m-1;
	while (l<=r) {
		for (int i=r;i>=l;i--) add((x+i)%n);
		for (int i=l+1;i<=r;i++) add((x+i)%n);
		l++,r--;
	}
	if (m>=2) {
		for (int i=0;i<=(m-2)/2;i++) add((x+i)%n);
	}
}
int main() {
	read(n);
	for (int i=0;i<n;i++) a[i].set(i);
	if (n==2) add(1),add(0),add(1);
	else {
		solve(0,n-1);
		if (n%2==0) solve(n/2,n/2-1); else solve(n/2+1,n/2-1);
		solve(0,n-1);
	}
	printf("%d\n",(int)ans.size());
	for (int &x : ans) printf("%d ",x); puts("");
	
	for (int i=0;i<n;i++) {
		for (int j=0;j<n;j++) assert(a[i].test(j)==(j+i==n-1));
	}
	
	return 0;
}