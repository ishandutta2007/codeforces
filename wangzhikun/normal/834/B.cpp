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
int n,m,ans = 0,b[1000010],start[26] = {0},en[26] = {0},qzh[1000010] = {0},cur=0;
char c[1000010];
int main() {
    cin>>n>>m;
    cin>>c;
    for(int i=0;i<n;i++){
        int cur = c[i]-'A';
        if(start[cur] == 0) start[cur] = i+1;
        en[cur] = i+2;
    }
    for(int i=0;i<26;i++){
        if(start[i]!=0){
            qzh[start[i]]+=1;
            qzh[en[i]] -= 1;
        }
    }
    for(int i=0;i<n+1;i++){
        cur+=qzh[i];
        ans = max(cur,ans);
    }
    if(m>=ans) cout<<"NO";
    else cout<<"YES";
    return 0;
}