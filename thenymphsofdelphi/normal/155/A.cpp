#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie();
	int n, x, minx, maxx, count = 0;
	cin >> n;
	cin >> x;
	int i;
	minx = x;
	maxx = x;
	for (i = 1; i <= n; i++){
		cin >> x;
		if (x < minx){
			count++;
			minx = x;
		}
		else if (x > maxx){
			count++;
			maxx = x;
		}
	}
	cout << count;
}