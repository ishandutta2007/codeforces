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
constexpr int inf=1e9+7;
constexpr ll longinf=1LL<<60 ;
constexpr ll mod=1e9+7 ;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;cin>>n;
		string s;cin>>s;
		char c = 'z'+1;
		string ans = "";
		ans += c;
		int ret = -1;
		REP(i,1,n+1){
			string res = s.substr(i-1);
			string t = s.substr(0,i-1);
			if((n+1-i)%2)reverse(t.begin(),t.end());
			res += t;
			if(res<ans){
				ans = res;
				ret = i;
			}
		}
		cout<<ans<<endl;
		cout<<ret<<endl;
	}
	return 0;
}