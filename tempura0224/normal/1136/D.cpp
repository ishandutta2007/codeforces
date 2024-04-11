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
	int a[n];
	rep(i,n)scanf("%d",&a[i]);
	rep(i,n)--a[i];
	reverse(a,a+n);
	vector<int> v[n];
	rep(i,m){
		int x,y;
		scanf("%d%d",&x,&y);
		--x;--y;
		v[x].push_back(y);
	}
	set<int> st;
	st.insert(a[0]);
	int ans=0;
	REP(i,1,n){
		int cnt=st.size();
		for(auto x : v[a[i]]){
			if(st.count(x))--cnt;
		}
		if(cnt)st.insert(a[i]);
		else ++ans;
	}
	cout<<ans<<endl;
	return 0;
}