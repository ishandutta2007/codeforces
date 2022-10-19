#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

#define int long long

int n , k , num2 , num5 , po = 1;

main(void) {
    cin>>n>>k;
    int nn = n;
    while(nn % 2 == 0) {
        num2 ++;
        nn /= 2;
    }
    while(nn % 5 == 0) {
        num5 ++;
        nn/= 5;
    }
    if(min(num2 , num5) >= k) {
        cout<<n<<endl; return 0;
    }
    else {
        k -= min(num2 , num5);
        int p = min(num2 , num5);
        num2 -=p;
        num5 -=p;
        for(int i = 1;i <= k;i ++) {
            po *= 10;
            if(num2) {
                po /= 2; num2 --;
            }
            if(num5) {
                po /= 5; num5 --;
            }
        }
        cout<<po*n<<endl;
    }
}