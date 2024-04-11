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
#define UPD(x,y) (((x)+=(y))>=mo?x-=mo:233)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
using namespace std;
ll n,fir;
int main(){
	scanf("%lld",&n);
	fir=n;
	for (int i=2;1ll*i*i<=n;i++)
		if (n%i==0){
			fir=i;
			break;
		}
	for (;n!=1&&n%fir==0;n/=fir);
	printf("%lld\n",n==1?fir:1);
}