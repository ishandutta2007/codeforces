//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,tune=native")
#include<bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(),(x).end()
#define I(x, a) for(auto x : (a))
#define ins insert
#define F(i, l, r) for(auto i = (l); i < (r); i++)
#define DF(i, l, r) for(auto i = (l); i >= (r); i--)
#define E(i, l, r) for(auto i = (l); i <= (r); i++)
#define pb push_back
#define X first
#define Y second
#define mp make_pair
#define ret return
#define brk break
#define cont continue
#define move fjgjgjgjghd

typedef long long ll;
typedef long double dbl;
typedef pair<int, int> pii;

class Out{
public:
	virtual void out(int x, int y) = 0;
};

class SOut : public Out{
public:
	void out(int x, int y){
		cout << x << ' ' << y << '\n';
	}
};

class ROut : public Out{
public:
	void out(int x, int y){
		cout << y << ' ' << x << '\n';
	}
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	Out * o;
	if(n >= m)
		o = (Out*)new SOut;
	else{
		swap(n, m);
		o = (Out*)new ROut;
	}
	if(m == 0){
		o->out(1, 0);
		o->out(n, 0);
		o->out(0, 0);
		o->out(n - 1, 0);
		return 0;
	}
	if(m <= 3){
		o->out(0, 0);
		o->out(n, m);
		o->out(0, m);
		o->out(n, 0);
		return 0;
	}
	o->out(0, m - 1);
	o->out(n, 0);
	o->out(0, m);
	o->out(n, 1);
	return 0;
}