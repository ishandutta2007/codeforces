#include <bits/stdc++.h>
using namespace std;

#define ll long long

string a, b;
int cntA[10];

string solve(int i, bool smaller) {
	if(i>=b.size())
		return "";
	if(!smaller&&cntA[b[i]-'0']) {
		--cntA[b[i]-'0'];
		string c=solve(i+1, 0);
		++cntA[b[i]-'0'];
		if(c!="fk")
			return b[i]+c;
	}
	for(int j=smaller?9:b[i]-'0'-1; j>=0; --j) {
		if(!cntA[j])
			continue;
		--cntA[j];
		string c=solve(i+1, 1);
		++cntA[j];
		if(c!="fk")
			return (char)((char)j+'0')+c;
	}
	return "fk";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> a >> b;
	if(a.size()<b.size()) {
		sort(a.begin(), a.end(), greater<int>());
		cout << a;
	} else {
		for(char c : a)
			++cntA[c-'0'];
		cout << solve(0, 0);
	}
}