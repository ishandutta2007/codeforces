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
    int cnt = 0;
    for(int i=1;i<n-1;i+=2)
        if(res[i]<res[i-1] && res[i]<res[i+1]) ++cnt;
    cout << cnt << endl;
    for(int i=0;i<n;i++)
        cout << res[i] << " ";
}