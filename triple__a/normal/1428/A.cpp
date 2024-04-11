#include<bits/stdc++.h>
using namespace std;

int t;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>t;
    while (t--){
        int a,b,c,d;
        cin>>a>>c>>b>>d;
        int res=abs(b-a)+abs(d-c);
        if (res){
            if (b!=a&&d!=c) res+=2;
        }
        cout<<res<<"\n";
    }
}