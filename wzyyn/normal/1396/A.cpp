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
ll a[200005];
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%lld",&a[i]);
	if (n==1) printf("1 1\n%lld\n1 1\n0\n1 1\n0\n",-a[1]);
	else{
		printf("1 %d\n",n-1);
		For(i,1,n-1){
			int T=(a[i]%n+n)%n;
			printf("%lld ",1ll*T*(n-1));
			a[i]+=1ll*T*(n-1);
		}
		puts("");
		printf("%d %d\n%lld\n",n,n,-a[n]);
		a[n]=0;
		printf("%d %d\n",1,n);
		For(i,1,n) printf("%lld ",-a[i]);
	}
}