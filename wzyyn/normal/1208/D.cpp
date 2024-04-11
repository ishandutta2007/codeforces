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
const int N=1<<19;
int n,nn,ans[N];
ll v[N],t[N];
set<int> S;
void change(int x,int v){
	for (x+=nn;x;x>>=1) t[x]+=v;
}
int find(ll x){
	int k=1,l=0,r=nn-1;
	while (k<=nn){
		int mid=(l+r)/2;
		if (t[k*2]<=x){
			x-=t[k*2];
			l=mid+1;
			k=k*2+1;
		}
		else{
			r=mid;
			k=k*2;
		}
	}
	return l;
}
int main(){
	scanf("%d",&n);
	for (nn=1;nn<=n;nn<<=1);
	For(i,1,n){
		scanf("%lld",&v[i]);
		change(i,i);
		S.insert(i);
	}
	Rep(i,n,1){
		ans[i]=find(v[i]);
		ans[i]=*S.lower_bound(ans[i]);
		change(ans[i],-ans[i]);
		S.erase(ans[i]);
	}
	For(i,1,n)
		printf("%d ",ans[i]);
}