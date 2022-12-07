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

void solve(){
	int a,b,c,d;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	if (b>=a) printf("%d\n",b);
	else{
		ll T=b,rem=a-b;
		if (c<=d) printf("%d\n",-1);
		else{
			T+=rem/(c-d)*c;
			if (rem%(c-d)) T+=c;
			printf("%lld\n",T);
		}
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}