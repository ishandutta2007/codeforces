#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;

int N;
int ss[220];
int ds[220];

long long ls[220], rs[220];
int c;

bool check(long long s, long long d){
	long long L = s, R = s + d - 1;
	int id = lower_bound(ls, ls + c, s) - ls;
	if(ls[id] <= R) return false;
	if(rs[id - 1] >= L) return false;
	return true;
}

long long find(long long d){
	for(int i = 0; i + 1 < c; ++i){
		long long tmp_l = rs[i] + 1;
		long long tmp_r = ls[i + 1] - 1;
		if(tmp_r - tmp_l + 1 >= d) return tmp_l;
	}
	return -1;
}

void ins(long long le, long long ri){
	ls[c] = le, rs[c] = ri;
	c++;
	sort(ls, ls + c);
	sort(rs, rs + c);
}

void solve(){
	ls[0] = 0, rs[0] = 0;
	ls[1] = 1ll << 50, rs[1] = 1ll << 50;
	c = 2;
	for(int i = 0; i < N; ++i){
		bool flg = check(ss[i], ds[i]);
		long long ans_le = -1, ans_ri = -1;
		if(flg){
			ans_le = ss[i], ans_ri = ss[i] + ds[i] - 1;
		}else{
			ans_le = find(ds[i]);
			ans_ri = ans_le + ds[i] - 1;
		}
		ins(ans_le, ans_ri);
		cout << ans_le << " " << ans_ri << "\n";
	}
}

void input(){
	scanf("%d", &N);
	for(int i = 0; i < N; ++i){
		scanf("%d%d", ss + i, ds + i);
	}
}

int main(){
	input();
	solve();
	return 0;
}