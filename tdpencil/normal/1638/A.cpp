#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int t;
	scanf("%d", &t);

	while(t--) {
		static int a[500];
		int n;
		scanf("%d", &n);
		int first = n - 1;
		for(int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		for(int i = 0; i < n; i++) {
			if(i + 1 != a[i]) { first = i; break; } }
		int last = n - 1;
		for(int i = first + 1; i < n; i++) {
			if(a[i] == first + 1) {last = i; break;}
		}
		for(int i = 0; i < (last - first + 2) / 2; i++) {
			swap(a[i+first], a[last-i]);
		}
		for(int i = 0; i < n; i++) {
			printf("%d ", a[i]);
		}
		printf("\n");
	}
}