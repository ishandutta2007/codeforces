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

const int MAX = 2750131;

VI primes;
bool is_prime[MAX+5];
int next[MAX+5];
bool vis[MAX+5];

void get_primes(){
	FOR(i, MAX+1) is_prime[i] = true;
	for(int i = 2; i <= MAX; ++i){
		if(is_prime[i]){
			for(int j = 2*i; j <= MAX; j += i) is_prime[j] = false;
			primes.push_back(i);
		}
	}
	REP(i, 2, MAX+1) if(!is_prime[i]){
		int t = 2;
		while(i % t != 0) t++;
		next[i] = i/t;		
	}
}

std::vector<VI> g;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	get_primes();
	int n;
	std::cin >> n;
	VI A(2*n);
	FOR(i, 2*n) std::cin >> A[i];
	std::map<int, int> indeg;
	FOR(i, 2*n){
		if(is_prime[A[i]]){
			if(SZ(primes) >= A[i]){
				indeg[primes[A[i]-1]]++;
			}
		}else{
			indeg[next[A[i]]]++;
		}
	}
	std::queue<int> que;
	std::map<int, int> have;
	FOR(i, 2*n) have[A[i]]++;
	TRAV(pr, have) if(indeg[pr.X] == 0) que.push(pr.X);
	VI ans;
	// TRAV(pr, have) std::cout << pr.X << " " << indeg[pr.X] << std::endl;
	while(SZ(ans) < n){
		assert(SZ(que) > 0);
		int cur = que.front();
		// std::cout << "teraz " << cur << " indeg " << indeg[cur] << std::endl;
		assert(indeg[cur] == 0);
		que.pop();
		while(have[cur] > 0){
			have[cur]--;
			ans.push_back(cur);
			if(is_prime[cur]){
				assert(SZ(primes) >= cur);
				indeg[primes[cur-1]]--;
				have[primes[cur-1]]--;
				int nxt = primes[cur-1];
				if(SZ(primes) >= nxt){
					indeg[primes[nxt-1]]--;
					if(have[primes[nxt-1]] > 0 && indeg[primes[nxt-1]] == 0) que.push(primes[nxt-1]);
				}
				if(have[primes[cur-1]] > 0 && indeg[primes[cur-1]] == 0) que.push(primes[cur-1]);
			}else{
				indeg[next[cur]]--;
				have[next[cur]]--;
				int nxt = next[cur];
				if(is_prime[nxt]){
					if(SZ(primes) >= nxt){
						indeg[primes[nxt-1]]--;
						if(have[primes[nxt-1]] > 0 && indeg[primes[nxt-1]] == 0) que.push(primes[nxt-1]);
					}
				}else{
					indeg[next[nxt]]--;
					if(have[next[nxt]] > 0 && indeg[next[nxt]] == 0) que.push(next[nxt]);
				}
				if(have[next[cur]] > 0 && indeg[next[cur]] == 0) que.push(next[cur]);
			}
		}
		// std::cout << "byla " << cur << "\n";
		// TRAV(i, ans) std::cout << i <<  " ";
		// std::cout << std::endl;
	}
	TRAV(i, ans) std::cout << i << " ";
	return 0;
}