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



const int MOD = 998244353;


#define LSB(i) ((i) & -(i)) // zeroes all the bits except the least significant one

int BIT[200005];
int Sum(int i) // Returns the sum from index 1 to i
{
    int sum = 0;
    while (i > 0) 
        sum += BIT[i], i -= LSB(i);
    return sum;
}
 
void Add(int i, int k) // Adds k to element with index i
{
    while (i < 200005) 
        BIT[i] += k, i += LSB(i);
}

int mod_pow(int b, int e){
	int r = 1;
	while(e > 0){
		if(e&1) r = (1ll*r*b)%MOD;
		b = (1ll*b*b)%MOD;
		e >>= 1;
	}
	return r;
}
int fact[200005], invfact[200005];
inline int falling(int n, int k){
	return (1ll*fact[n]*invfact[n-k])%MOD;
}
inline int binco(int n, int k){
	return (1ll*falling(n, k)*invfact[k])%MOD;
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	fact[0] = 1;
	invfact[0] = 1;
	REP(i, 1, 200005) fact[i] = (1ll*fact[i-1]*i)%MOD, invfact[i] = mod_pow(fact[i], MOD-2);
	int n, bl = 0;
	VI A, here, blanks;
	std::cin >> n;
	A.resize(n);
	here.resize(n+1);
	FOR(i, n){
		std::cin >> A[i];
		if(A[i] == -1) bl++;
		else here[A[i]] = 1;
	}
	REP(i, 1, n+1) if(here[i] == 0) blanks.push_back(i);
	int ev = 0;
	if(bl > 1) ev = (1ll*(((1ll*bl*(bl-1))/2)%MOD)*invfact[2])%MOD;
	int left = 0;
	int right = bl;
	int ev2 = 0;
	FOR(i, n){
		if(A[i] == -1) left++, right--;
		else{
			int smaller = std::lower_bound(blanks.begin(), blanks.end(), A[i]) - blanks.begin();
			int bigger = bl - smaller;
			int cur = 1;
			cur = (1ll*cur*right)%MOD;
			cur = (1ll*cur*smaller)%MOD;
			cur = (1ll*cur*fact[bl-1])%MOD;
			ev2 = (ev2+cur)%MOD;
			// std::cout << cur << " ";
			cur = 1;
			cur = (1ll*cur*left)%MOD;
			cur = (1ll*cur*bigger)%MOD;
			cur = (1ll*cur*fact[bl-1])%MOD;
			ev2 = (ev2+cur)%MOD;
			// std::cout << cur << " ";
			// std::cout << "\n";
		}
	}
	int normal = 0;
	FOR(i, n){
		if(A[i] == -1) continue;
		normal = (1ll*normal+Sum(n+2)-Sum(A[i]))%MOD;
		Add(A[i], 1);
	}
	normal = (1ll*normal*fact[bl])%MOD;
	// std::cout << 1ll*ev*fact[bl]%MOD << " " << ev2 << " " << normal << "\n";
	std::cout << ((((1ll*ev2+(1ll*ev*fact[bl])%MOD)%MOD+normal)%MOD)*invfact[bl])%MOD << "\n";
	return 0;
}