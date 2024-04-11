#include <bits/stdc++.h>

using namespace std;

#define I(x, a) for(auto x : a)
#define F(i, l, r) for(auto i = l; i != r; i++)
#define Df(i, l, r) for(auto i = l; i != r; i--)
#define fi0(x) memset((x), 0, sizeof(x))
#define ins insert
#define era erase
#define ret return
#define cont continue
#define mk make_pair
#define X first
#define Y second
#define brk break

typedef long long int lint;
const int MAXN = 2e5 + 5;

int n;
string s;
int mask[MAXN];

bool check(int kek){
	int bishkek = 0;
	while(kek){
		bishkek += kek%10;
		kek /= 10;
	}
	kek = 0;
	while(bishkek){
		kek += bishkek%10;
		bishkek /= 10;
	}
	ret kek <= 9;
}

int buf[MAXN];

void out(int kek){
	F(i, 0, n){
		if(mask[i])cout << '+';
		cout << s[i];
	}
	cout << '\n';
	int ptr = 0;
	int bishkek = 0;
	while(kek){
		buf[ptr] = kek%10;
		bishkek += buf[ptr++];
		kek /= 10;
	}
	Df(i, ptr - 1, -1){if(i != ptr-1)cout<<'+'; cout<<buf[i];}
	cout<<'\n';
	ptr = 0;
	while(bishkek){
		buf[ptr++] = bishkek%10;
		bishkek /= 10;
	}
	Df(i, ptr - 1, -1){if(i != ptr-1)cout<<'+'; cout<<buf[i];}
	cout<<'\n';
	exit(0);
}

void fail(){
	while(true){
		if(s.back() == '?')brk;
		s += 'a';
		s += (rand()&1) ? '!' : '@';
		s.pop_back();
	}
}

int next_bg(int seg){
	int v = (rand()<<15) + rand();
	v %= 3;
	if(v==0)ret seg + 1;
	if(v==1)ret seg + 2;
	ret seg + 3;
}

string a, b, c;
const int vars = 50;

int main(){
	//freopen("t.in", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	cin >> s;
	F(i, 1, n)mask[i] = 1;
	int kek = 0;
	F(i, 0, n)kek += s[i] - '0';
	if(check(kek))out(kek);
	int b1 = n/3, b2 = n - b1;
	a = s.substr(0, b1);
	b = s.substr(b1, b2 - b1 + 1);
	c = s.substr(b2);
	srand(time(NULL));
	int seg = 0, tail = 0;
	bool must;
	F(v1, 0, vars){
		int kek1 = 0;
		must = true; tail = 0;
		F(i, 0, b1)mask[i] = 0;
		F(i, 0, b1){
		if(must){
			if(i != 0)mask[i] = 1;
			tail = 0; seg = next_bg(i);
			must = false;
		}
		tail = tail * 10 + s[i] - '0';
		if(seg == i + 1){
			must = true;
			kek1 += tail;
			tail = 0;
		}}
		kek1 += tail;
		F(v2, 0, vars){int kek2 = 0;
			must = true; tail = 0;
			F(i, b1, b2)mask[i] = 0;
			F(i, b1, b2){
			if(must){
			if(i != 0)mask[i] = 1;
			tail = 0; seg = next_bg(i);
			must = false;
		}
		tail = tail * 10 + s[i] - '0';
		if(seg == i + 1){
			must = true;
			kek2 += tail;
			tail = 0;
		}}kek2 += tail;
			F(v3, 0, vars){int kek3 = 0;
				must = true; tail = 0;
				F(i, b2, n)mask[i] = 0;
				F(i, b2, n){
					if(must){
			if(i != 0)mask[i] = 1;
			tail = 0; seg = next_bg(i);
			must = false;
		}
		tail = tail * 10 + s[i] - '0';
		if(seg == i + 1){
			must = true;
			kek3 += tail;
			tail = 0;
		}
				}kek3 += tail;
				if(check(kek1 + kek2 + kek3))out(kek1 + kek2 + kek3);
			}
		}
	}
	fail();
	ret 0;
}