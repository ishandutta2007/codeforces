#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;std::cin>>n;
    int ans=0;
    while(n--){
        int x;cin>>x;
        ans+=abs(x);
    }
    cout<<ans<<endl;
}