#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int a,b,c;
        cin>>a>>b>>c;
        puts((a==b+c||b==a+c||c==a+b)||(a==b&&!(c&1))||(c==b&&!(a&1))||(a==c&&!(b&1))?"YES":"NO");
    }
    return  0;
}