#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int qry(string s) {
	cout << s << endl;
	int a;
	cin >> a;
	if(!a)
		exit(0);
	return a;
}

string cv(vector<int> v) {
	string a;
	for(int i=0; i<v.size(); ++i) {
		if(i)
			a+='a';
		for(int j=0; j<v[i]; ++j)
			a+='b';
	}
	return a;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int x=300-qry(cv(vector<int>(301)));
	if(!x) {
		vector<int> v={1};
		while(qry(cv(v)))
			++v[0];
		return 0;
	}
	vector<int> v(x+1);
	int y=qry(cv(v));
	for(int i=0; i<=x; ++i) {
		while(1) {
			++v[i];
			if(qry(cv(v))<y) {
				--y;
				continue;
			}
			--v[i];
			break;
		}
	}
}