//
//  main.cpp
//  NEW
//
//  Created by  on 2016/10/3.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
using namespace std;
double abs(double a){
    if (a>0) {
        return a;
    }
    return -1*a;
}
int main() {
    double a,b,c,sum,aver,ans;
    cin>>a>>b>>c;
    sum = a+b+c;
    ans = 100000;
    for (aver = 0; aver<max(max(a,b),c); aver++) {
        int current = abs(a-aver)+abs(b-aver)+abs(c-aver);
        if (current<ans) {
            ans = current;
        }
    }
    
    cout<<ans<<endl;
    return 0;
}