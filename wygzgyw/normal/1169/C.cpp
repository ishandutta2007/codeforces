#include <bits/stdc++.h>
#define dbug(x) cout<<#x<<"="<<x<<endl
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=300010;
int n,m,a[maxn];
bool solve(int mid) {
	int lst=0;
	for (int i=1;i<=n;i++) {
		//printf("%d %d\n",a[i],lst);
		if (a[i]>=lst) {
			if ((a[i]+mid)%m>=lst&&a[i]+mid>=m) ;
			else lst=a[i];
		} else {
			if (lst-a[i]>mid) return 0;
		}
	} return 1;
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n); read(m);
	for (int i=1;i<=n;i++) read(a[i]);
	int l=0,r=m-1,res,mid;
	while (l<=r) {
		mid=(l+r)/2;
		if (solve(mid)) r=mid-1,res=mid;
		else l=mid+1;
	} printf("%d\n",res);
	return 0;
}