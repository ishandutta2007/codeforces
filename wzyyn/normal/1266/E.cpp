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
#define y1 ysghysgsygshc
using namespace std;
const int N=500005;
int n,Q,a[N],b[N];
map<pii,int> mp;
ll ans;
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]),ans+=a[i]; 
	scanf("%d",&Q);
	For(i,1,Q){
		int x,y,v;
		scanf("%d%d%d",&x,&y,&v);
		if (mp[pii(x,y)]!=0){
			int id=mp[pii(x,y)];
			if (--b[id]<a[id]) ++ans;
			mp[pii(x,y)]=0;
		}
		if (v){
			if (b[v]++<a[v]) --ans;
			mp[pii(x,y)]=v;
		}
		printf("%lld\n",ans);
	}
}