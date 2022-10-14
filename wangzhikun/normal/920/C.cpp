//
//  main.cpp
//  Codeforces
//
//  Created by  on 2018/1/19.
//  Copyright  2018 . All rights reserved.
//
//#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
typedef int ll;
ll read(){
    char ch = getchar();
    ll an = 0;
    while(ch>'9'||ch<'0')ch = getchar();
    while(ch>='0'&&ch<='9'){
        an = an*10+ch-'0';
        ch = getchar();
    }
    return an;
}
ll rec[200010],lb = -1,cs = 1000000,cb = 0,ans = 1;
char qh;
int main() {
    ll n=read();
    for(int i=0;i<n;i++) rec[i] = read();
    while(qh>'1'||qh<'0')qh = getchar();
    for(int i=0;i<n;i++){
        cs = min(cs,rec[i]);
        cb = max(cb,rec[i]);
        if(qh == '0'){
            if(!(cs==lb+2&&cb==i+1))ans = 0;
            cs = 1000000;cb = 0;
            lb = i;
        }
        if(i<n-1)qh = getchar();
    }
    if(ans)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}