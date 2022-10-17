#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto &i : a)
#define SZ(i) ((int)(i).size())
#define X first
#define Y second
#define PR std::pair
#define PII std::pair<int, int>
#define MP std::make_pair
#define ll long long
#define VI std::vector<int>

// -----------------------
// copied from http://www.algorytm.org
void Pref( std::vector<int> &P, std::string &S )
{
unsigned int t = 0, i, n = S.size();
P.resize(n+1, 0);
for( i = 2; i < n; i++ )
{
while (t > 0 && S[t + 1] != S[i]) t = P[t];
if( S[t+1] == S[i] ) t++;
P[i] = t;
}
}
int KMP( std::string &T, std::string &W )
{
std::string S = "#" + W + "#" + T;
std::vector<int> P;
Pref(P, S);
unsigned int i, ws = W.size();
for( i = ws + 2; i < S.size(); i++ )
{
if( P[i] == ws ) return i-ws-ws-1;
}
return -1;
}
// -----------------------

int n;
std::vector<PR<std::string, std::string> > A;
std::vector<PII> loh;
std::vector<std::string> wzor, perfect;

void fail(){
	std::cout << "NO\n";
	std::exit(0);
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n;
	std::vector<std::string> xd(n);
	FOR(i, n){
		std::string a;
		std::cin >> a;
		xd[i] = a;
	}
	FOR(i, n){
		std::string a;
		std::cin >> a;
		if(xd[i] == a) perfect.push_back(a);
		else A.push_back(MP(xd[i], a));
	}
	loh.resize(SZ(A));
	wzor.resize(SZ(A));
	FOR(kt, SZ(A)){
		loh[kt] = MP(-1, -1);
		FOR(i, SZ(A[kt].X)) if(A[kt].X[i] != A[kt].Y[i]){
			if(loh[kt].X == -1) loh[kt].X = i;
			loh[kt].Y = i;
		}
		REP(i, loh[kt].X, loh[kt].Y+1) wzor[kt].push_back(A[kt].X[i]);
	}
	REP(i, 1, SZ(wzor)) if(wzor[0] != wzor[i]) fail();
	std::string left = "";
	int move_left = 1;
	while(true){
		if(loh[0].X-move_left < 0) break;
		char chr = A[0].X[loh[0].X-move_left];
		bool bad = false;
		REP(i, 1, SZ(A)){
			if(loh[i].X-move_left < 0){
				bad = true;
				break;
			}
			if(A[i].X[loh[i].X-move_left] != chr){
				bad = true;
				break;
			}
		}
		if(bad) break;
		left.push_back(chr);
		move_left++;
	}
	std::reverse(left.begin(), left.end());
	std::string right = "";
	int move_right = 1;
	while(true){
		if(loh[0].Y+move_right >= SZ(A[0].X)) break;
		char chr = A[0].X[loh[0].Y+move_right];
		bool bad = false;
		REP(i, 1, SZ(A)){
			if(loh[i].Y+move_right >= SZ(A[i].X)){
				bad = true;
				break;
			}
			if(A[i].X[loh[i].Y+move_right] != chr){
				bad = true;
				break;
			}
		}
		if(bad) break;
		right.push_back(chr);
		move_right++;
	}
	std::string big = left + wzor[0] + right;
	move_right--;
	move_left--;
	FOR(i, SZ(A)) if(KMP(A[i].X, big) != loh[i].X-move_left) fail();
	FOR(i, SZ(perfect)) if(KMP(perfect[i], big) != -1) fail();
	std::cout << "YES\n";
	std::cout << big << "\n";
	REP(i, loh[0].X-move_left, loh[0].Y+move_right+1) std::cout << A[0].Y[i];
	return 0;
}