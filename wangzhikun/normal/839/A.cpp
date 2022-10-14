#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
    int n,ans = 0,a,b = 0,c,d,e,cur;
    cin>>n>>a;
    
    for(int i=0;i<n;i++){
        cin>>cur;
        b+=cur;
        if(b>8){
            ans+=8;
            b-=8;
        }else{
            ans+=b;
            b=0;
        }
        if(ans>=a){
            cout<<i+1<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
    
    return 0;
}