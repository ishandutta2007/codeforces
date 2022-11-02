#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
int T;
ll x,y;
int main() {
	//freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		read(x); read(y);
		if (x-y==1) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}