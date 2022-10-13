#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int n,m; cin >> n >> m;
    int b[n];
    ll sum = 0;
    for(int i=0;i<n;i++) cin >> b[i];
    for(int i=0;i<n;i++) sum+=b[i];
    sum = sum*1LL*m;
    int g[m];
    for(int i=0;i<m;i++){
        cin >> g[i];
    }
    sort(b,b+n);
    sort(g,g+m);
    if(g[0]<b[n-1]){
        cout << -1 << endl;
    }
    else{
        if(g[0]==b[n-1]){
            for(int i=0;i<m;i++)
                sum+=g[i]-b[n-1];
        }
        else{
            for(int i=0;i<m;i++)
                sum+=g[i]-b[n-1];
            sum+=b[n-1]-b[n-2];
        }
        cout << sum << endl;
    }
}