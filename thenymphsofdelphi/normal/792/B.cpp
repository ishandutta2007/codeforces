#include<bits/stdc++.h>
using namespace std;

const int N = 200005;

int n, k;
int a[N], v[N];

void remove(int v[], int n, int x){
	for (int i = x; i < n; i++){
		v[i] = v[i + 1];
	}
}

int main(){
	cin >> n >> k;
	for (int i = 1; i <= k; i++){
		cin >> a[i];
	}
	for (int i = 0; i < n; i++){
		v[i] = i;
	}
	int cur = 0;
	for (int i = 1; i <= k; i++){
		cur = (cur + a[i]) % n;
		cout << v[cur] + 1 << " ";
		remove(v, n, cur);
		n--;
	}
}