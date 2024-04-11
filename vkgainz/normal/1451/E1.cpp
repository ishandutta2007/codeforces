#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
const int MX = 2e5+5;
int an(int i, int j) {
    cout << "AND " << i << " " << j << "\n";
    cout << flush;
    int r; cin >> r;
    return r;
}
int o(int i, int j) {
    cout << "OR " << i << " " << j << "\n";
    cout << flush;
    int r; cin >> r;
    return r;
}
int x(int i, int j) {
    cout << "XOR " << i << " " << j << "\n";
    cout << flush; 
    int r; cin >> r;
    return r;
}
int main() {
    int n; cin >> n;
    int a[n];
    memset(a,0,sizeof(a));
    int r1 = an(1, 2);
    int r2 = o(1, 2);
    int r3 = o(1, 3);
    int r4 = o(2, 3);
    int r5 = x(2, 3);
    for(int msk=0;msk<16;msk++) {
        if(r1&(1<<msk)) {
            a[0]+=1<<msk;
            a[1]+=1<<msk;
        }
        else if((r2&(1<<msk))==0) {
            a[0]+=0;
            a[1]+=0;
        }
        else {
             if((r3&(1<<msk))==0 || (r4&(1<<msk))==0) {
                if((r3&(1<<msk))==0) a[1]+=1<<msk;
                else a[0]+=1<<msk;
             }
             else {
                 if((r5&(1<<msk))==0) {
                     a[1]+=1<<msk;
                 }
                 else {
                     a[0]+=1<<msk;
                 }
             }
        }
    }
    a[2] = a[1]^r5;
    for(int i=3;i<n;i++) {
        int curr = x(i+1, i);
        a[i] = a[i-1]^curr;
    }
    cout << "! ";
    for(int i=0;i<n;i++) cout << a[i] << " ";
    cout << "\n";
    cout << flush;
    return 0;
}