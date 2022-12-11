#include<bits/stdc++.h>
using namespace std;
int a,b,c;
int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>a>>b>>c;
        int x,y=b,z=c;
        x=(c-a+b)/b*b+a;
        cout<<x<<' '<<y<<' '<<z<<endl;
    }
    return  0;
}