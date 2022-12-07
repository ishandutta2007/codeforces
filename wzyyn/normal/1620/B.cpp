#include<bits/stdc++.h>

using namespace std;

const int N=200005;
int w,h;
int a[N],b[N],c[N],d[N];
void solve(){
	scanf("%d%d",&w,&h);
	scanf("%d",a);
	for (int i=1;i<=*a;i++)
		scanf("%d",&a[i]);
	scanf("%d",b);
	for (int i=1;i<=*b;i++)
		scanf("%d",&b[i]);
	scanf("%d",c);
	for (int i=1;i<=*c;i++)
		scanf("%d",&c[i]);
	scanf("%d",d);
	for (int i=1;i<=*d;i++)
		scanf("%d",&d[i]);
	printf("%lld\n",max(1ll*h*max(a[*a]-a[1],b[*b]-b[1]),
						1ll*w*max(c[*c]-c[1],d[*d]-d[1])));
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}