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


int gcd(int x,int y){
	return y?gcd(y,x%y) : x;
}
int main(){
	int n;
	cin>>n;
	string s;
	cin>>s;
	vector<int> ans(n+1);
	int res=0;
	for(int i = 1;  i<=n;++i){
		int g = gcd(i,n);
		if(g!=i){
			res+=ans[g];
			continue;
		}
		int y = g;
		vector<int> cnt(y);
		rep(j,n)cnt[j%y]+=(s[j]=='1');
		ans[i]=1;
		rep(j,y)ans[i]&=(cnt[j]%2==0);
		res+=ans[i];
	}
	cout<<res<<endl;
	return 0;
}