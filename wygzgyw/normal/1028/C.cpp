#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
const int INF=(2e9);
const int maxn=600010;
int n,cnt,u[maxn],a[maxn],b[maxn],c[maxn],d[maxn];
int l1,r1,l2,r2;
int main() {
	//freopen("1.txt","r",stdin);
    read(n);
    for (int i=1;i<=n;i++) {
    	read(a[i]); read(c[i]); read(b[i]); read(d[i]);
    }
    l1=l2=-INF; r1=r2=INF;
    for (int i=1;i<=n;i++)
    	if (l1<=b[i]&&a[i]<=r1&&l2<=d[i]&&c[i]<=r2) {
    		cnt++;
    		l1=max(l1,a[i]); r1=min(r1,b[i]);
    		l2=max(l2,c[i]); r2=min(r2,d[i]);
    	}
    if (cnt<n-1) {
    	l1=l2=-INF; r1=r2=INF;
		for (int i=n;i>=1;i--)
			if (l1<=b[i]&&a[i]<=r1&&l2<=d[i]&&c[i]<=r2) {
				cnt++;
				l1=max(l1,a[i]); r1=min(r1,b[i]);
				l2=max(l2,c[i]); r2=min(r2,d[i]);
			}
    }
    printf("%d %d\n",r1,r2);
	return 0;
}