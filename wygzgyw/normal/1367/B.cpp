#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; int f=1; char ch=getchar();
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
int T,n,x,c1,c2;

int main() {
	//freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		read(n);
		c1=c2=0;
		for (int i=0;i<n;i++) {
			read(x);
			if (x%2==1&&i%2==0) c1++;
			else if (x%2==0&&i%2==1) c2++;
		}
		if (c1==c2) printf("%d\n",c1);
		else printf("-1\n");
	}
	return 0;
}