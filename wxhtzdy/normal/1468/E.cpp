#include <bits/stdc++.h>
using namespace std;
int main(){
    int tt;scanf("%i",&tt);
    while(tt--){
        int a[4];
        for(int i=0;i<4;i++)scanf("%i",&a[i]);
        sort(a,a+4);
        printf("%i\n",a[0]*a[2]);
    }
    return 0;
}