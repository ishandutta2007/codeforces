//
//  main.cpp
//  Codeforces
//
//  Created by  on 2018/1/19.
//  Copyright  2018 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;

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
int main() {
    int ks = read(),n,cn,ans1,ans2,ans,cur = 0,lc;
    for(int k=0;k<ks;k++){
        ans1 = 6666;ans2 = 6666;ans = 0;
        n = read();cn = read();
        for(int i = 0;i<cn;i++){
            lc = cur;
            cur = read();
            ans = max(ans,(cur+2-lc)/2);
            ans1 = min(ans1,cur-1);
            ans2 = min(ans2,n-cur);
        }
        cout<<max(max(ans1,ans2)+1,ans)<<endl;
    }
    return 0;
}