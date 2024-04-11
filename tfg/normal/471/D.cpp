#include <iostream>
#include <cstdio>

const int ms = 200200;

int pat[ms];
int border[ms];
int a[ms];

int main() {
	int n, w;
	std::cin >> n >> w;
	if(w == 1) {
		std::cout << n << '\n';
		return 0;
	}
	for(int i = 0; i < n; i++) {
		scanf("%d", a + i);
	}
	for(int i = 0; i < w; i++) {
		scanf("%d", pat + i);
	}
	w--;
	border[0] = -1;
	for(int i = 0, j = -1; i < w; i++) {
		pat[i] = pat[i + 1] - pat[i];
		if(i == 0) continue;
		while(j >= 0 && pat[j + 1] != pat[i]) {
			j = border[j];
		}
		if(pat[j + 1] == pat[i]) {
			j++;
		}
		border[i] = j;
	}
	n--;
	int ans = 0;
	for(int i = 0, j = -1; i < n; i++) {
		a[i] = a[i + 1] - a[i];
		while(j >= 0 && pat[j + 1] != a[i]) {
			j = border[j];
		}
		if(pat[j + 1] == a[i]) {
			j++;
		}
		if(j == w - 1) {
			ans++;
			j = border[j];
		}
	}
	//for(int i = 0; i < w; i++) std::cout << pat[i] << (i + 1 == w ? '\n' : ' ');
	//for(int i = 0; i < w; i++) std::cout << border[i] << (i + 1 == w ? '\n' : ' ');
	//for(int i = 0; i < n; i++) std::cout << a[i] << (i + 1 == n ? '\n' : ' ');
	std::cout << ans << '\n';
}