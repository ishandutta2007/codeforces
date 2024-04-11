#include<bits/stdc++.h>

const int N = 62;
typedef long long ll;

void mod(ll &a, ll moder){
	a &= moder - 1;
}

ll offset[N];

int main(){
	int q;
	scanf("%d", &q);
	while (q --){
		int type;
		scanf("%d", &type);
		if (type == 1){
			ll x, k;
			scanf("%I64d%I64d", &x, &k);
			int level = 0;
			while (x){
				x >>= 1;
				++ level;
			}
			offset[level] += k;
			mod(offset[level], 1ll << level - 1);
		}
		else if (type == 2){
			ll x, k;
			scanf("%I64d%I64d", &x, &k);
			int level = 0;
			while (x){
				x >>= 1;
				++ level;
			}
			mod(k, 1ll << level - 1);
			for (int i = level; i < N; ++ i){
				offset[i] += k << i - level;
				mod(offset[i], 1ll << i - 1);
			}
		}
		else{
			ll x;
			scanf("%I64d", &x);
			int level = 0;
			ll xx = x;
			while (xx){
				xx >>= 1;
				++ level;
			}
			while (true){
				printf("%I64d ", x);
				if (level <= 1){
					break;
				}
				x -= 1ll << level - 1;
				x += offset[level];
				mod(x, 1ll << level - 1);
				x += 1ll << level - 1;
				x >>= 1;
				x -= offset[level - 1];
				mod(x, 1ll << level - 2);
				x += 1ll << level - 2;
				-- level;
			}
			putchar('\n');
		}
	}
	return 0;
}