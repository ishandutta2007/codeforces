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
#define all(v) v.begin(),v.end()
using namespace std;
map<int,ll> mp;
void mian(){
	mp.clear();
	int n,k;
	ll ans=0;
	cin>>n>>k;
	For(i,1,n){
		int x;
		cin>>x;
		if (!(x%k)) continue;
		if (!mp[x%k]) mp[x%k]=k-x%k+1;
		ans=max(ans,mp[x%k]);
		mp[x%k]+=k;
	}
	cout<<ans<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) mian();
}