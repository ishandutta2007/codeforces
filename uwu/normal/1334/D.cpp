#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;


int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        ll n,l,r; cin >> n >> l >> r;
        ll uwu=2*(n-1),block=1;
        while (uwu>0){
            if (!(l<=uwu&&l>0)){
                l-=uwu; r-=uwu;
                uwu-=2; block++;
                continue;
            }
            for (ll i=l;i<=min(uwu,r);++i){
                if (i%2==1) cout << block << " ";
                else{
                    cout << (ll)((i+block*2)/2) << " ";
                }
            }
            l=1; r-=uwu;
            uwu-=2; block++;
            //cout << "AAA";
        }
        if (r==1) cout << 1 << " ";
        cout << '\n';
    }   

}