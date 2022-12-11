#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=1e2+10;
int n;
string s[N];
int main() {
    cin>>n;
    for(int i=1;i<=n;i++) cin>>s[i];
    for(int i=1;i<=n;i++){
        bool okay=0;
        for(int j=1;j<i;j++) okay|=s[j]==s[i];
        if (okay) cout<<"YES\n";
        else cout<<"NO\n";
    }
}