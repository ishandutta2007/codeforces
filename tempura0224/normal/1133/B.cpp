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
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
typedef long long ll;
typedef pair<int,int> pint;
typedef pair<ll,int> pli;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

int main(){
	int n,k;
	cin>>n>>k;
	vector<ll>  cnt(k);
	rep(i,n){
		int x;
		cin>>x;
		++cnt[x%k];
	}
	int ans=0;
	for(int i=0 ; 2*i<=k ; ++i){
		int j=(k-i)%k;
		if(i==j)ans+=cnt[i]/2;
		else ans+=min(cnt[i],cnt[j]);
	}
	cout<<2*ans<<endl;
	return 0;
}