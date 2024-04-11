#include <bits/stdc++.h>
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define rep(i,b,e)for(int i=(b);i<(e);i++)
#define repd(i,b,e)for(int i=(b);i>=(e);i--)
#define each(a,x)for(auto&a:(x))
#define all(x)(x).begin(),(x).end()
#define sz(x)int((x).size())
#define tem template<class t,class...g>
#define D DD()
#define pri(k)tem auto p(t a,ll)->decltype(a.k,z()){D
#define DBP(...)void print(){D.x("{"#__VA_ARGS__,__VA_ARGS__);D,"}";}
#ifdef LOC
#define deb(...)((D,"<",__LINE__,"> ").x(#__VA_ARGS__,__VA_ARGS__),D,"\n")
#else
#define deb(...)
#endif
using namespace std;using namespace rel_ops;using ll=long long;using Vi=vector<int>;
using Pii=pair<int,int>;struct DD{using z=void;z x(...){}tem z p(t a,...){cerr<<a;}
tem DD&operator,(t a){p(a,0);return*this;}pri(first),"(",a.first,", ",a.second,")";}
tem z x(const char*s,t a,g...k){while(*s&&*s!=',')D,*s++;D,": ",a,*s++;x(s,k...);}
pri(print());a.print();}pri(begin()),"[";each(k,a)D,k,", ";D,"]";}};

// ------------------------------------------------------------------------------------------ //

int hei, wid;
vector<string> board;
vector<Pii> moves;
string order;
Pii start;

bool check() {
	int x = start.second, y = start.first;

	each(cmd, order) {
		Pii dir = moves[cmd-'0'];
		x += dir.second;
		y += dir.first;
		if (x < 0 || y < 0 || x >= wid || y >= hei) return false;

		if (board[y][x] == '#') return false;
		if (board[y][x] == 'E') return true;
	}
	return false;
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	cin >> hei >> wid;
	board.resize(hei);
	each(s, board) cin >> s;

	cin >> order;

	moves.pb({ 1, 0 });
	moves.pb({ -1, 0 });
	moves.pb({ 0, 1 });
	moves.pb({ 0, -1 });

	sort(all(moves));
	int ret = 0;

	rep(y, 0, hei) rep(x, 0, wid) {
		if (board[y][x] == 'S') start = mp(y, x);
	}

	do {
		if (check()) ret++;
	} while (next_permutation(all(moves)));

	cout << ret << endl;
	return 0;
}