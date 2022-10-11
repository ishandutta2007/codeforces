// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <chrono>
#include <random>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <iomanip>
#define dibs reserve
#define OVER9000 1234567890
#define tisic 47
#define soclose 1e-8
#define patkan 9
#define ff first
#define ss second
#define abs(x) (((x) < 0)?-(x):(x))
using uint = unsigned int;
using cat = long long;
using dbl = long double;
constexpr dbl pi = 3.14159265358979323846;
using namespace std;

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

int A[100], D[100];
int last_trip, last_str;

pair<int, int> query(int pos, bool init = false) {
	if(!init) {
		cout << "+ " << pos+1 << endl;
		D[pos]++;
	}
	int next_trip = 0, next_str = 0;
	cin >> next_trip >> next_str;
	int dif_trip = next_trip-last_trip, dif_str = next_str-last_str;
	last_trip = next_trip, last_str = next_str;
	return {dif_trip, dif_str};
}

void solve(int l, int r) {
	if(l > r) return;
	if(l == r) {
		query(l);
		auto [dif_trip, dif_str] = query(l);
		A[l] = 2;
		while((A[l]-1)*(A[l]-2)/2 < dif_trip) A[l]++;
		return;
	}
	if(l+1 == r) {
		query(l-1);
		A[l-1] = 1;
		query(r);
		auto [dif_trip, dif_str] = query(r);
		A[r] = 2;
		while((A[r]-1)*(A[r]-2)/2 < dif_trip) A[r]++;
		A[l] = dif_str;
		return;
	}
	if(l+2 == r) {
		int dif_str_final;
		for(int k = l; k <= l+1; k++) {
			query(k);
			auto [dif_trip, dif_str] = query(k);
			dif_str_final = dif_str;
			A[k] = 2;
			while((A[k]-1)*(A[k]-2)/2 < dif_trip) A[k]++;
		}
		A[r] = dif_str_final/A[l];
		return;
	}
	auto [dif2_trip, dif2_str] = query(l+1);
	auto [dif1_trip, dif1_str] = query(l);
	if(dif1_str == 0) {
		A[l] = A[l+1] = 1;
		A[l+2] = 0;
		if(r-l+1 == 4) {
			auto [dif3_trip, dif3_str] = query(l+2);
			A[l+2] = 1;
			auto [dif_trip, dif_str] = query(l);
			A[l+1] = dif_str;
			A[l] = 2;
			while((A[l]-2)*(A[l]-1)/2 < dif_trip) A[l]++;
			if((A[l]-2)*(A[l]-1)/2 != dif_trip) exit(1);
			// dif3_str == (A[r]+A[l]-1)*A[l+1]
			A[r] = dif3_str/A[l+1]-A[l]+1;
			return;
		}
		if(r-l+1 == 5) {
			auto [dif3_trip, dif3_str] = query(l+2);
			A[l+2] = 1;
			auto [dif4_trip, dif4_str] = query(l+3);
			auto [dif_trip, dif_str] = query(l);
			A[l] = 2;
			while((A[l]-2)*(A[l]-1)/2 < dif_trip) A[l]++;
			if((A[l]-2)*(A[l]-1)/2 != dif_trip) exit(1);
			A[l+1] = dif_str;
			A[l+4] = dif4_str-A[l+1];
			A[l+3] = (dif3_str-(A[l]-1)*A[l+1])/dif4_str+1;
			return;
		}
		if(r-l+1 == 6) {
			auto [dif3_trip, dif3_str] = query(l+2);
			A[l+2] = 1;
			auto [dif4_trip, dif4_str] = query(l+3);
			auto [dif5_trip, dif5_str] = query(l+4);
			auto [dif_trip, dif_str] = query(l);
			A[l] = 2;
			while((A[l]-2)*(A[l]-1)/2 < dif_trip) A[l]++;
			if((A[l]-2)*(A[l]-1)/2 != dif_trip) exit(1);
			A[l+1] = dif_str;
			// dif3_str = (A[l]-1)*A[l+1]+(A[l+1]+A[l+4]-1)*(A[l+3]-1)
			if(dif4_trip) {
				A[l+3] = 2;
				while((A[l+3]-2)*(A[l+3]-1)/2 < dif4_trip) A[l+3]++;
				if((A[l+3]-2)*(A[l+3]-1)/2 != dif4_trip) exit(1);
				A[l+4] = (dif3_str-(A[l]-1)*A[l+1])/(A[l+3]-1)-A[l+1]+1;
			}
			else if(dif5_trip) {
				A[l+4] = 2;
				while((A[l+4]-2)*(A[l+4]-1)/2 < dif5_trip) A[l+4]++;
				if((A[l+4]-2)*(A[l+4]-1)/2 != dif5_trip) exit(1);
				A[l+3] = (dif3_str-(A[l]-1)*A[l+1])/(A[l+1]+A[l+4]-1)+1;
			}
			else {
				dif3_str -= (A[l]-1)*A[l+1]; // (A[l+1]+A[l+4]-1)*(A[l+3]-1)
				dif4_str -= A[l+1]; // (A[l+4]-1)*(A[l+5]+1)
				A[l+4] = (dif4_str == 0) ? 1 : 2;
				A[l+3] = dif3_str/(A[l+1]+A[l+4]-1)+1;
			}
			A[l+5] = dif5_str/A[l+3]-A[l+2];
			return;
		}
		solve(l+3, r);
		if(dif1_trip) {
			while((A[l]-2)*(A[l]-1)/2 < dif1_trip) A[l]++;
			if((A[l]-2)*(A[l]-1)/2 != dif1_trip) exit(1);
		}
		if(dif2_trip) {
			while((A[l+1]-2)*(A[l+1]-1)/2 < dif2_trip) A[l+1]++;
			if((A[l+1]-2)*(A[l+1]-1)/2 != dif2_trip) exit(1);
		}
		auto [dif_trip, dif_str] = query(l+2);
		A[l+2]++;
		dif_str -= A[l+3]*A[l+4];
		if(dif1_trip) A[l+1] = dif_str/(A[l]+A[l+3]);
		else if(dif2_trip) A[l] = dif_str/A[l+1]-A[l+3];
		else if(dif_str == A[l+3]*1+1) A[l] = A[l+1] = 1;
		else if(dif_str == A[l+3]*1+2) A[l] = 2, A[l+1] = 1;
		else if(dif_str == A[l+3]*2+2) A[l] = 1, A[l+1] = 2;
		else if(dif_str == A[l+3]*2+4) A[l] = A[l+1] = 2;
		else exit(1);
		return;
	}
	// A[l+2] > 0
	auto [dif_trip, dif_str] = query(l+2);
	A[l+2] = 2;
	while((A[l+2]-2)*(A[l+2]-1)/2 < dif_trip) A[l+2]++;
	if((A[l+2]-2)*(A[l+2]-1)/2 != dif_trip) exit(1);
	A[l+1] = dif1_str/(A[l+2]-1);
	// dif2_str/(A[l+2]-1) == A[l]-1+A[l+3]
	if(l+2 == r) {
		A[l] = dif2_str/(A[l+2]-1)+1;
		return;
	}
	if(dif2_str == 0) {
		A[l] = 1;
		A[l+3] = 0;
		solve(l+4, r);
		return;
	}
	if(l+4 == r) {
		query(l+3);
		auto [dif3_trip, dif3_str] = query(l+3);
		A[l+3] = 2;
		while((A[l+3]-1)*(A[l+3]-2)/2 < dif3_trip) A[l+3]++;
		A[l] = dif2_str/(A[l+2]-1)-(A[l+3]-2)+1;
		A[l+4] = dif3_str/A[l+2]-A[l+1];
		return;
	}
	if(l+5 == r) {
		auto [dif3_trip, dif3_str] = query(l+3);
		auto [dif4_trip, dif4_str] = query(l+4);
		if(dif3_str == A[l+2]*A[l+1]) {
			A[l+4] = 1;
			// dif4_str == A[l+3](A[l+2]+A[l+5])
			auto [dif_trip, dif_str] = query(l+3);
			A[l+3] = 2;
			while((A[l+3]-2)*(A[l+3]-1)/2 < dif_trip) A[l+3]++;
			if((A[l+3]-2)*(A[l+3]-1)/2 != dif_trip) exit(1);
			A[l] = dif2_str/(A[l+2]-1)-(A[l+3]-2)+1;
			A[r] = dif4_str/(A[l+3]-1)-A[l+2];
		}
		else {
			A[l+4] = 2;
			while((A[l+4]-2)*(A[l+4]-1)/2 < dif4_trip) A[l+4]++;
			if((A[l+4]-2)*(A[l+4]-1)/2 != dif4_trip) exit(1);
			// dif_str == (A[l]+A[l+3]-1)*A[l+1]+(A[l+3]-1)*(A[l+4]-1)
			// dif2_str == (A[l]+A[l+3]-2)*(A[l+2]-1)
			A[l+3] = (dif_str-(dif2_str/(A[l+2]-1)+1)*A[l+1]) / (A[l+4]-1) + 1;
			A[l] = dif2_str/(A[l+2]-1)-(A[l+3]-1)+1;
			A[l+5] = dif4_str/A[l+3]-A[l+2];
		}
		return;
	}
	if(l+6 == r) {
		auto [dif31_trip, dif31_str] = query(l+4);
		auto [dif41_trip, dif41_str] = query(l+5);
		auto [dif32_trip, dif32_str] = query(l+4);
		auto [dif42_trip, dif42_str] = query(l+5);
		A[l+4] = A[l+5] = 2;
		while((A[l+4]-2)*(A[l+4]-1)/2 < dif32_trip) A[l+4]++;
		if((A[l+4]-2)*(A[l+4]-1)/2 != dif32_trip) exit(1);
		while((A[l+5]-2)*(A[l+5]-1)/2 < dif42_trip) A[l+5]++;
		if((A[l+5]-2)*(A[l+5]-1)/2 != dif42_trip) exit(1);
		// dif41_str == (A[l+4]-1)(A[l+3]+A[l+6])
		// dif32_str == (A[l+5]-1)(A[l+3]+A[l+6])+A[l+2]*A[l+3]
		A[l+3] = (dif32_str - (A[l+5]-1)*dif41_str/(A[l+4]-1)) / A[l+2];
		A[l] = dif2_str/(A[l+2]-1)-A[l+3]+1;
		A[l+6] = dif41_str/(A[l+4]-1)-A[l+3];
		return;
	}
	auto [dif4_trip, dif4_str] = query(l);
	A[l] = 2;
	while((A[l]-2)*(A[l]-1)/2 < dif4_trip) A[l]++;
	if((A[l]-2)*(A[l]-1)/2 != dif4_trip) exit(1);
	A[l+3] = dif2_str/(A[l+2]-1)+1-(A[l]-1);
	if(l+3 == r) return;
	if(A[l+3] == 0) {
		solve(l+4, r);
		return;
	}
	// dif_str == A[l]*A[l+1]+A[l+1]*A[l+3]+A[l+3]*A[l+4]
	int k = 4;
	while(l+k <= r) {
		A[l+k] = (dif_str-(A[l+k-4]-(k==4))*A[l+k-3])/A[l+k-1]-A[l+k-3];
		if(A[l+k] == 0) {
			solve(l+k+1, r);
			return;
		}
		pair<int, int> p = query(l+k-1);
		dif_trip = p.ff, dif_str = p.ss;
		A[l+k-1]++;
		k++;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(10);
	int N;
	cin >> N;
	cin >> last_trip >> last_str;
	//query(0, true);
	solve(0, N-1);
	cout << "!";
	for(int i = 0; i < N; i++) cout << " " << A[i]-D[i];
	cout << endl;
	return 0;
}

// look at my code
// my code is amazing