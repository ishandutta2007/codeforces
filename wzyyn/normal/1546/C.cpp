#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
using namespace std;

const int N=100005;
int n,a[N],b[N],c[N];
void solve(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	*b=*c=0;
	for (int i=1;i<=n;i++)
		if (i&1) b[++*b]=a[i];
		else c[++*c]=a[i];
	sort(b+1,b+*b+1);
	sort(c+1,c+*c+1);
	for (int i=2;i<=*b;i++)
		if (b[i]<c[i-1]){
			puts("NO");
			return;
		}
	for (int i=1;i<=*c;i++)
		if (c[i]<b[i]){
			puts("NO");
			return;
		}
	puts("YES");
	
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}