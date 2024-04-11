#include<bits/stdc++.h>
#define int long long
using namespace std;


const int maxn=200007;
int n;
int x[maxn],y[maxn];

#undef int
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>x[i]>>y[i];
    }
    if (n&1){
        cout<<"NO"<<endl;
        return 0;
    }
    for (int i=1;i<n/2;++i){
        if (x[i]-x[i+1]+x[n/2+i]-x[n/2+i+1]){
            cout<<"NO";
            return 0;
        }
        if (y[i]-y[i+1]+y[n/2+i]-y[n/2+i+1]){
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES\n";
    return 0;
}