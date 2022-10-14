//
//  main.cpp
//  Codeforces462
//
//  Created by  on 2018/2/14.
//  Copyright  2018 . All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
int main() {
    ll n;
    cin>>n;
    if(n>36) {
        cout<<"-1"<<endl;
    }else{
        for(int i=0;i<n/2;i++)cout<<8;
        if(n%2)cout<<4;
    }
    return 0;
}