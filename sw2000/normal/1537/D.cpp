#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
const int N=5e5+10;
const int mod=1e9+7;

int main(){
//    freopen("A.in","r",stdin);
    int _;cin>>_;
    while(_--){
        int a;cin>>a;
        if(a%2||!(a&a-1)&&__builtin_ctz(a)%2)cout<<"Bob\n";
        else cout<<"Alice\n";
    }
}