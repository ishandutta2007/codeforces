#include <bits/stdc++.h>

using namespace std;

int a[10];

int main() {
	
	int v;
	scanf("%d", &v);
	
	for (int i = 1; i <= 9; i++)
		scanf("%d", &a[i]);
	
	int mx = 0;
	for (int i = 1; i <= 9; i++)
		mx = max(mx, v / a[i]);
	
	if (mx == 0) return printf("-1"), 0;
	
	char s[mx];
	for (int i = 9; i >= 1; i--)
		if (v / a[i] == mx)
			for (int j = 0; j < mx; j++)
				s[j] = (char) ('0' + i);
	
	v -= mx * (a[s[0] - '0']);
	
	for (int i = 0; i < mx; i++)
		for (int j = 9; j >= 1; j--) {
			int dig = s[i] - '0';
			
			if (v + a[dig] >= a[j]) {
				v += a[dig];
				v -= a[j];
				
				s[i] = (char) ('0' + j);
				break;
			}
		}
				
	
	for (int i = 0; i < mx; i++)
		printf("%c", s[i]);
		
	return 0;
}