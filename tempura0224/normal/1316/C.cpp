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
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	int n,m,p;
	cin>>n>>m>>p;
	vector<int> a(n);
	vector<int> b(m);
	rep(i,n)cin>>a[i];
	rep(i,m)cin>>b[i];
	int i=0,j=0;
	while(a[i]%p==0)++i;
	while(b[j]%p==0)++j;
	cout<<i+j<<endl;
	return 0;
}