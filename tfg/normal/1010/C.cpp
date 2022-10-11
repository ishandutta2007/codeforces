#include <iostream>
#include <cstdio>
#include <vector>
#include <complex>

typedef double ld;

const ld PI = acosl(-1.0);
const int ms = 1 << 18;

typedef std::complex<ld> Complex;
typedef std::vector<Complex> CVector;

int bits[ms];

void pre(int n) {
	int LOG = 0;
	while(1 << (LOG + 1) < n) {
		LOG++;
	}
	for(int i = 1; i < n; i++) {
		bits[i] = (bits[i >> 1] >> 1) | ((i & 1) << LOG);
	}
}

void fft(CVector &a, bool inv = false) {
	int n = a.size();
	for(int i = 0; i < n; i++) {
		int to = bits[i];
		if(to > i) {
			std::swap(a[to], a[i]);
		}
	}
	
	double angle = inv ? -PI : PI;
	for(int len = 1; len < n; len *= 2) {
		Complex delta(cosl(angle / len), sinl(angle / len));
		for(int i = 0; i < n; i += 2 * len) {
			Complex cur_root = 1;
			for(int j = 0; j < len; j++) {
				Complex u = a[i + j], v = a[i + j + len] * cur_root;
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
}

int main() {
	//std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, k;
	std::cin >> n >> k;
	std::vector<int> freq(k, 0);
	freq[0]++;
	for(int i = 0; i < n; i++) {
		int t;
		//std::cin >> t;
		scanf("%d", &t);
		t %= k;
		int b = t;
		if(!freq[t]) {
			while(t != 0) {
				freq[t]++;
				t = (t + b) % k;
			}
		}
	}
	int size = ms;
	pre(size);
	CVector A(ms, 0);
	for(int i = 0; i < k; i++) {
		if(freq[i]) {
			A[i] = 1;
		}
	}
	std::vector<int> hmm(k, 0);
	for(int rep = 0; rep < 8; rep++) {
		fft(A);
		for(int i = 0; i < ms; i++) {
			A[i] *= A[i];
		}
		fft(A, true);
		for(int i = 0; i < ms; i++) {
			if(A[i].real() + 0.5 >= 1) {
				hmm[i % k]++;
			}
			A[i] = 0;
		}
		for(int i = 0; i < k; i++) {
			if(hmm[i]) {
				A[i] = 1;
			}
		}
	}
	std::vector<int> ans;
	for(int i = 0; i < k; i++) {
		if(hmm[i]) {
			ans.push_back(i);
		}
	}
	std::cout << ans.size() << std::endl;
	for(int i = 0; i < ans.size(); i++) {
		printf("%d%c", ans[i], i + 1 == ans.size() ? '\n' : ' ');
		//std::cout << ans[i] << (i + 1 == ans.size() ? '\n' : ' ');
	}
}