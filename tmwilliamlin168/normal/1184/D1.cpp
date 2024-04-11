#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k,m,t;
int main(){
    ios::sync_with_stdio(false);
    cin >> n >> k >> m >> t;
    for(int i=1; i<=t ;i++){
        int ti,pi;
        cin >> ti >> pi;
        if(ti==1){
            if(pi<=k) k++;
            n++;
        }
        else{
            if(pi<k){
                k-=pi;
                n-=pi;
            }
            else n=pi;
        }
        cout << n << ' ' << k << endl;
    }
}