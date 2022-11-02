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
#define acpy(y, x) memcpy(y, x, sizeof(y))
#define y1 adjf
#define tm dhgdg

const ldb eps = 1e-9;

struct pt{
	int x, y;
	void get(){
	    cin >> x >> y;
	}
};

struct line{
	lint a, b, c;
	line(){}
	line(const pt & p1, const pt & p2){
		a = p2.y - p1.y;
		b = p1.x - p2.x;
		c = -a * 1ll * p1.x - b * 1ll * p1.y;
	}
	ldb dist(const pt & p){
		ret llabs(a * p.x + b * p.y + c)/sqrt((ldb)(a * a + b * b));
	}
};

lint dist(const pt & a, const pt & b){
	ret (a.x - b.x) * 1ll * (a.x - b.x) + (a.y - b.y) * 1ll * (a.y - b.y);
}

const int MAXN = 1e3 + 3;

pt p[MAXN];
int n;
ldb ans = 2e18;

void upd(const ldb & x){
	if(ans - x > eps)ans = x;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	F(i, 0, n)p[i].get();
	F(i, 0, n){
		int j = (i + 1)%n;
		line bs(p[i], p[j]);
		F(k, 0, n){
			if(k == i || k == j)cont;
			line li(p[j], p[k]), lj(p[i], p[k]), lk(p[j], p[i]);
			upd(li.dist(p[i])/2); upd(lj.dist(p[j])/2); upd(lk.dist(p[k])/2);
		}
	}
	cout.precision(15);
	cout << ans;
	ret 0;
}