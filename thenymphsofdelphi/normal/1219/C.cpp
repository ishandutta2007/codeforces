#include<bits/stdc++.h>
using namespace std;
#define ll long long
signed main(){
    ll n, i;
    string x, res = "", c;
    cin>>n;
    cin>>x;
    ll a = x.length();
    if(a%n==0){
        c = x.substr(0, n);
        string ck="";
        for(i=1; i<=a/n; i++){
            ck += c;
        }
        ll b=ck.compare(x);
        if(b>0){
            cout<<ck;
        }
        else{
            int idx = c.length() - 1;
            while (idx >= 0){
                if (c[idx] < '9'){
                    c[idx]++;
                    break;
                }
                c[idx] = '0';
                idx--;
            }
            if (idx == -1){
                c = '1' + c;
                c.pop_back();
                for (int i = 0; i <= a / n; i++){
                    cout << c;
                }
                return 0;
            }
            //cout << c << endl;
            for (int i = 1; i <= a / n; i++){
                cout << c;
            }
        }
    }
    else{
        ll fren = a/n+1; 
        for(i=0; i<n; i++){
            if(i%n==0){
                res+='1';
            }
            else{
                res+='0';
            }
        }
        for(i=0; i<fren; i++){
            cout<<res;
        }
    }
}