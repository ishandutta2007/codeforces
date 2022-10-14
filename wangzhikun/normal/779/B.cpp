//
//  main.cpp
//  Problem2
//
//  Created by  on 2017/3/23.
//  Copyright  2017 . All rights reserved.
//

#include <iostream>
using namespace std;
int main() {
    string a;
    int b,i,ans = 0,cs=0,nans = 0;
    cin>>a>>b;
    ans = a.length()-1;
    if(b>a.length()){
        cout<<ans;
        return 0;
    }
    for(i=a.length()-1;i>=0;i--){
        if(a[i] == '0') cs+=1;
        else nans+=1;
        if(cs >= b){
            ans = min(ans,nans);
            break;
        }
    }
    cout<<ans<<endl;
    return 0;
}