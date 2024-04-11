#include<bits/stdc++.h>

const int N = 1010;

int n;
int a[N], b[N];
std::set <int> set;

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; ++ i){
		scanf("%d", &a[i]);
	}
	int sit1 = -1, sit2 = -1;
	for (int i = 0; i < n; ++ i){
		scanf("%d", &b[i]);
		if (b[i] != a[i]){
			~sit1 ? sit2 = i : sit1 = i;
		}
	}
	if (~sit2){
		for (int i = 0; i < n; ++ i){
			if (i != sit1 && i != sit2){
				set.insert(a[i]);
			}
		}
		int x = -1, y = -1;
		for (int i = 1; i <= n; ++ i){
			if (!set.count(i)){
				~x ? y = i : x = i;
			}
		}
		int cnt1 = (a[sit1] != x) + (a[sit2] != y);
		int cnt2 = (b[sit1] != x) + (b[sit2] != y);
		if (cnt1 == 1 && cnt2 == 1){
			a[sit1] = x;
			a[sit2] = y;
		}
		else{
			a[sit1] = y;
			a[sit2] = x;
		}
	}
	else{
		for (int i = 0; i < n; ++ i){
			if (i != sit1){
				set.insert(a[i]);
			}
		}
		for (int i = 1; i <= n; ++ i){
			if (!set.count(i)){
				a[sit1] = i;
			}
		}
	}
	for (int i = 0; i < n; ++ i){
		printf("%d%c", a[i], " \n"[i == n - 1]);
	}
	return 0;
}