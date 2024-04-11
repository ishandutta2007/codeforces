#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; a++)
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " << 

using namespace std;
typedef long long ll;

set<int> alpaca;
map<int,int> vec;
vector<int> vcs[200020];
int main() {
	int n;
	int k=0;
	cin>>n;
	fr(i,0,n){
		int a;
		cin>>a;
		auto it=alpaca.lower_bound(-a);
		if(it==alpaca.end()){
			alpaca.insert(-a);
			vec[a]=k;
			vcs[k++].push_back(a);
		}else{
			int x=*it;
			vcs[vec[-x]].push_back(a);
			vec[a]=vec[-x];
			alpaca.erase(it);
			alpaca.insert(-a);
		}
		
	}
	fr(i,0,k){
		for(auto x: vcs[i])cout<<x<<" ";
		cout<<endl;
	}
}