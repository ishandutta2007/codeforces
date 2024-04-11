#include<bits/stdc++.h>

const int N = 300010;

int father[N], size[N];

int find(int u){
	return u == father[u] ? u : (father[u] = find(father[u]));
}

int main(){
	int n;
	scanf("%d", &n);
	printf("%d ", 1);
	for (int i = 0, x; i < n; ++ i){
		scanf("%d", &x);
		father[x] = x;
		size[x] = 1;
		int left = find(x - 1);
		int right = find(x + 1);
		if (left){
			father[x] = left;
			size[left] += size[x];
			x = find(x);
		}
		if (right){
			father[x] = right;
			size[right] += size[x];
			x = find(x);
		}
		printf("%d%c", i - size[find(n)] + 2, " \n"[i == n - 1]);
	}
	return 0;
}