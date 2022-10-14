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
int main() {
    int n;
    cin>>n;
    int a[2010],b[2010] = {0},qzh[2010] = {0},ans = 0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        a[i]=2-a[i];
        qzh[i] = qzh[i-1]+a[i];
    }
    for(int l=0;l<=n;l++){
        for(int r=l;r<=n;r++){
            b[l] = max(b[l],qzh[r]-qzh[l]+(n-r-(qzh[n]-qzh[r])));
        }
    }
    for(int lm = 0;lm<=n;lm++){
        for(int l=lm;l<=n;l++){
            ans = max(ans,qzh[lm]+(l-lm-(qzh[l]-qzh[lm]))+b[l]);
        }
    }
    cout<<ans<<endl;
    return 0;
}