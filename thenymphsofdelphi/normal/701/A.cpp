#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, sum = 0;
    cin >> n;
    int a[n];
    bool b[n];
    memset(b, 0, sizeof(b));
    for (int i = 0; i < n; i++){
    	cin >> a[i];
    	sum += a[i];
	}
	sum = sum * 2 / n;
	for (int i = 0; i < n; i++){
		if (b[i] == true){
			continue;
		}
		b[i] = true;
		for (int j = 0; j < n; j++){
			if (!b[j] && a[j] == sum - a[i]){
				cout << i + 1 << " " << j + 1 << endl;
				b[j] = true;
				break;
			}
		}
	}
}