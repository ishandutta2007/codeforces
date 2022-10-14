#include <bits/stdc++.h>
using namespace std;


int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    vector<string> pos;
    // 26^3=1000
    for(int i = 0; i < 26; i++) {
		string v;
		v += 'a' + i;
		pos.push_back(v);
	}
    for(int i = 0; i < 26; i++) {
		for(int j = 0; j < 26; j++) {
			string v;
			v += 'a' + i;
			v += 'a' + j;
			pos.push_back(v);
		}
	}
    for(int i=0;i<26;i++) {
		for(int j=0;j<26;j++) {
			for(int k=0;k<26;k++) {
				string v;
				v += 'a' + i;
				v += 'a' + j;
				v += 'a' + k;
				pos.push_back(v);
			}
		}
	}
	
	
	int t;
	cin >> t;
	while(t--) {
		int n; cin >> n;
		string x; cin >> x;
		int l = 0;
		vector<string> v;
		for(int i = 0; i < int(x.size()); i++) {
			string a;
			for(int j = 0; j < 3 && i + j < int(x.size()); j++) {
				a += x[i + j];
				v.push_back(a);
			}
		}
		sort(v.begin(), v.end(), [](const auto a, const auto b) {
			return a.size()==b.size()?a<b:a.size()<b.size();
		});
		
		for(string t : v) {
			if(t == pos[l]) {
				++l;
			}
		}
		
		cout << pos[l] << "\n";
	}
}