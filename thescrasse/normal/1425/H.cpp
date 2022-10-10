#include<bits/stdc++.h>
using namespace std;

int main(){
	int t; cin >> t;
	while(t--){
		int a, b, c, d; cin >> a >> b >> c >> d;
		int aa=1, ab=1, ac=1, ad=1;
		if((a+b) & 1) ac = ad = 0; else aa = ab = 0;
		if(a+d == 0) aa = ad = 0;
		if(b+c == 0) ab = ac = 0;
		cout << (aa? "Ya" : "Tidak") << " ";
		cout << (ab? "Ya" : "Tidak") << " ";
		cout << (ac? "Ya" : "Tidak") << " ";
		cout << (ad? "Ya" : "Tidak") << "\n";
	}
}