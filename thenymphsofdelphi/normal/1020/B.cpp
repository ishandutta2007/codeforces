#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define pb push_back
#define mp make_pair

signed main(){
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++){
	    cin >> a[i];
	    a[i]--;
	}
	for (int i = 0; i < n; i++){
	    bool ck[n];
	    memset(ck, 0, sizeof(ck));
	    int j = i;
	    do{
	        ck[j] = 1;
	        j = a[j];
	    } while (!ck[j]);
	    cout << j + 1 << ' ';
	}
}