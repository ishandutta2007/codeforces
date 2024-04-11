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
#define y1 adjf
#define ws wejgnjn
#define left fhgfj

int n, m;
vector<int> atk, def;
vector<int> t;

char gett(){
	char c = getc(stdin);
	while(!isalpha(c))
		c = getc(stdin);
	ret c;
}

void skip(){
	char c = getc(stdin);
	while(isalpha(c))
		c = getc(stdin);
}

set<pair<int, int> > left;

int main(){
	scanf("%d%d", &n, &m);
	F(i, 0, n){
		char tp = gett(); skip();
		int val;
		scanf("%d", &val);
		if(tp == 'A')atk.pb(val);
		else def.pb(val);
	}
	sort(all(atk)); sort(all(def));
	t.rs(m);
	F(i, 0, m)
		scanf("%d", &t[i]);
	int ans1 = 0, ans2 = 0;
	//Destroying all
	bool fail = false;
	F(i, 0, m)
		left.ins(mk(t[i], i));
	F(i, 0, (int)def.size()){
		auto it = left.upper_bound(mk(def[i], m + 1));
		if(it == left.end())fail = true;
		else{left.era(it);}
	}
	F(i, 0, (int)atk.size()){
		auto it = left.lower_bound(mk(atk[i], 0));
		if(it == left.end())fail = true;
		else{ans2 += it->X - atk[i]; left.era(it);}
	}
	I(u, left){
		ans2 += u.X;
	}
	//Only atk
	sort(all(t)); reverse(all(t));
	int ptr = 0;
	I(u, atk){
		if(ptr == m || t[ptr] < u)cont;
		ans1 += t[ptr] - u; ptr++;
	}
	if(!fail && ans2 > ans1)ans1 = ans2;
	printf("%d", ans1);
	ret 0;
}