// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <cmath>
#include <iomanip>
#include <time.h>
#define dibs reserve
#define OVER9000 1234567890
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define tisic 47
#define soclose 1e-8
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define abs(x) (((x) < 0)?-(x):(x))
#define uint unsigned int
#define dbl long double
#define pi 3.14159265358979323846
using namespace std;
// mylittledoge

using cat = long long;

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

template <typename T>
struct vec3 {
	int N[3];
	vector<T> data;

	vec3() = default;
	vec3(int N0, int N1, int N2, T val = 0) : N{N0, N1, N2} {
		data.resize(N0*N1*N2, val);
	}

	T & operator()(int i0, int i1, int i2) {
		return data[(i0*N[1]+i1)*N[2]+i2];
	}
};

template <typename T>
struct vec2 {
	int N[2];
	vector<T> data;

	vec2() = default;
	vec2(int N0, int N1, T val = 0) : N{N0, N1} {
		data.resize(N0*N1, val);
	}

	T & operator()(int i0, int i1) {
		return data[i0*N[1]+i1];
	}
};

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N[3];
	for(int i = 0; i < 3; i++) cin >> N[i];
	vec2<int> A[3][2];
	int dim[3][2];
	for(int k = 0; k < 3; k++) for(int l = 0; l < 2; l++) {
		dim[k][0] = k ? 0 : 1;
		dim[k][1] = 3-k-dim[k][0];
		A[k][l] = vec2<int>(N[dim[k][0]], N[dim[k][1]]);
		for(int i = 0; i < N[dim[k][0]]; i++)
			for(int j = 0; j < N[dim[k][1]]; j++)
				cin >> A[k][l](i,j);
	}
	vec3<int> ans(N[0], N[1], N[2], -1);
	for(int k = 0; k < 3; k++)
		for(int i = 0; i < N[dim[k][0]]; i++)
			for(int j = 0; j < N[dim[k][1]]; j++)
				if(!A[k][0](i,j) || !A[k][1](i,j)) {
					if(A[k][0](i,j) || A[k][1](i,j)) {
						cout << "-1\n";
						return 0;
					}
					int idx[3];
					idx[dim[k][0]] = i;
					idx[dim[k][1]] = j;
					for(idx[k] = 0; idx[k] < N[k]; idx[k]++) ans(idx[0],idx[1],idx[2]) = 0;
				}
	vec3<int> border[8];
	for(int c = 0; c < 8; c++) border[c] = vec3<int>(N[0], N[1], N[2], 0);
	vec3<int> cur[8];
	for(int c = 0; c < 8; c++) cur[c] = vec3<int>(N[0], N[1], N[2], -1);
	vec2<int> B[8][3];
	for(int c = 0; c < 8; c++)
		for(int k = 0; k < 3; k++) {
			int x = (c>>k)&1;
			B[c][k] = vec2<int>(N[dim[k][0]], N[dim[k][1]], 0);
			for(int i = 0; i < N[dim[k][0]]; i++)
				for(int j = 0; j < N[dim[k][1]]; j++) {
					int i_r = i, j_r = j;
					if((c>>dim[k][0])&1) i_r = N[dim[k][0]]-1-i;
					if((c>>dim[k][1])&1) j_r = N[dim[k][1]]-1-j;
					B[c][k](i_r,j_r) = A[k][x](i,j);
				}
		}
	bool stop;
	for(int r = 0; r < 2*min(N[0], min(N[1], N[2])); r++) for(int c = 0; c < 8; c++) {
		if(!c) stop = true;
		for(int i = 0; i < N[0]; i++)
			for(int j = 0; j < N[1]; j++)
				for(int k = 0; k < N[2]; k++) {
					if(i == 0) border[c](i,j,k) |= 1;
					if(j == 0) border[c](i,j,k) |= 2;
					if(k == 0) border[c](i,j,k) |= 4;
					int i_r = i, j_r = j, k_r = k;
					if(c&1) i_r = N[0]-1-i;
					if(c&2) j_r = N[1]-1-j;
					if(c&4) k_r = N[2]-1-k;
					if(ans(i_r,j_r,k_r) == 0) cur[c](i,j,k) = 0;
				}
		for(int i = 0; i < N[0]; i++)
			for(int j = 0; j < N[1]; j++)
				for(int k = 0; k < N[2]; k++) {
					int b = border[c](i,j,k);
					if(!b) continue;
					int idx[3] = {i, j, k};
					if(cur[c](i,j,k) == -1) for(int l = 0; l < 3; l++) if((b>>l)&1) {
						int val = B[c][l](idx[dim[l][0]],idx[dim[l][1]]);
						if(cur[c](i,j,k) == -1) cur[c](i,j,k) = val;
						else if(cur[c](i,j,k) != val) {
							cur[c](i,j,k) = 0;
							break;
						}
					}
					if(cur[c](i,j,k) == 0) for(int l = 0; l < 3; l++) {
						idx[l]++;
						if(idx[l] != N[l]) border[c](idx[0],idx[1],idx[2]) |= b & (1<<l);
						idx[l]--;
					}
				}
		for(int i = 0; i < N[0]; i++)
			for(int j = 0; j < N[1]; j++)
				for(int k = 0; k < N[2]; k++) {
					int i_r = i, j_r = j, k_r = k;
					if(c&1) i_r = N[0]-1-i;
					if(c&2) j_r = N[1]-1-j;
					if(c&4) k_r = N[2]-1-k;
					int val_cur = cur[c](i,j,k), val_ans = ans(i_r,j_r,k_r);
					if(val_cur != -1) {
						if(val_ans != -1 && val_cur != val_ans) ans(i_r,j_r,k_r) = 0, stop = false;
						else ans(i_r,j_r,k_r) = val_cur;
					}
				}
		if(c == 7 && stop) r = 3*N[0];
	}
	for(int k = 0; k < 3; k++)
		for(int i = 0; i < N[dim[k][0]]; i++)
			for(int j = 0; j < N[dim[k][1]]; j++)
				if(A[k][0](i,j)) {
					int idx[3];
					idx[dim[k][0]] = i;
					idx[dim[k][1]] = j;
					idx[k] = 0;
					while(idx[k] < N[k] && !ans(idx[0],idx[1],idx[2])) idx[k]++;
					if(idx[k] == N[k] || ans(idx[0],idx[1],idx[2]) != A[k][0](i,j)) {
						cout << "-1\n";
						return 0;
					}
					idx[k] = N[k]-1;
					while(idx[k] >= 0 && !ans(idx[0],idx[1],idx[2])) idx[k]--;
					if(idx[k] == -1 || ans(idx[0],idx[1],idx[2]) != A[k][1](i,j)) {
						cout << "-1\n";
						return 0;
					}
				}
	for(int i = 0; i < N[0]; i++)
		for(int j = 0; j < N[1]; j++)
			for(int k = 0; k < N[2]; k++)
				if(ans(i,j,k) == -1) ans(i,j,k) = 0;
	for(int i = 0; i < N[0]; i++) {
		if(i) cout << "\n";
		for(int j = 0; j < N[1]; j++) for(int k = 0; k < N[2]; k++)
			cout << ans(i,j,k) << ((k == N[2]-1) ? "\n" : " ");
	}
	return 0;
}

// look at my code
// my code is amazing