#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, a, b;
	cin >> n >> a >> b;
	int r = max(a + 1, n - b);
	cout << n - r + 1;
}