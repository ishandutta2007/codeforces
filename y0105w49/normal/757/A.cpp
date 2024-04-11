#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;
#define fi first
#define se second
#define pb push_back

int _main() {
	string S; cin>>S;
	map<char,int> ct;
	for(char c:S) ++ct[c];
	int ans=0;
	const string BULB="Bulbasaur";
	for(;;) {
		for(char c:BULB) {
			if(!ct[c]) return ans;
			--ct[c];
		}
		++ans;
	}
}
int main() {
	cout<<_main()<<endl;
}