//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,ssse3,sse3,sse4,popcnt,tune=native")
#include<bits/stdc++.h>

using namespace std;

#define I(x, a) for(auto x : (a))
#define all(x) (x).begin(),(x).end()
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

typedef long long ll;
typedef long double dbl;
typedef pair<int, int> pii;
typedef unsigned long long ull;

const uint32_t NO = -1;
const int N = (int)1e6;

map<pii, int> id;
uint32_t gr[N];
pii wut[N];
int a, b, n;
int sz = 0;

void calc(pii x){
	int i = id[x];
	pii y = mp(x.X, x.Y + 1);
	pii z = mp(x.X + 1, x.Y);
	uint32_t l, r;
	if(!id.count(y))l = 1;
	else {if(gr[id[y]] == NO)calc(y); l = gr[id[y]];}
	if(!id.count(z))r = 1;
	else {if(gr[id[z]] == NO)calc(z); r = gr[id[z]];}
	if(l > r)swap(l, r);
	if(l){gr[i] = 0; return;}
	if(r > l + 1){gr[i] = l + 1; return;}
	gr[i] = r + 1;
}

int winb(){
	int turn = 0;
	int old = a;
	while(a * 1ll * a < n){
		if(!gr[id[mp(a, 2)]]){turn ^= 1; break;}
		++a;
		turn ^= 1;
	}
	if(a * 1ll * a < n){
		return turn;
	}
	else{
		a = n - old;
		if(a&1)return 0;
		else return 1;
	}
}

int wina(){
	int c = 0;
	while((1<<c) < n)++c;
	if(c <= b)return -1;
	uint32_t pw = 1<<b;
	int turn = 0;
	while(pw < n){
		if(!gr[id[mp(2, b)]]){turn ^= 1; break;}
		++b;
		turn = turn^1;
		pw *= 2;
		if(pw >= (uint32_t)n){turn = -1; break;}
	}
	return turn;
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	fill(gr, gr + N, NO);
	cin >> a >> b >> n;
	for(int i = 2; i * i < n; i++){
		ll j = i * i;
		int pw = 2;
		while(j < n){
			wut[sz] = mp(i, pw);
			id[mp(i, pw)] = sz++;
			++pw;
			j *= i;
		}
	}
	DF(i, sz - 1, 0){
		if(gr[i] == NO)calc(wut[i]);
//		cout << wut[i].X << "^" << wut[i].Y << " " << gr[i] << endl;
	}
	if(a >= 2 && b >= 2){
		if(gr[id[mp(a, b)]])cout << "Masha";
		else cout << "Stas";
		return 0;
	}
	if(a == 1 && b == 1){
		int oa = a, ob = b;
		++b;
		int x = wina();
		a = oa; b = ob;
		++a;
		int y = winb();
		y = 1 - y;
		if(x != -1)x = 1 - x;
		if(x == 1 || y == 1){cout << "Masha";}
		else{
			if(x == -1)cout << "Missing";
			else cout << "Stas";
		}
		return 0;
	}
	if(b == 1){
		int x = winb();
		if(x)cout << "Masha";
		else cout << "Stas";
		return 0;
	}
	if(a == 1){
		int x = wina();
		if(x == 1)cout << "Masha";
		else if (x == -1)cout << "Missing";
		else cout << "Stas";
		return 0;
	}
	return 0;
}