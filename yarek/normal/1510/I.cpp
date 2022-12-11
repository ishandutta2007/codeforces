#include <bits/stdc++.h>

using namespace std;

typedef long double T;

const int N = 10'007;
const T MT = 2.;

int n, m;
T all_sum = 0.;
int min_wa = 0;

int wa[N];
int cnt_wa[N];
char vote[N];

int write(int v) {
	printf("%d\n", v);
	fflush(stdout);
	
	scanf("%d", &v);
	return v;
}

T getReal(T a, T b) {
	static mt19937 rng(342109);
	return uniform_real_distribution <T> (a, b)(rng);
}

T get(int id) {
//	return 1. / (wa[id] - min_wa + 1);
	return exp((min_wa - wa[id]) / MT);
}

void update(int result) {
	for(int i = 0; i < n; ++i) {
		if(vote[i] == result + '0')
			continue;
		
		cnt_wa[wa[i]]--;
		wa[i]++;
		cnt_wa[wa[i]]++;
	}
	
	if(cnt_wa[min_wa] == 0)
		++min_wa;

	all_sum = 0.;
	for(int i = 0; i < n; ++i)
		all_sum += get(i);
}

int getVote() {
	T shot = getReal(0., all_sum);
	for(int i = 0; i < n; ++i) {
		shot -= get(i);
		if(shot < 0.)
			return i;
	}
	
	return n - 1;
}

void read() {
	scanf("%s", vote);
}

int main() {
	scanf("%d %d", &n, &m);
	all_sum = n;
	cnt_wa[0] = n;
	
	for(int i = 0; i < m; ++i) {
		read();
		int t = vote[getVote()] - '0';
		int result = write(t);
		update(result);
	}
	
	return 0;
}