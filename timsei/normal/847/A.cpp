#include<bits/stdc++.h>
using namespace std;

const int N = 100005;

int beg[N] , en[N]  , L[N] , R[N] , n , cnt;

int main(void) {
    cin>>n;
    for(int i = 1;i <= n;i ++) cin>>L[i] >> R[i];
    for(int i = 1;i <= n;i ++) if(!L[i]) {
        int p = i;
        beg[++ cnt] = i; while(R[p]) p = R[p];
        en[cnt] = p;
    }
    for(int i = 1;i <= cnt - 1;i ++) {
        R[en[i]] = beg[i + 1]; L[beg[i + 1]] = en[i];
    }
    for(int i = 1;i <= n;i ++) cout<<L[i] <<" "<<R[i] <<endl;
}