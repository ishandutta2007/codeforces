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
	int n;
	cin>>n;
	deque<int> a,b;
	rep(i,n){
		int x;
		cin>>x;
		if(x)a.push_back(x);
	}
	rep(i,n){
		int x;
		cin>>x;
		if(x)b.push_back(x);
	}
	while(b[0]!=a[0]){
		int x = b[0];
		b.pop_front();
		b.push_back(x);
	}
	rep(i,n-1){
		if(b[i]!=a[i]){
			cout<<"NO"<<endl;
			return 0;
		}
	}
	cout<<"YES"<<endl;
	return 0;
}