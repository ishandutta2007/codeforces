#include<bits/stdc++.h>

const int N = 110;

int n, k;
char s[N];

int main(){
	scanf("%d%d%s", &n, &k, s);
	int begin, end;
	for (int i = 0; i < n; ++ i){
		if (s[i] == 'G'){
			begin = i;
		}
		if (s[i] == 'T'){
			end = i;
		}
	}
	if (begin > end){
		std::swap(begin, end);
	}
	if ((end - begin) % k){
		return printf("NO\n"), 0;
	}
	for (int i = begin; i <= end; i += k){
		if (s[i] == '#'){
			return printf("NO\n"), 0;
		}
	}
	return printf("YES\n"), 0;
}