#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main(){
    int t; cin >> t;
    while(t--){
        long long c,m,x;
        cin >> c >> m >> x;
        if(c>m) swap(c,m);
        cout << min(c,(c+m+x)/3) << endl;
    }
}