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
ll ans;
multiset<int> S,now;
map<int,int> mp;
int main(){
	scanf("%d",&n);
	For(i,1,n){
		int x;
		scanf("%d",&x);
		mp[x]++; ans+=x;
	}
	map<int,int>::iterator it;
	for (it=mp.end();it!=mp.begin();){
		int x=(--it)->fi,cnt=it->se;
		for (;cnt&&!S.empty()&&!*S.begin();)
			--cnt,S.erase(S.begin()),now.insert(x);
		for (;cnt>1&&!S.empty();){
			int y=*S.begin();
			if (y>=2*x) break;
			S.erase(S.begin()); cnt-=2;
			if (y<x) now.insert(x),now.insert(x);
			else now.insert(2*x-y),now.insert(y);
		}
		if (cnt&&!S.empty()&&*S.begin()<x)
			S.erase(S.begin()),now.insert(x),now.insert(0),cnt--;
		for (;cnt;cnt--) now.insert(0);
		for (;!now.empty();S.insert(*now.begin()),now.erase(now.begin()));
	}
	for (auto i:S) ans-=i;
	cout<<ans<<endl;
}