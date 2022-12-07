#include<bits/stdc++.h>
#define ll long long
#define uint unsigned
#define ull unsigned ll
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a))
#define CPY(a,b) memcpy(a,b,sizeof(a))
using namespace std;
const int N=1005;
int n,a[N],b[N],pa[N],pb[N],cnt;
pii px[N],py[N];
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]),pa[a[i]]=i;
	For(i,1,n) scanf("%d",&b[i]),pb[b[i]]=i;
	For(i,1,n) if (pa[i]!=i||pb[i]!=i){
		px[++cnt]=pii(i,pb[i]);
		py[cnt]=pii(pa[i],i);
		int x=i,y=pa[i];
		if (x!=y){
			swap(a[x],a[y]);
			swap(pa[a[x]],pa[a[y]]);
		}
		x=i,y=pb[i];
		if (x!=y){
			swap(b[x],b[y]);
			swap(pb[b[x]],pb[b[y]]);
		}
	}
	printf("%d\n",cnt);
	For(i,1,cnt)
		printf("%d %d %d %d\n",px[i].fi,px[i].se,py[i].fi,py[i].se);
}