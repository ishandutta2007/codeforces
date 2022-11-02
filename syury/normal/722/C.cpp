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
#define y1 adjf

int n;
set<pair<int, int> > s;
map<lint, int> cnts;
set<lint, greater<lint> > mx;
vector<int> a;
vector<lint> prts;

lint getsum(int l, int r){
	if(l == 0)
		ret prts[r];
	else
		ret prts[r] - prts[l - 1];
}

int main(){
	scanf("%d", &n);
	a.rs(n); s.ins(mk(0, n - 1));
	prts.rs(n);
	lint sum = 0ll;
	F(i, 0, n){
		scanf("%d", &a[i]);
		sum += a[i];
		prts[i] = sum;
	}
	cnts[sum] = 1;
	mx.ins(sum);
	F(i, 0, n){
		int pos;
		scanf("%d", &pos); pos--;
		auto it = s.lower_bound(mk(pos, pos));
		if(it != s.begin()){
			it--;
			if(it->Y < pos){it++;}
		}
		int l = it->X, r = it->Y;
		s.era(it);
		lint cs = getsum(l, r);
		cnts[cs]--;
		if(cnts[cs] == 0){mx.era(cs);}
		if(pos > l){
			cs = getsum(l, pos - 1);
			s.ins(mk(l, pos - 1));
			mx.ins(cs);
			cnts[cs]++;
		}
		if(pos < r){
			cs = getsum(pos + 1, r);
			s.ins(mk(pos + 1, r));
			mx.ins(cs);
			cnts[cs]++;
		}
		if(!mx.empty()){printf("%lld\n", *mx.begin());}
		else{printf("0\n");}
	}
	ret 0;
}