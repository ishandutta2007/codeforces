#include <stdio.h>
#include <algorithm>
#include <utility>
#include <vector>
#include <iostream>
using namespace std;
int main() {
	int te;
	scanf("%d", &te);
	
	while(te--) {
		int n; scanf("%d", &n);
		vector<int> a(n);
		for(int &i : a) {
			scanf("%d", &i);
		}
		vector<int> b(n);
		for(int &i : b) {
			scanf("%d", &i);
		}

		for(int i = 0; i < n; i++) {
			if(a[i] < b[i]) swap(a[i], b[i]);
		}

		printf("%d\n", (*max_element(a.begin(),a.end())) * (*max_element(b.begin(),b.end())));
	}
}