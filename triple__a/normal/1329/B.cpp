#include<bits/stdc++.h>
#define int long long
using namespace std;


int d,m;

signed main(){
    int _;
    cin>>_;
    while(_--){
        int res=1;
        cin>>d>>m;
        for (int i=1;;i*=2){
            if (i>d) break;
            res=res*(min(i+1,d-i+2))%m;
        }
        cout<<(res-1+m)%m<<"\n";
    }
    return 0;
}