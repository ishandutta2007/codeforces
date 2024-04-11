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
#define ws wejgnjn
#define left fhgfj

struct pt{
	lint x, y;
	pt(){}
	pt(lint px, lint py):x(px), y(py){}
	void get(){scanf("%lld%lld", &x, &y);}
};

pt operator + (const pt & a, const pt & b){
	ret pt(a.x + b.x, a.y + b.y);
}

pt operator - (const pt & a, const pt & b){
	ret pt(a.x - b.x, a.y - b.y);
}

lint operator ^ (const pt & a, const pt & b){
	ret a.x * b.y - a.y * b.x;
}

vector<pt> sum(vector<pt> & a, vector<pt> & b){
	vector<pt> c;
	int li = 0, lj = 0;
	int n = a.size(), m = b.size();
	F(i, 1, n)if(a[i].y < a[li].y || (a[i].y == a[li].y && a[i].x < a[li].x))li = i;
	F(j, 1, m)if(b[j].y < b[lj].y || (b[j].y == b[lj].y && b[j].x < b[lj].x))lj = j;
	rotate(a.begin(), a.begin() + li, a.end());
	rotate(b.begin(), b.begin() + lj, b.end());
	a.pb(a[0]); b.pb(b[0]);
	a.pb(a[1]); b.pb(b[1]);
	int i = 0, j = 0;
	while(i < n || j < m){
		c.pb(a[i] + b[j]);
		if(((a[i + 1] - a[i]) ^ (b[j + 1] - b[j])) > 0)i++;
		else if(((a[i + 1] - a[i]) ^ (b[j + 1] - b[j])) < 0)j++;
		else {i++; j++;}
	}
	ret c;
}

int n, m, k;
vector<pt> a, b, c, s, t;

void prepare(){
	n = s.size();
	int li = 0;
	F(i, 1, n)if(s[i].x < s[li].x || (s[i].x == s[li].x && s[i].y < s[li].y))li = i;
	rotate(s.begin(), s.begin() + li, s.end());
}

bool inside(pt p){
	if(p.x == s[0].x && p.y == s[0].y)ret true;
	if(((s[n - 1] - s[0]) ^ (p - s[0])) > 0)ret false;
	if(((p - s[0]) ^ (s[1] - s[0])) > 0)ret false;
	int l = 1, r = n - 1;
	while(r - l > 1){
		int mid = (l + r) >> 1;
		if(((s[mid] - s[0]) ^ (p - s[0])) > 0)l = mid;
		else r = mid - 1;
	}
	if(((s[r] - s[0]) ^ (p - s[0])) > 0)l = r;
	lint la = s[l + 1].y - s[l].y;
	lint lb = s[l].x - s[l + 1].x;
	lint lc = -la * s[l].x - lb * s[l].y;
	lint f0 = la * s[0].x + lb * s[0].y + lc;
	lint fp = la * p.x + lb * p.y + lc;
	if(f0 < 0 && fp > 0)ret false;
	if(f0 > 0 && fp < 0)ret false;
	ret true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	scanf("%d", &n);
	a.rs(n);
	F(i, 0, n)a[i].get();
	scanf("%d", &m);
	b.rs(m);
	F(i, 0, m)b[i].get();
	scanf("%d", &k);
	c.rs(k);
	F(i, 0, k)c[i].get();
	t = sum(a, b);
	s = sum(t, c);
	prepare();
	int q;
	scanf("%d", &q);
	F(i, 0, q){
		pt p;
		p.get();
		p.x *= 3; p.y *= 3;
		if(inside(p))printf("YES\n");
		else printf("NO\n");
	}
	ret 0;
}