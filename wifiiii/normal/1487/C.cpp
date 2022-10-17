#include<bits/stdc++.h>

typedef long long ll;
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        if(n % 2) {
            for(int i=1;i<=n*(n-1)/2;++i) {
                if(i&1) cout<<1<<" ";
                else cout<<-1<<" ";
            }
            cout<<endl;
        } else {
            int f=1;
            for(int i=1;i<=n;++i) {
                for(int j=i+1;j<=n;++j) {
                    if(((i-1)^(j-1))==1) cout<<0<<" ";
                    else cout<<f<<" ",f=-f;
                }
                f=-f;
            }
            cout<<endl;
        }
    }
}