#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef long long ll;
int n;
vector<pair<pair<int,int>,int> >up,dn;
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1; i<=n ;i++){
		int a,b;cin >> a >> b;
		if(a<b) up.push_back({{a,b},i});
		else dn.push_back({{b,a},i});
	}
	sort(up.begin(),up.end());
	sort(dn.begin(),dn.end());
	reverse(up.begin(),up.end());
	if(up.size()>dn.size()){
		cout << up.size() << '\n';
		for(auto cur:up) cout << cur.se << ' ';
		cout << endl;
	}
	else{
		cout << dn.size() << '\n';
		for(auto cur:dn) cout << cur.se << ' ';
		cout << endl;
	}
}