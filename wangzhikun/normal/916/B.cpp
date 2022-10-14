//
//  main.cpp
//  Codeforces
//
//  Created by  on 2018/1/19.
//  Copyright  2018 . All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
ll lpow(int n){
    ll a = 1;
    for(int i=0;i<n;i++){
        a*=2;
    }
    return a;
}
int main() {
    ll q[200] = {0};
    ll n,k,sn = 0;
    cin>>n>>k;
    for(int i = 62;i>=0;i--){
        if(lpow(i) <= n){
            //cout<<i<<endl;
            n-= lpow(i);
            q[i+50] = 1;
            sn+=1;
        }
    }
    if(sn>k){
        cout<<"No"<<endl;
        return 0;
    }
    cout<<"Yes"<<endl;
    for(int i = 62;i>=-30;i--){
        if(q[i+50]>0 && k-sn>=q[i+50]){
            q[i+50-1]+=2*q[i+50];
            sn+=q[i+50];
            q[i+50] = 0;
        }else{
            if(q[i+50]>0 && k-sn<q[i+50]){
                break;
            }
        }
    }
    int ln;
    if(k-sn>0)for(int i = -30;i<=62;i++){
        if(q[i+50]>0 && k-sn>0){
            q[i+50]-=1;
            ln = i-1;
            sn-=1;
            break;
        }
    }
    for(int i = 62;i>=-30;i--){
        if(q[i+50]>0){
            for(int j=0;j<q[i+50];j++)cout<<i<<' ';
        }
    }
    if(k-sn>0){
        for(int i=0;i<k-sn-1;i++){
            cout<<ln-i<<" ";
        }
        cout<<ln-(k-sn-2);
    }
    return 0;
}