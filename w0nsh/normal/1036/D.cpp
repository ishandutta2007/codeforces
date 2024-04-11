#include <algorithm>
#include <bitset>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_set>
#include <queue>
#include <deque>
#include <map>
#include <unordered_map>
#include <list>
#include <stack>
#include <functional>
#include <utility>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <random>
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

int n, m;
std::vector<ll> A, B;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n;
	A.resize(n);
	FOR(i, n) std::cin >> A[i];
	std::cin >> m;
	B.resize(m);
	FOR(i, m) std::cin >> B[i];
	ll a = 0;
	ll b = 0;
	ll roz = 0;
	int lena = n;
	int lenb = m;
	while(a < n || b < m){
		do{
			if(a < n && (b >= m || roz < 0)) roz += A[a++], lena--;
			else roz -= B[b++], lenb--;
		}while(roz != 0 && (a < n || b < m));
		if(roz != 0){
			std::cout << -1 << "\n";
			return 0;
		}
		lena++;
		lenb++;
	}
	if(lena != lenb) std::cout << -1 << "\n";
	else std::cout << lena << "\n";
	return 0;
}