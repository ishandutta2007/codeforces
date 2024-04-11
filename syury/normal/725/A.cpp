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
#define y1 adjf
#define tm afhdhn

string s;
int n;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> s;
	int posl = 0, posr = n - 1;
	while(posl < n && s[posl] == '<')posl++;
	while(posr >= 0 && s[posr] == '>')posr--;
	printf("%d", posl + (n - 1 - posr));
	ret 0;
}