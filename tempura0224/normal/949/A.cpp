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
	int n = s.size();
	vector<vector<int>> a(n);
	deque<int> one,zero;
	rep(i,n)one.push_back(i);
	rep(i,n){
		if(s[i]=='0'){
			if(one.empty()){
				cout<<-1<<endl;
				return 0;
			}
			a[one[0]].push_back(i+1);
			zero.push_front(one[0]);
			one.pop_front();
		}
		else {
			if(zero.empty()){
				cout<<-1<<endl;
				return 0;
			}
			a[zero[0]].push_back(i+1);
			one.push_front(zero[0]);
			zero.pop_front();	
		}
	}
	int ans = 0;
	while(ans<n&&!a[ans].empty())++ans;
	rep(i,ans){
		if(a[i].size()%2==0){
			cout<<-1<<endl;
			return 0;
		}
	}
	cout<<ans<<endl;
	rep(i,ans){
		cout<<a[i].size();
		for(auto e:a[i])cout<<" "<<e;
		cout<<endl;
	}
	return 0;
}