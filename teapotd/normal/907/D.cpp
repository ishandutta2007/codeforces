#pragma GCC optimize("Ofast,no-stack-protector")
#include <bits/stdc++.h>

#define mp make_pair
#define rep(i,b,e)for(int i=(b);i<(e);i++)
#define repd(i,b,e)for(int i=(b);i>=(e);i--)
#define each(a,x)for(auto&a:(x))
#define all(x)(x).begin(),(x).end()
#define sz(x)int((x).size())
#define TM template<class T,class U=int,class...V>
#define DF(t,...)TM auto operator<<(ostream&o,__VA_ARGS__ x)->decltype(t,cout)
#define DD(...)void print(){cerr<<'{';dbgx(#__VA_ARGS__,__VA_ARGS__);cerr<<'}';}
#ifdef LOC
#define dbg(...)(cerr<<"<"<<__LINE__,dbgx("> "#__VA_ARGS__,__VA_ARGS__),cerr<<"\n")
#else
#define dbg(...)
#endif
using namespace std;using namespace rel_ops;using ll=int64_t;using Vi=vector<int>;using Pii=pair<int,int>;
void dbgx(...){}TM void dbgx(T s,U a,V...b){while(*s&&*s!=',')cerr<<*s++;cerr<<": "<<a<<*s++;dbgx(s,b...);}
DF(&T::print,T){x.print();return o;}DF(0,pair<T,U>){return o<<"("<<x.first<<", "<<x.second<<")";}
DF(T().begin(),T){o<<"[";each(e,x)o<<e<<", ";return o<<"]";}

// ----------------------------------------------------------------------------------------------------- //

int hei, wid;
vector<int> board;

inline bool check(int i, int j) {
	i = board[i]; j = board[j];
	if (i > j) swap(i, j);
	return i+1 == j || i+wid == j;
}

bool tryIt() {
	random_shuffle(all(board));

	rep(y, 0, hei) {
		int i = y*wid;
		rep(x, 1, wid) if (check(i+x-1, i+x)) return false;

		if (y > 0) {
			rep(x, 0, wid) if (check(i+x-wid, i+x)) return false;
		}
	}

	cout << "YES\n";
	rep(i, 0, sz(board)) {
		cout << board[i] << " ";
		if ((i+1) % wid == 0) cout << endl;
	}
	return true;
}

void checkDet() {
	int oy = 1;
	cout << "YES\n";

	rep(y, 0, hei) {
		int ox = 1;

		rep(x, 0, wid) {
			cout << (oy-1)*wid + ox << " ";
			ox += 2;
			if (ox > wid) ox = 2;
		}

		oy += 2;
		if (oy > hei) oy = 2;
		cout << endl;
	}
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	cin >> hei >> wid;
	board.resize(hei*wid);
	iota(all(board), 1);

	if (wid >= 6 && hei >= 6) {
		checkDet();
		return 0;
	}

	while (clock() < CLOCKS_PER_SEC) if (tryIt()) return 0;
	cout << "NO\n";
	return 0;
}