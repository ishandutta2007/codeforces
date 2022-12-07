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
const int N=200005;
int n,a[N];
ll W;
void solve(){
	scanf("%d%lld",&n,&W);
	For(i,1,n) scanf("%d",&a[i]);
	ll S=0,s1=0;
	For(i,1,n){
		if (a[i]>W) continue;
		S+=a[i]; s1++;
		if (S*2>=W&&S<=W){
			printf("%lld ",s1);
			For(j,1,i) if (a[j]<=W) printf("%d ",j);
			puts("");
			return;
		}
		if (a[i]*2>=W&&a[i]<=W){
			printf("1 %d\n",i);
			return;
		}
	}
	puts("-1");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}