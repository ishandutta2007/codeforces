#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n,x,a,b;
        cin >> n >> x >> a >> b;
        if(a>b) swap(a,b);
        int c = min(x,a-1);
        x-=c;
        a-=c;
        c = min(x,n-b);
        b+=c;
        x-=c;
        cout << (b-a) << endl;
    
    }
}