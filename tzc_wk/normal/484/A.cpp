#include <bits/stdc++.h>
using namespace std ;
#define lint long long 
lint n,l,r;
int main(){
    cin>>n;
    while(n--){
        cin>>l>>r;
        for(lint i=0;;i++){
            if((l|(1ll<<i))>r) break ;
            l|=(1ll<<i) ;
        } 
        cout<<l<<endl;
    } 
    return 0 ;
}