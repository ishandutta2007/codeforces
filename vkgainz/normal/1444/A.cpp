#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int t; cin >> t;
    while(t--) {
        ll p;
        int q;
        cin >> p >> q;
        if(p%q) cout << p << endl;
        else {
            ll mn = 1e18;
            ll temp = p;
            for(int i=2;i*i<=q;i++) {
                if(q%i==0) {
                    int f1 = 0;
                    while(q%i==0) {
                        q/=i;
                        ++f1;
                    }
                    int f2 = 0;
                    while(p%i==0) {
                        p/=i;
                        ++f2;
                    }
                    mn = min(mn,(ll)pow(i,f2-f1+1));
                }
            }
            if(q>1) {
                int f = 0;
                while(p%q==0) {
                    p/=q;
                    ++f;
                }
                mn = min(mn,(ll) pow(q,f));
            }
            cout << temp/mn << endl;
        }
    }
}