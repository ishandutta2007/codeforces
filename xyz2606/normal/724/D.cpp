#include<bits/stdc++.h>
using namespace std;
vector<int> vec[33];
const int N(111111);
int sigma[N * 4];
void build(int k, int le, int ri) {
	sigma[k] = ri - le + 1;
	if(le == ri) {
	}else {
		int mid(le + ri >> 1);
		build(k + k, le, mid);
		build(k + k + 1, mid + 1, ri);
	}
}
int ask(int k, int le, int ri, int ql, int qr) {
	if(ql <= le && ri <= qr) {
		return sigma[k];
	}else {
		int mid(le + ri >> 1);
		int res(0);
		if(sigma[k] == 0) {
			sigma[k + k] = sigma[k + k + 1] = 0;
		}
		if(ql <= mid) {
			res += ask(k + k, le, mid, ql, qr);
		}
		if(qr >= mid + 1) {
			res += ask(k + k + 1, mid + 1, ri, ql, qr);
		}
		return res;
	}
}
void reset(int k, int le, int ri, int ql, int qr) {
	//printf("! %d %d %d %d %d\n", k, le, ri,ql, qr);
	if(ql <= le && ri <= qr) {
		sigma[k] = 0;
	}else {
		int mid(le + ri >> 1);
		if(sigma[k] == 0) {
			sigma[k + k] = sigma[k + k + 1] = 0;
		}
		if(ql <= mid) {
			reset(k + k, le, mid, ql, qr);
		}
		if(qr >= mid + 1) {
			reset(k + k + 1, mid + 1, ri, ql, qr);
		}
		sigma[k] = sigma[k + k] + sigma[k + k + 1];
	}
}
int main() {
	int m;
	scanf("%d", &m);
	static char st[N];
	scanf("%s", st + 1);
	int n(strlen(st + 1));
	for(int i(1); i <= n; i++) {
		vec[st[i] - 'a'].push_back(i);
	}
	string ans;
	build(1, 1, n - m + 1);
	for(int i(0); i < 26; i++) {
		int cnt(0);
		for(int j(0); j < (int)vec[i].size(); j++) {
			/*printf("%d \n", vec[i][j]);
			if(j + 1 < (int)vec[i].size() && vec[i][j + 1] - m >= 1) {
				printf("?! %d %d\n",  min(n - m + 1, vec[i][j + 1] - m), (vec[i][j + 1] - m <= 0 || ask(1, 1,  n - m + 1, 1, min(n - m + 1, vec[i][j + 1] - m))));
			}*/
			if(ask(1, 1, n - m + 1, 1, n - m + 1) == 0 || (j + 1 < (int)vec[i].size() && (vec[i][j + 1] - m <= 0 || ask(1, 1,  n - m + 1, 1, min(n - m + 1, vec[i][j + 1] - m)) == 0))) {
				continue;
			}else {
				//printf("wow\n");
				reset(1, 1, n - m + 1, max(1, vec[i][j] - m + 1), min(n - m + 1, vec[i][j]));
				ans.push_back(i + 'a');
				cnt++;
			}
		}
		//printf("??%d\n", ask(1, 1,  n - m + 1, 1, n - m + 1));
		if(ask(1, 1,  n - m + 1, 1, n - m + 1) == 0) {
			cout << ans << endl;
			return 0;
		}else {
			while(ans.size() >= 1 && ans.back() == i + 'a') {
				ans.pop_back();
			}
			for(int j : vec[i]) {
				reset(1, 1, n - m + 1, max(1, j - m + 1), min(n - m + 1, j));
				ans.push_back(i + 'a');
			}
		}
	}
}