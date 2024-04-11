#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	//freopen("in.txt", "r", stdin);
	int n,idx=0;
	string s;
	cin >> n >> s;
	for(int i=0,len=s.size();i<len-1;++i,++idx) {
		if(s[i]>s[i+1]) break;
	}
	for(int i=0,len=s.size();i<len;++i) {
		if(i!=idx) cout<<s[i];
	}
	cout << "\n";
}