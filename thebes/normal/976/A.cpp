#include <bits/stdc++.h>
using namespace std;
int fnd, i, cnt;
string s;
int main(){
	cin >> s >> s;
	for(char ch : s)
		(ch=='1')? fnd=1:cnt++;
	if(fnd) cout<<'1';
	while(cnt--) cout<<'0';
	return 0;
}