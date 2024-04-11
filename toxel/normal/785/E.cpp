#include<bits/stdc++.h>
#define ll long long

const int N = 200010;
const int M = 500;

int a[N], cnt[M][M], l[M], r[M];
int n, q, m;

int query(int i, int x){
	int left = l[i] % m, right = r[i] % m;
	while (left < right){
		int mid = left + right + 1 >> 1;
		if (cnt[i][mid] > x){
			right = mid - 1;
		}
		else{
			left = mid;
		}
	}
	return cnt[i][left] < x ? left + 1 : 0;
}

void change(int i, int sit, int value){
	cnt[i][sit] = value;
	while (sit && cnt[i][sit] < cnt[i][sit - 1]){
		std::swap(cnt[i][sit], cnt[i][sit - 1]);
		-- sit;
	}
	while (sit < r[i] % m && cnt[i][sit] > cnt[i][sit + 1]){
		std::swap(cnt[i][sit], cnt[i][sit + 1]);
		++ sit;
	}
}

int main(){
	scanf("%d%d", &n, &q);
	m = sqrt(n);
	for (int i = 0; i < n; i += m){
		l[i / m] = i;
		r[i / m] = i + m >= n ? n - 1 : i + m - 1;
		for (int j = i; j <= r[i / m]; ++ j){
			cnt[i / m][j % m] = a[j] = j + 1;
		}
	}
	ll ans = 0;
	while (q --){
		int left, right;
		scanf("%d%d", &left, &right);
		if (left == right){
			printf("%I64d\n", ans);
			continue;
		}
		-- left, -- right;
		if (left > right){
			std::swap(left, right);
		}
		int sit1 = left / m, sit2 = right / m, cnt1 = 0, cnt2 = 0;
		a[left] > a[right] ? -- ans : ++ ans;
		if (sit2 == sit1){
			for (int i = left + 1; i < right; ++ i){
				if (a[i] < a[left]){
					++ cnt1;
				}
				if (a[i] < a[right]){
					++ cnt2;
				}
			}
			ans += cnt2 - cnt1 << 1;
			std::swap(a[left], a[right]);
			printf("%I64d\n", ans);
			continue;
		}
		for (int i = left + 1; i <= r[sit1]; ++ i){
			if (a[i] < a[left]){
				++ cnt1;
			}
			if (a[i] < a[right]){
				++ cnt2;
			}
		}
		for (int i = l[sit2]; i < right; ++ i){
			if (a[i] < a[left]){
				++ cnt1;
			}
			if (a[i] < a[right]){
				++ cnt2;
			}
		}
		for (int i = sit1 + 1; i < sit2; ++ i){
			cnt1 += query(i, a[left]);
			cnt2 += query(i, a[right]);
		}
		ans += cnt2 - cnt1 << 1;
		std::swap(a[left], a[right]);
		printf("%I64d\n", ans);
		for (int i = 0; i <= r[sit1]; ++ i){
			if (cnt[sit1][i] == a[right]){
				change(sit1, i, a[left]);
				break;
			}
		}
		for (int i = 0; i <= r[sit2]; ++ i){
			if (cnt[sit2][i] == a[left]){
				change(sit2, i, a[right]);
				break;
			}
		}
	}
	return 0;
}