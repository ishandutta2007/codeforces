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
const int N=40005;
int n,m,k;
int a1[N],a2[N];
ll ans;
void ini(int *a,int n){
	int l=0;
	For(i,1,n){
		int x;
		scanf("%d",&x);
		if (!x) ++a[l],l=0;
		else ++l;
	} 
	++a[l];
	Rep(i,n,1) a[i]+=a[i+1];
	Rep(i,n,1) a[i]+=a[i+1];
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	ini(a1,n); ini(a2,m);
	For(i,1,n) if (k%i==0&&k/i<=m) ans+=1ll*a1[i]*a2[k/i];
	printf("%lld\n",ans);
}