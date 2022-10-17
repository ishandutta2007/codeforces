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

#define LSB(i) ((i) & -(i)) // zeroes all the bits except the least significant one
const int SIZE = 200005;
struct BIT{
	ll A[SIZE];
	ll sum(int i) // Returns the sum from index 1 to i
	{
		i++;
	    ll sum = 0;
	    while (i > 0) 
	        sum += A[i], i -= LSB(i);
	    return sum;
	}
	 
	void add(int i, ll k) // Adds k to element with index i
	{
		i++;
	    while (i < SIZE) 
	        A[i] += k, i += LSB(i);
	}
};


int n, m;
std::vector<PII> A;
VI B, ord;
BIT b1, b2;



int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> m;
	A.resize(n);
	B.resize(n);
	FOR(i, n) std::cin >> A[i].X;
	FOR(i, n) A[i].Y = i, B[i] = A[i].X;
	std::sort(A.begin(), A.end());
	ord.resize(n);
	FOR(i, n) ord[A[i].Y] = i;
	FOR(i, n){
		ll can = m-B[i];
		int left = 0;
		int right = n;
		while(left < right){
			int mid = (left+right)/2;
			if(b1.sum(mid) > can) right = mid;
			else left = mid+1;
		}
		left--;
		std::cout << i-b2.sum(left) << "\n";
		b2.add(ord[i], 1);
		b1.add(ord[i], B[i]);
	}
	return 0;
}