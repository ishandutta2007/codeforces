#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define double long double
using namespace std;

int n,a[100005],b[100005],m;
void solve(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]);
	if (n==1) return puts("0"),void(0);
	For(i,1,n-1) b[i]=a[i+1]-a[i];
	sort(b+1,b+n);
	m=unique(b+1,b+n)-b-1;
	if (m==1) puts("0");
	else if (m>=3) puts("-1");
	else if (b[1]>=0&&b[2]>=0) puts("-1");
	else if (b[1]<=0&&b[2]<=0) puts("-1");
	else{
		int v=b[2]-b[1],A=b[2],fl=0;
		if (a[1]>=v) fl=1;
		For(i,2,n) if ((a[i-1]+A)%v!=a[i]) fl=1;
		if (fl) puts("-1");
		else printf("%d %d\n",v,A);
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}