#include<bits/stdc++.h>

using namespace std;
typedef long long lint;
typedef long double ldb;
typedef unsigned long long uli;

#define X first
#define Y second
#define F(i, l, r) for(auto i = l; i != r; i++)
#define Df(i, l, r) for(auto i = l; i != r; i--)
#define pb push_back
#define rs resize
#define mk make_pair
#define asg assign
#define all(x) x.begin(),x.end()
#define ret return
#define cont continue
#define brk break
#define ins insert
#define era erase
#define y1 adjf

string s;
int n;
bool na = false;
int l, r;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> s;
	n = s.length();
	F(i, 0, n)
		if(s[i] != 'a')
			na = true;
	if(!na){
		s[n - 1] = 'z';
		printf("%s", s.c_str());
		ret 0;
	}
	F(i, 0, n){
		if(s[i] == 'a')
			continue;
		int j = i + 1;
		while(j < n && s[j] != 'a')
			j++;
		l = i;
		r = j - 1;
		brk;
	}
	F(i, l, r + 1){
		s[i]--;
	}
	printf("%s", s.c_str());
	ret 0;
}