#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    if(n-m>=m){
    cout<<max(1,m);
    }
    else{
        cout<<n-m;
    }
    
   // cout<<count;
    
}