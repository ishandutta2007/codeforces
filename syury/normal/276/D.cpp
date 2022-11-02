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
#define fi0(x) memset(x, 0, sizeof(x))
#define y1 adjf
#define tm afhdhn

const int MAXP = 61;

lint l, r;
lint p1 = 0ll;

lint inter(lint l1, lint r1){
	if(r1 < l || l1 > r){ret 0;}
	ret min(r1, r) - max(l1, l) + 1;
}

int main(){
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	scanf("%lld%lld", &l, &r);
	Df(i, MAXP, -1){
		if((l&(1ll << i)) == (r&(1ll << i))){cont;}
		p1 = (1ll << (i + 1)) - 1;
		brk;
	}
	printf("%lld", p1);
	ret 0;
}