#include<bits/stdc++.h>

typedef long long ll;
using namespace std;

int solve(int n, int k) {
    --k;
    if(n % 2 == 0) return k%n;
    return (k+k/(n/2))%n;
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n,k;
        cin>>n>>k;
        if(n%2==0) cout<<(k-1)%n+1<<endl;
        else cout<<(k-1+(k-1)/(n/2))%n+1<<endl;
    }
}