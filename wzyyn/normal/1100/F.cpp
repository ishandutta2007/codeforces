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
const int N=500005;
int n,Q,a[N],ans[N];
vector<pii> vec[N];
pii b[25];
void insert(pii v){
	Rep(i,20,0)
		if (v.fi&(1<<i)){
			if (!b[i].fi||b[i].se<v.se) swap(b[i],v);
			if (v.fi&(1<<i)) v.fi^=b[i].fi; 
		} 
}
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]);
	scanf("%d",&Q);
	For(i,1,Q){
		int l,r;
		scanf("%d%d",&l,&r);
		vec[r].PB(pii(l,i));
	}
	For(i,1,n){
		insert(pii(a[i],i));
		for (auto j:vec[i]){
			int val=0;
			Rep(k,20,0)
				if (b[k].se>=j.fi)
					val=max(val,val^b[k].fi);
			ans[j.se]=val;
		}
	}
	For(i,1,Q)
		printf("%d\n",ans[i]);
}