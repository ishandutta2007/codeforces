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

int n;
vector<int> p;
vector<string> s;

auto vo = [](char c)->bool{
			ret (c == 'a') || (c == 'o') || (c == 'e') || (c == 'i') || (c == 'u') || (c == 'y');
		};

int main(){
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	p.rs(n); s.rs(n);
	F(i, 0, n)
		cin >> p[i];
	cin.get();
	F(i, 0, n){
		getline(cin, s[i]);
		F(j, 0, (int)s[i].length())
			if(vo(s[i][j])){p[i]--;}
		if(p[i] != 0){printf("NO"); ret 0;}
	}
	printf("YES");
	ret 0;
}