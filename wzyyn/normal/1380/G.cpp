#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
#define y1 ysghysgsygsh
#define all(v) v.begin(),v.end()
using namespace std;
const int mo=998244353;
const int N=300005;
int n,a[N];
int power(int x,int y){
	int s=1;
	for (;y;y/=2,x=1ll*x*x%mo)
		if (y&1) s=1ll*s*x%mo;
	return s;
}
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	For(i,1,n) a[i]=(a[i]+a[i-1])%mo;
	For(i,1,n){
		int l=n-2*i+1,r=n-i,d=1,s=0;
		//cout<<l<<' '<<r<<endl;
		for (;r>0;l-=i,r-=i,d++)
			l=max(l,1),s=(s+1ll*d*(a[r]-a[l-1]+mo))%mo;
		printf("%lld ",1ll*s*power(n,mo-2)%mo);
	}
}