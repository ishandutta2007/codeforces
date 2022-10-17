#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, n) for(auto &i : n)
#define SZ(x) (int)(x).size()
#define PR std::pair
#define MP std::make_pair
#define X first
#define Y second
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;


int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n, k;
	std::cin >> n >> k;
	std::string s;
	std::cin >> s;
	VI A(n);
	FOR(i, n) A[i] = (int)(s[i] == 'B');
	int roz = -1;
	FOR(i, n){
		if(A[i] == A[(i+1)%n]){
			roz = (i+1)%n;
			break;
		}
	}
	if(roz == -1){
		if(k%2 == 0){
			std::cout << s << "\n";
		}else{
			FOR(i, n) s[i] = (s[i] == 'B' ? 'W' : 'B');
			std::cout << s << "\n";
		}
		return 0;
	}
	VI xd;
	FOR(i, n) xd.push_back(A[(roz+i)%n]);
	A = xd;
	std::vector<bool> safe(n);
	safe[0] = true;
	safe[n-1] = true;
	FOR(i, n-1){
		if(A[i] == A[i+1]) safe[i] = true, safe[i+1] = true;
	}
	//FOR(i, n) std::cout << (A[i] == 1 ? 'B' : 'W');
//	std::cout << "\n";
//	FOR(i, n) std::cout << (int)safe[i];
//	std::cout << "\n";
	VI gap(n);
	for(int i = n-2; i >= 0; --i){
		if(!safe[i]) gap[i] = gap[i+1]+1;
	}
	VI ans(n);
	int pos = 0;
	while(pos < n){
		if(safe[pos]){
			ans[pos] = A[pos];
			pos++;
			continue;
		}
		if(gap[pos] % 2 == 1){
			int wut = A[(pos+n-1)%n];
			int from = pos+k;
			int to = pos+gap[pos]-1-k;
			if(from > to){
				while(!safe[pos]){
					ans[pos] = wut;
					pos++;
				}
			}else{
				while(pos < from){
					ans[pos] = wut;
					pos++;
				}
				while(pos <= to){
					ans[pos] = ((pos-from)%2 == 0 ? 1-wut : wut);
					pos++;
				}
				while(!safe[pos]){
					ans[pos] = wut;
					pos++;
				}
			}
		}else{
			int lef = A[(pos+n-1)%n];
			int rig = A[(pos+gap[pos])%n];
			int from = pos+k;
			int to = pos+gap[pos]-1-k;
			if(from > to){
				int st = pos;
				while(!safe[pos]){
					ans[pos] = (pos-st >= gap[st]/2 ? rig : lef);
					pos++;
				}
			}else{
				while(pos < from){
					ans[pos] = lef;
					pos++;
				}
				while(pos <= to){
					ans[pos] = ((pos-from)%2 == 0 ? 1-lef : lef);
					pos++;
				}
				while(!safe[pos]){
					ans[pos] = rig;
					pos++;
				}
			}
		}
	}
	//FOR(i, n) std::cout << (ans[i] == 1 ? 'B' : 'W');
	//std::cout << "\n";
	FOR(i, n) std::cout << (ans[(i-roz+n)%n] == 1 ? 'B' : 'W');
	return 0;
}