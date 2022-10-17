#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        int s=0;
        for(int i=0;i<n;++i) cin>>a[i],s+=a[i];
        if(s==n) {
            cout<<0<<endl;
        } else if(s>n) {
            cout<<s-n<<endl;
        } else {
            cout<<1<<endl;
        }
    }
}