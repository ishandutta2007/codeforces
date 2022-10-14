#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
    int n,ans,a,b,c,d,e,cur;
    cin>>a>>b>>c>>d>>e;
    
    if(b*a+2*d<c*a+2*e){
        cout<<"First";
    }
    else if(b*a+2*d>c*a+2*e){
        cout<<"Second";
    }else{
        cout<<"Friendship";
    }
    
    
    return 0;
}