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
using ll = long long;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

int main(){
	string s;
	cin>>s;
	int n=s.size();
	vector<int> mi(n,inf);
	rep(i,n){
		for(int j=1;i-j>=0&&i+j<n;++j){
			if(s[i-j]==s[i]&&s[i]==s[i+j]){
				mi[i-j]=min(i+j,mi[i-j]);
				break;
			}
		}
	}
	rep(i,n-1){
		mi[n-i-2]=min(mi[n-i-2],mi[n-i-1]);
	}
	ll ans=0;
	rep(i,n)if(mi[i]!=inf)ans+=n-mi[i];
	cout<<ans<<endl;
	return 0;
}