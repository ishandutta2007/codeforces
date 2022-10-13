#include <bits/stdc++.h>
using namespace std;
int t;

int main(){
    cin >> t;
    while(t--){
        int l,r;
        long long m;
        cin >> l >> r >> m;
        long long high = m+r-l;
        long long low = m+l-r;
        for(int a=l;a<=r;a++){
            if(high>=a && high%a==0){

                cout << a << " " <<  l << " " <<  r << endl;
                break;
            }
            else if(low>=a && low%a==0){
                cout << a << " " <<  r << " " <<  l << endl;
                break;
            }
            else{
                if(high/a != low/a){
                    if(high/a>0){
                        long long tot = a*(high/a);
                        if(tot>=m)
                        cout << a << " " << l << " " << l+tot-m << endl;
                        else
                            cout << a << " " << r << " " <<  tot+r-m << endl;
                        
                        break;
                    }
                }
            }
        }
        
    }
}