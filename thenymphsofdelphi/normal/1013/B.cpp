#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, x, idx;
    cin >> n >> x;
    vector <int> a(n), b(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    for (int i = 1; i < n; i++){
        if (a[i] == a[i - 1]){
            cout << 0;
            return 0;
        }
    }
    for (int i = 0; i < n; i++){
    	b[i] = (a[i] & x);
    	//cout << b[i] << ' ';
    	if (b[i] == a[i]){
    		b[i] = -1;
		}
		//cout << b[i] << ' ';
	}
	sort(b.begin(), b.end());
	for (int i = 0; i < n; i++){
		if (b[i] == -1){
			continue;
		}
		int idx = lower_bound(a.begin(), a.end(), b[i]) - a.begin();
		//cout << idx << ' ' << a[idx] << ' ' << b[idx];
		if (idx == n || a[idx] != b[i]){
			continue;
		}
		cout << 1;
		return 0;
	}
	for (int i = 1; i < n; i++){
        if (b[i] == b[i - 1] && b[i] != -1){
            cout << 2;
            return 0;
        }
    }
    cout << -1;
}