#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 209;
int R,G,B;
ll a[N],b[N],c[N];
ll f[N][N][N];
bool cmp(ll x,ll y){return x>y;}
int main(){
	scanf("%d%d%d",&R,&G,&B);
	for(int i=1;i<=R;i++) scanf("%lld",&a[i]);
	for(int i=1;i<=G;i++) scanf("%lld",&b[i]);
	for(int i=1;i<=B;i++) scanf("%lld",&c[i]);
	sort(a+1,a+R+1,cmp);
	sort(b+1,b+G+1,cmp);
	sort(c+1,c+B+1,cmp);
	memset(f,0,sizeof(f));ll ans=0;
	for(int i=0;i<=R;i++)
		for(int j=0;j<=G;j++)
			for(int k=0;k<=B;k++){
				if(i&&j) f[i][j][k]=max(f[i][j][k],f[i-1][j-1][k]+a[i]*b[j]);
				if(i&&k) f[i][j][k]=max(f[i][j][k],f[i-1][j][k-1]+a[i]*c[k]);
				if(j&&k) f[i][j][k]=max(f[i][j][k],f[i][j-1][k-1]+b[j]*c[k]);
				ans=max(ans,f[i][j][k]);
			}
	printf("%lld\n",ans);
	return 0;
}