#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define array a

string s;
int n;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> s;
	n=s.size();
	s+='b';
	for(int i=0; i<n; ++i)
		cout << (s[i]!=s[i+1]) << " ";
}