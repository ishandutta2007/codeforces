#include<bits/stdc++.h>
using namespace std;
#define int long long

int n, k;

int cal(int l, int r, int lev){
    int mid = (l + r) / 2;
    if (k == mid || lev == 1 || l == r){
        return lev;
    }
    if (k > mid){
        return cal(mid + 1, r, lev - 1);
    }
    else{
        return cal(l, mid - 1, lev - 1);
    }
}

signed main(){
    cin >> n >> k;
    cout << cal(1, (long long)(1LL << n) - 1, n);
}