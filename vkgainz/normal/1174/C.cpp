#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int n; cin >> n;
    int a[n+2];
    memset(a,-1,sizeof(a));
    int cnt = 1;
    for(int i=2;i<=n;i++) {
        if(a[i]==-1) {
            a[i] = cnt++;
            for(ll j=i*1LL*i;j<=n;j+=i) {
                if(a[j]==-1) a[j] = a[i];
            }
        }
    }
    for(int i=2;i<=n;i++) cout << a[i] << endl;
}