#include<bits/stdc++.h>

using namespace std;
typedef long long lint;
typedef long double ldb;
typedef unsigned long long uli;

#define X first
#define Y second
#define F(i, l, r) for(auto i = l; i != r; i++)
#define Df(i, l, r) for(auto i = l; i != r; i--)
#define I(i, a) for(auto i : a)
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
#define fi0(x) memset(x, 0, sizeof(x))
#define finf(x) memset(x, 127, sizeof(x))
#define y1 adjf
#define tm afhdhn

string s;
int n;
vector<int> len;
int tm = 0;

int main(){
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> s;
	reverse(all(s));
	n = s.length();
	len.rs(n);
	Df(i, n - 1, -1){
		if(s[i] == 'M')len[i] = 0;
		else len[i] = 1 + ((i == n - 1) ? 0 : len[i + 1]);
	}
	int curr = -1;
	bool open = false;
	F(i, 0, n){
		if(s[i] == 'M'){
			if(curr != -1)tm++;
			open = false;
			cont;
		}
		if(open)cont;
		if(i + len[i] >= n)brk;
		curr += len[i]; open = true;
		if(curr > tm)tm = curr;
	}
	printf("%d", tm);
	ret 0;
}