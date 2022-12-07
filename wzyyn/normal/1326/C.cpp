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
using namespace std;
const int mo=998244353;
const int N=200005;
int n,k,a[N];
int main(){
	scanf("%d%d",&n,&k);
	For(i,1,n) scanf("%d",&a[i]);
	int l=0,ans=1,fl=0;
	For(i,1,n) if (a[i]>=n-k+1){
		if (fl) ans=1ll*ans*(l+1)%mo;
		l=0; fl=1;
	}
	else ++l;
	printf("%lld %d\n",1ll*k*(n+n-k+1)/2,ans);
}