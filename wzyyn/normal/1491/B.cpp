#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define pii pair<int,int>
#define fi first
#define se second
#define PB push_back
#define ll long long
#define ull unsigned long long
#define pll pair<ll,ll> 
#define y1 orzkcz
using namespace std;
int n,u,v,a[505];
void solve(){
	scanf("%d%d%d",&n,&u,&v);
	For(i,1,n) scanf("%d",&a[i]);
	For(i,2,n) if (abs(a[i]-a[i-1])>=2) return puts("0"),void(0);
	For(i,2,n) if (abs(a[i]-a[i-1])==1) return printf("%d\n",min(u,v)),void(0);
	printf("%d\n",min(u,v)+v);
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}