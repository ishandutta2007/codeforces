#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,ssse3,sse3,sse4,popcnt,avx,mmx,abm,tune=native")
#include <bits/stdc++.h>
using namespace std;

string s;
int n, k, i, d[100005];

int main(){
	cin >> n >> k >> s;
	for(i=0;i<s.size()-1&&k;i++){
		if(i<0) continue;
		if(s[i]=='4'&&s[i+1]=='7'){
			if(d[i]){
				if(k%2&&i%2) s[i]='7';
				else if(k%2) s[i+1]='4';
				break;
			}
			d[i] = 1; k--;
			if(i%2) s[i] = '7',i-=2;
			else s[i+1] = '4';
		}
	}
	cout << s << endl;
	return 0;
}