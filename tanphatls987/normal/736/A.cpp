#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll f[1000];
int main(){
    ll n;
    cin>>n;
    f[0]=1;f[1]=2;
    int n1=1;
    while (f[n1]<=n){
        n1++;
        f[n1]=f[n1-1]+f[n1-2];
    }
    cout<<n1-1;
}