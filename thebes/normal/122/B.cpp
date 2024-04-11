#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,ssse3,sse3,sse4,popcnt,avx,mmx,abm,tune=native")
#include <bits/stdc++.h>
using namespace std;

string s;
int cnt1, cnt2;

int main(){
	cin >> s;
	for(char c : s){
		if(c=='4') cnt1++;
		else if(c=='7') cnt2++;
	}
	if(!cnt1&&!cnt2) printf("-1\n");
	else printf("%d\n",(cnt1>=cnt2)?4:7);
	return 0;
}