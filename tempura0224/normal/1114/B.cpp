#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#include<numeric>
using namespace std;
#define REP(i,m,n) for(int i=(int)m ; i < (int) n ; ++i )
#define rep(i,n) REP(i,0,n)
typedef long long ll;
typedef pair<int,int> pint;
typedef pair<ll,int> pli;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

int main(){
	int n,k,m;
	cin>>n>>m>>k;
	ll a[n];
	rep(i,n){
		cin>>a[i];
	}
	vector<int> ord(n);
	iota(ord.begin(),ord.end(),0);
	sort(ord.begin(),ord.end(),[&](int x,int y){
		return a[x]>a[y];
	});
	vector<int>cnt(n);
	ll ans=0;
	rep(i,k*m){
		cnt[ord[i]]=1;
		ans+=a[ord[i]];
	}
	printf("%lld\n",ans);
	int sum=0;
	rep(i,n){
		sum+=cnt[i];
		if(sum==m){
			--k;
			if(k)printf("%d ",i+1);
			sum=0;
		}
	}
	return 0;
}