#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>

using namespace std;

long long f[20][200][2];

int main() {
  	long long n;
	cin >> n;
	vector<int> vn;
	while (n) {
		vn.push_back(n % 10);
		n /= 10;
	}
	reverse(vn.begin(), vn.end());
	memset(f, -1, sizeof(f));
	f[0][0][0] = 0;
	for (int cur = 0; cur < (int)vn.size(); cur++) {
		for (int sum = 0; sum <= cur * 9; sum++) {
			for (int flag = 0; flag < 2; flag++) {
			  		if (f[cur][sum][flag] == -1) continue;
					for (int x = 0; x < 10; x++) {
					  	if ((flag == 0) && (x > vn[cur])) continue;
						long long nf = f[cur][sum][flag] * 10 + x;
						int nflag = (flag | (x < vn[cur]));
						int nsum = sum + x;
						if (nf > f[cur + 1][nsum][nflag]) {
							f[cur + 1][nsum][nflag] = nf;
						}
					}
			}
		}
	}
	for (int sum = (int)vn.size() * 9; sum >= 1; sum--) {
	  	for (int flag = 0; flag < 2; flag++) {
			if (f[(int)vn.size()][sum][flag] != -1) {
				cout << f[(int)vn.size()][sum][flag] << endl;
				return 0;
			}
		}
	}
}