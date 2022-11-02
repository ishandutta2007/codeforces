#include<bits/stdc++.h>

using namespace std;
typedef long long lint;
typedef long double ldb;
typedef unsigned long long uli;

#define X first
#define Y second
#define F(i, l, r) for(int i = l; i != r; i++)
#define Df(i, l, r) for(auto i = l; i != r; i--)
#define uF(i, l, r) for(i = l; i != r; i++)
#define uDf(i, l, r) for(i = l; i != r; i--)
#define I(a, x) for(auto a : x)
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
#define acpy(y, x) memcpy(y, x, sizeof(y))
#define y1 adjf
#define tm fjfjfk
#define cset fhjfghjgfh

const int MAXN = 1e6 + 666;

string s;
int n;
int kek[MAXN];
int ptr = 0;
char sgn[2 * MAXN];
int base[2 * MAXN];
int tot = 0;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> s;
	n = (int)s.length();
	if(n == 1){
		cout << "1\n+2^0";
		ret 0;
	}
	int cu = n;
	int bg = 0;
	F(i, 1, n){
		if(s[bg] != s[i]){kek[ptr++] = i - bg; bg = i;}
	}
	kek[ptr++] = n - bg;
	if(s.back() == '1')kek[ptr++] = 0;
	string csgn = "+";
	bool was1 = false;
	bool carry_that_shit = false;
	F(i, 0, ptr){
//		printf("At %d cu = %d\n", i, cu);
		if(carry_that_shit){
			if(csgn == "+"){
				csgn = "-"; cu -= kek[i]; cont;
			}
			else{
				csgn = "+";
				if(kek[i] == 0)cont;
				if(kek[i] == 1){if(i == ptr - 1){carry_that_shit = false; cu++; }sgn[tot]='-'; base[tot] = cu - 1; tot++; cu -= kek[i]; cont;}
				carry_that_shit = false;
				tot++;
				sgn[tot-1] = '-'; base[tot-1] = cu;
				cu -= kek[i];
				cont;
			}
		}
		if(csgn == "+" && kek[i] == 1){
			tot++;
			sgn[tot-1] = '+'; base[tot-1] = cu-1;
			was1 = true; cu -= kek[i]; csgn = "-"; cont;
		}
		if(csgn == "-" && was1){
			was1 = false; csgn = "+";
			cu -= kek[i];
			cont;
		}
		if(csgn == "-" && kek[i] == 1){
			carry_that_shit = true;
			if(i == ptr - 1){carry_that_shit = false; cu++;}
			tot++; csgn = "+";
			sgn[tot-1] = '-'; base[tot-1] = cu-1;
			cu -= kek[i];
			cont;
		}
		tot++;
		sgn[tot-1] = csgn[0]; base[tot-1] = cu;
		cu -= kek[i];
		if(csgn == "+")csgn = "-"; else csgn = "+";
	}
	if(carry_that_shit){
		sgn[tot] = '-'; base[tot] = 0;
		tot++;
	}
	cout << tot << '\n';
	F(i, 0, tot)cout << sgn[i] << "2^" << base[i] << '\n';
	ret 0;
}