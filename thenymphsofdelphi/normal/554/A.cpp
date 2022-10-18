#include<bits/stdc++.h>
using namespace std;

set <string> a;

int main(){
	string s;
	cin >> s;
	string t;
	for (int i = 0; i <= (int)s.size(); i++){
		for (int j = 0; j < 26; j++){
			t.clear();
			for (int p = 0; p < i; p++){
				t.push_back(s[p]);
			}
			t.push_back('a' + j);
			for (int p = i; p < (int)s.size(); p++){
				t.push_back(s[p]);
			} 
			a.insert(t);
		}
	}
	cout << a.size();
}