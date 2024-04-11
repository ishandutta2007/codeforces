%:pragma GCC optimize(4)
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

#define int long long

const int N = 1000005;
const int K = 10000005;

int a[N] , n , m , ans , Num[N]  , res , pr[K / 10] , cnt , cnt1 , st[K] , S[K];
bool isp[K];

void prework() {
	int n = 10000000;
	memset(isp , 1 , sizeof(isp));
	isp[1] = 0;
	for(int i = 1;i <= n;i ++) {
		if(isp[i]) pr[++ cnt] = i;
		for(int j = 1;j <= cnt && pr[j] * i <= n;j ++) {
			isp[i * pr[j]] = 0;
			if(i % pr[j] == 0) break;
		}
	}
}

int calc(int x , int y) {
	int res = 0;
	while(x) {
		res += x / y;
		x /= y;
	}
	return res;
}

main(void) {
	prework();
	cin>>n;
	for(int i = 1;i <= n;i ++) scanf("%lld",&a[i]) , st[a[i]] ++;
	for(int i = 10000000;i >= 1;i --) {
		st[i - 1] += st[i];
	}
	for(int i = 1;i <= cnt;i ++) {
		int it = pr[i];
		int k = it;
		while(k <= 10000000) {
			for(int j = 2;j * k <= 10000000;j ++) st[k] += st[j * k];
			k *= it;
		}
	}
	ans = 1;
	for(int i = 1;i <= cnt;i ++) {
		int it = pr[i] , res = 0;
		for(int j = it;j <= 10000000;j *= it) {
			res += st[j];
		}
		
		if(!res) break;
		int l = 1 , r = 1e18 , ret = 1;
		while(l <= r) {
			int mid = (l + r) >> 1;
			if(calc(mid , pr[i]) >= res) {
				ret = mid; r = mid - 1;
			}
			else l = mid + 1;
		}
		ans = max(ans , ret);
	}
	cout<<ans<<endl;
}