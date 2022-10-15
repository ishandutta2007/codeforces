#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, k;
string s;

void flip() {
	for(int i=0; i<n; ++i)
		s[i]^=1;
}

void win1() {
	cout << "tokitsukaze";
	exit(0);
}

void win2() {
	cout << "quailty";
	exit(0);
}

void chk1win() {
	int l=0, r=n-1;
	while(l<n&&s[l]&1)
		++l;
	while(~r&&s[r]&1)
		--r;
	if(r-l+1<=k)
		win1();
}

bool test1(string t) {
	for(int i=0; i<k; ++i)
		t[i]='1';
	int l=0, r=n-1;
	while(l<n&&t[l]&1)
		++l;
	while(~r&&t[r]&1)
		--r;
	return r-l+1<=k;
}

bool chk2win() {
	int l=0, r=n-1;
	while(s[l]&1)
		++l;
	while(s[r]&1)
		--r;
	if(r-l+1>=k+2)
		return 0;
	string t=s;
	bool b1=test1(t);
	reverse(t.begin(), t.end());
	bool b2=test1(t);
	return b1&&b2;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k >> s;
	chk1win();
	flip();
	chk1win();
	bool b1=chk2win();
	flip();
	bool b2=chk2win();
	if(b1&&b2)
		win2();
	cout << "once again";
}