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


int gcd(int x,int y){
	if(x<y)swap(x,y);
	return y==0?x:gcd(y,x%y);
}
int main(){
	int n;
	cin>>n;
	map<pair<int,int>,int> mp;
	int a[n],b[n];
	rep(i,n)cin>>a[i];
	rep(i,n)cin>>b[i];
	int cnt=0;
	rep(i,n){
		if(a[i]==0){
			if(b[i]==0)++cnt;
			continue;
		}
		int g=gcd(abs(a[i]),abs(b[i]));
		if(a[i]<0){
			a[i]=-a[i];
			b[i]=-b[i];
		}
		mp[{a[i]/g, b[i]/g}]++;
	}
	int ans=0;
	for(auto p : mp){
		ans=max(ans,p.second);
	}
	cout<<ans+cnt<<endl;
	return 0;
}