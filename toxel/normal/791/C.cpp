#include<bits/stdc++.h>

const int N = 60;
const int M = 26;

int a[N], ans[N], cnt[N];
int n, k;
char s[N];

int main(){
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n - k + 1; ++ i){
		scanf("%s", s);
		a[i] = s[0] == 'Y';
	}
	for (int i = 1; i < k; ++ i){
		ans[i] = i;
	}
	for (int i = 1; i <= n - k + 1; ++ i){
		if (a[i]){
			memset(cnt, 0, sizeof(cnt));
			for (int j = i; j < i + k; ++ j){
				++ cnt[ans[j]];
			}
			for (int j = 1; j <= k; ++ j){
				if (!cnt[j]){
					ans[i + k - 1] = j;
					break;
				}
			}
		}
		else{
			ans[i + k - 1] = ans[i];
		}
	}
	for (int i = 1; i <= n; ++ i){
		std::string str = "";
		str += 'A' + ans[i] % M;
		str += 'a' + ans[i] / M;
		std::cout << str << ' ';
	}
	std::cout << std::endl;
	return 0;
}