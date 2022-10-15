#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ar array
 
int k;
string s;
vector<int> v;
 
bool chk(int x) {
	int nl=1, cl=0;
	for(int i=0; i<v.size(); ++i) {
		if(cl+v[i]+(i<v.size()-1)>x) {
			++nl;
			cl=0;
		}
		cl+=v[i]+(i<v.size()-1);
		if(cl>x)
			return 0;
	}
	return nl<=k;
}
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
 
	cin >> k;
	getline(cin, s);
	getline(cin, s);
	//cout << s;
	int i=0;
	while(i<s.size()) {
		int j=i;
		while(j<s.size()&&s[j]^'-'&&s[j]^' ')
			++j;
		v.push_back(j-i);
		i=j+1;
		//cout << v.back() << endl;
	}
	int lb=1, rb=1e6;
	while(lb<rb) {
		int mb=(lb+rb)/2;
		if(chk(mb))
			rb=mb;
		else
			lb=mb+1;
	}
	cout << lb;
}