#include <bits/stdc++.h>
using namespace std;

int n,q;
map<string,string> ops;

int go(int on, string s) {
	if (on==n) {
		while (true) {
			if (s.size()==1) return (s[0]=='a');
			string t;
			t = t+s[0]+s[1];
			if (ops.count(t)) {
				s.erase(s.begin());
				s.erase(s.begin());
				s = ops[t]+s;
			} else return 0;
		}
	} else {
		int res = 0;
		for (char c='a';c<='f';c++) {
			res+=go(on+1,s+c);
		}
		return res;
	}
}

int main() {
	scanf("%d%d",&n,&q);
	for (int i=0;i<q;i++) {
		string a,b;
		cin >> a >> b;
		ops[a] = b;
	}
	printf("%d\n",go(0,""));

	return 0;
}