#include<bits/stdc++.h> 
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define ll long long
#define fi first
#define se second
#define PB push_back
#define uint unsigned
#define ull unsigned ll
using namespace std;
const int N=200005;
vector<int> vec[N];
ll a[N],b[N],A[N];
int n,T;
void insert(int id){
	ll TT=A[id]/b[id];
	if (TT<T) vec[TT].PB(id);
}
bool check(ll v){
	For(i,1,n) A[i]=a[i];
	For(i,0,T-1) vec[i].clear();
	For(i,1,n) insert(i);
	int nowT=0;
	For(i,0,T-2)
		for (;vec[i].size();){
			int id=vec[i].back();
			vec[i].pop_back();
			if (nowT>i) return 0;
			++nowT;
			A[id]+=v;
			//printf("%d %d %d %lld %lld\n",i,id,nowT,v,A[id]); 
			insert(id);
		}
	return 1;
}
int main(){
	scanf("%d%d",&n,&T);
	For(i,1,n) scanf("%lld",&a[i]);
	For(i,1,n) scanf("%lld",&b[i]);
	ll l=0,r=1ll<<41,ans=-1;
	while (l<=r){
		ll mid=(l+r)/2;
		if (check(mid)) ans=mid,r=mid-1;
		else l=mid+1;
	}
	printf("%lld\n",ans);
}