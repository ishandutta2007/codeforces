#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
#include <complex>
#include <cmath>

using namespace std;

const double pi = acos(-1);
const int maxn = (1 << 20) + 5;

typedef complex<double> cd;

int bits[1 << 23];

void pre(int n) {
	int LOG = 0;
	while(1 << (LOG + 1) < n) {
		LOG++;
	}
	for(int i = 1; i < n; i++) {
		bits[i] = (bits[i >> 1] >> 1) | ((i & 1) << LOG);
	}
}

vector<cd> fft(vector<cd> a, bool inv = false) {
	int n = a.size();
	pre(n);
	for(int i = 0; i < n; i++) {
		int to = bits[i];
		if(to > i) {
			std::swap(a[to], a[i]);
		}
	}
	
	double angle = inv ? -1 : 1;
	angle *= pi;
	for(int len = 1; len < n; len *= 2) {
		cd delta(cosl(angle / len), sinl(angle / len));
		for(int i = 0; i < n; i += 2 * len) {
			cd cur_root = 1;
			for(int j = 0; j < len; j++) {
				cd u = a[i + j], v = a[i + j + len] * cur_root;
				a[i + j] = u + v;
				a[i + j + len] = u - v;
				cur_root *= delta;
			}
		}
	}
	if(inv) {
		for(int i = 0; i < n; i++)
			a[i] /= n;
	}
	return a;
}

vector<int> mul(const vector<int> &a, const vector<int> &b) {
    vector<cd> p1, p2;
    int n = a.size();
    //while (n != (n & -n)) n += (n & -n);
    p1.reserve(n), p2.reserve(n);
    for (auto &i : a) p1.push_back(cd(i, 0));
    for (auto &i : b) p2.push_back(cd(i, 0));
    while (p1.size() < n) p1.push_back(cd(0, 0));
    while (p2.size() < n) p2.push_back(cd(0, 0));

    vector<cd> f1 = fft(p1), f2 = fft(p2);
    for (int i = 0; i < n; i++)
        f2[i] *= f1[i];
    f2 = fft(f2, true);
    vector<int> rtn(n);
    for (int i = 0; i < n; i++) rtn[i] = round(f2[i].real());
    //while (rtn.size() && rtn.back() == 0) rtn.pop_back();
    return rtn;
}

int decode[256];
int freq[4];

void print_vector(std::vector<int> A) {
	for(auto a : A) std::cout << a << ' ';
	std::cout << std::endl;
}

int main() {
	int n, m, k;
	std::cin >> n >> m >> k;
	std::string s, t;
	std::cin >> s >> t;
	int N=1;
	while(N<n+m)
		N<<=1;
	std::vector<int> A[4], B[4];
	for(int i=0;i<4;i++) {
		A[i].resize(N);
		B[i].resize(N);
	}
	decode['A']=0;
	decode['G']=1;
	decode['C']=2;
	decode['T']=3;
	for(int i=0;i<n;i++) {
		A[decode[s[i]]][std::max(i-k, 0)] += 1;
		if(i+k+1<n)
			A[decode[s[i]]][i+k+1] -= 1;
	}
	for(int i=0;i<m;i++) {
		B[decode[t[i]]][m-i-1]=1;
		freq[decode[t[i]]]++;
	}
	for(int i=0;i<4;i++) {
		for(int j=1;j<N;j++)
			A[i][j] += A[i][j-1];
	}
	for(int i=0;i<4;i++) {
		for(int j=0;j<N;j++)
			A[i][j] = std::min(1, A[i][j]);
	}
	std::vector<int> C[4];
	for(int j=0;j<4;j++) {
		//print_vector(A[j]);
		//print_vector(B[j]);
		C[j] = mul(A[j], B[j]);
		//print_vector(C[j]);
		//std::cout << "\n\n";
	}
	int ans=0;
	for(int i=0;i<=n-m;i++) {
		bool can=true;
		for(int j=0;j<4;j++)
			can=can && (C[j][m-1+i]==freq[j]);
		if(can) {
			//std::cout << "found on " << i << '\n';
			ans++;
		}
	}
	std::cout << ans << '\n';
}