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
int n,m,L,R;
int power(int x,ll y){
	int s=1;
	for (;y;y/=2,x=1ll*x*x%mo)
		if (y&1) s=1ll*s*x%mo;
	return s;
}
int main(){
	scanf("%d%d%d%d",&n,&m,&L,&R);
	if (1ll*n*m%2==1)
		printf("%d\n",power(R-L+1,1ll*n*m));
	else{
		int v1=R-L+1,v2=((R&1?1:-1)+(L&1?1:-1))/2;
		printf("%d\n",(power(v1,1ll*n*m)+power(mo+v2,1ll*n*m))*1ll*(mo+1)/2%mo);
	}
}