#include <bits/stdc++.h>
using namespace std;
#define ll long long
int basis[31];
int sz;
void insert(int msk) {
    for(int i=0;i<31;i++) {
        if((msk&(1<<i))==0) continue;
        if(!basis[i]) {
            basis[i] = msk;
            ++sz;
            return;
        }
        msk^=basis[i];
    }
}
int main() {
    int n; cin >> n;
    int a[n];
    int x =0;
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) {
        insert(a[i]);
        x^=a[i];
    }
    if(x==0) cout << -1;
    else cout << sz;
}