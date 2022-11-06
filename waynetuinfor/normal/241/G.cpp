#include<bits/stdc++.h>
using namespace std;

int main(){
    cout<<402<<endl;
    int totx=45000,nowr=500;
    cout<<0<<" "<<1000000<<endl;
    for(int i=2;i<=401;++i){
        cout<<totx<<" "<<nowr<<endl;
        totx+=nowr*2;
        --nowr;
    }
    cout<<totx+30000<<" "<<1000000<<endl;
}