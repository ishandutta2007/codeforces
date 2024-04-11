#include <bits/stdc++.h>

using namespace std;

int main(){
    int a,b,c,d;
    cin>>b>>a>>c>>d;
    int use=min(min(c,d),b);
    int ans=use*256;
    ans+=32*min(b-use,a);
    cout<<ans;
}