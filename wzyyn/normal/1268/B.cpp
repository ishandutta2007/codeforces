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
int n;
int main(){
	scanf("%d",&n);
	ll S0=0,S1=0;
	For(i,1,n){
		int x;
		scanf("%d",&x);
		i&1?S0+=x/2:S1+=x/2;
		i&1?S1+=x-x/2:S0+=x-x/2;
	}
	printf("%lld",min(S0,S1));
}