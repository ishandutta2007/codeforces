#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    while (n--){
        long long u;
        cin>>u;
        if (u>=14&&u%14>=1&&u%14<=6) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}