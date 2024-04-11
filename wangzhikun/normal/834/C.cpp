//
//  main.cpp
//  Round426
//
//  Created by  on 2017/7/30.
//  Copyright  2017 . All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;
long long n,a,b,c,d,f;
double e;
bool ans;
int rea(){
    int x=0;char c=getchar();
    while(c<'0' || c>'9')c=getchar();
    while(c>='0' && c<='9'){
        x=x*10+c-'0';
        c=getchar();
    }
    return x;
}
int cbrt(long long num){
    long long c = 1200000,b=600000,a=0;
    while(c-a>1){
        long long t = b*b*b;
        if(t>num){
            c=b;
        }else if(t<num){
            a=b;
        }
        else{
            return b;
        }
        b=(c+a)/2;
    }
    return -1;
}
int main() {
    cin>>n;
    for(int i=0;i<n;i++){
        ans = true;
        a = rea();b = rea();
        e = cbrt(a*b);
        c = a/e;d=b/e;
        ans = d*c*c == a && c*d*d == b;
        if(e == -1) ans = false;
        if(ans) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}