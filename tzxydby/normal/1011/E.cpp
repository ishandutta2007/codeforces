#include <bits/stdc++.h>
using namespace std;
int n, k, g, a, i;
int main() {
    cin>>n>>k;g=k;
    for(i = 1;i <= n;i++) cin >> a,g=__gcd(a,g);
    cout<<k/g<<endl;
    for(i=0;i<k;i+=g) cout << i << " ";
    return 0;
}