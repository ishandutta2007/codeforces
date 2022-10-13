#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    int a[n];
    for(int i=0;i<n;i++) cin >> a[i];
    sort(a,a+n);
    vector<int> res;
    res.assign(n,0);
    for(int i=0;i<(n)/2;i++){
        res[2*i+1] = a[i];
    }
    for(int i=(n)/2;i<n;i++){
        res[(i-n/2)*2] = a[i];
    }
    cout << (n-1)/2 << endl;
    for(int i=0;i<n;i++)
        cout << res[i] << " ";
}