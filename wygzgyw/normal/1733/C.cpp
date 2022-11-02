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
const int maxn=(1e5)+10;
int T,n;
int a[maxn];
vector<pair<int,int> > ans;
void add(int l,int r) {
	ans.push_back(MP(l,r));
	if ((a[l]+a[r])%2==1) a[r]=a[l]; else a[l]=a[r];
}
int main() {
	//freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		read(n);
		for (int i=1;i<=n;i++) read(a[i]);
		ans.clear();
		if ((a[n]%2)!=(a[1]%2)) add(1,n);
		for (int i=1;i<n;i++) if (a[i]%2==a[n]%2) add(i,n);
		int lst;
		for (int i=1;i<n;i++) {
			if (a[i]%2==a[n]%2) lst=i;
			else add(lst,i);
		}
		printf("%d\n",(int)ans.size());
		for (auto [x,y] : ans) printf("%d %d\n",x,y);
		
		for (int i=1;i<n;i++) assert(a[i]<=a[i+1]);
	}
	return 0;
}