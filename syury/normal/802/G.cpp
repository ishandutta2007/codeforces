#include<bits/stdc++.h>

#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx") 

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
#define acpy(y, x) memcpy(y, x, sizeof(y))
#define y1 adjf
#define tm dhgdg

const int MAXN = 1e3 + 3;

int n;
bool dp[MAXN][10];
string s;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> s;
	n = (int)s.length();
	string kek = "heidi";
	fi0(dp);
	F(i, 0, n){
		F(j, 0, 5){
			if(s[i] != kek[j])cont;
			if(j > 0){
				bool good = false;
				F(k, 0, i)if(dp[k][j - 1]){good = true; brk;}
				if(!good)cont;
			}
			dp[i][j] = true;
		}
	}
	F(i, 0, n)if(dp[i][4]){cout << "YES"; ret 0;}
	cout << "NO";
	ret 0;
}