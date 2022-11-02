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

int k;
string s = "";

bool can(int x, int y){
	lint kek = x * 1ll * (x - 1)/2;
	ret kek <= y;
}

int main(){
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	scanf("%d", &k);
	if(k == 0){
		printf("a");
		ret 0;
	}
	char c = 'a';
	while(k > 0){
		int l = 1, r = 1000;
		while(r - l > 1){
			int mid = (l + r)>>1;
			if(can(mid, k))l = mid; else r = mid - 1;
		}
		if(can(r, k))l = r;
		F(i, 0, l)s += c;
		c++;
		k -= l * (l - 1)/2;
	}
	printf("%s", s.c_str());
	ret 0;
}