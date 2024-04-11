#include<bits/stdc++.h>
#define ll long long

const int N = 50;

std::map <ll, int> Hash;
int n;
int cnt1[N], cnt2[N], cnt3[N];

int logg(ll n){
	int ret = 0;
	for (ll x = 1; x < n; x <<= 1, ++ ret);
	return ret;
}

int main(){
	for (ll x = 1, cnt = 0; cnt <= N; ++ cnt, x <<= 1){
		Hash[x] = cnt;
	}
	scanf("%d", &n);
	for (int i = 0; i < n; ++ i){
		ll x;
		scanf("%I64d", &x);
		if (Hash.count(x)){
			++ cnt1[Hash[x]];
		}
		else{
			++ cnt2[logg(x) - 1];
		}
	}
	bool _flag = false;
	for (int i = 1; i <= n; ++ i){
		if (cnt1[0] < i){
			break;
		}
		int max = i;
		memset(cnt3, 0, sizeof(cnt3));
		for (int j = 0; j < N - 1; ++ j){
			if (cnt1[j] > max){
				cnt3[j] += cnt1[j] - max;
				cnt2[j] += cnt3[j];
				cnt1[j] = max;
			}
			else{
				max = cnt1[j];
			}
		}
		int nowcnt = 0;
		bool flag = true;
		for (int j = N - 2; j >= 0; -- j){
			nowcnt += cnt1[j] - cnt1[j + 1] - cnt2[j];
			if (nowcnt < 0){
				flag = false;
				break;
			}
		}
		if (flag){
			printf("%d ", i);
			_flag = true;
		}
		for (int j = 0; j < N; ++ j){
			cnt1[j] += cnt3[j];
			cnt2[j] -= cnt3[j];
		}
	}
	if (!_flag){
		printf("-1");
	}
	putchar('\n');
	return 0;
}