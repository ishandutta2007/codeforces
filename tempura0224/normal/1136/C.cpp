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
	int n,m;
	cin>>n>>m;
	map<int,int> mp[1010];
	rep(i,n)rep(j,m){
		int x;
		scanf("%d",&x);
		mp[i+j][x]++;
	}
	rep(i,n)rep(j,m){
		int x;
		scanf("%d",&x);
		mp[i+j][x]--;
	}
	rep(i,m+n+1){
		for(auto p :mp[i]){
			if(p.second!=0){
				cout<<"NO"<<endl;
				return 0;
			}
		}
	}
	cout<<"YES"<<endl;
	return 0;
}