#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int t; cin >>t;
    while(t--){
        ll n,k;
        cin >> n >> k;
        ll step = 0;
        while(n>0){
            if(n%k ==0 ){
                n/=k;
                ++step;
            }
            else{
                step+=n%k;
                n = n-n%k;
            }
        }
        cout << step << endl;
    }
}