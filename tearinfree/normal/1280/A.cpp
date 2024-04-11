#include <bits/stdc++.h>
using namespace std;
using lli = long long;

const lli MOD = 1e9+7;

struct td{
    int l,r,t;
    td() {}
    td(int l,int r,int t):l(l),r(r),t(t) {}
};

char str[1000100];
int main() {
    int test;
    scanf("%d",&test);
    while(test--) {
        int x;
        scanf("%d%s", &x,str);

        int n=strlen(str), idx = 0, li = n;
        lli sum = n;

        for(int t=0;t<x;t++) {
            sum = (sum + (str[idx]-'1')*((sum - (idx+1) + MOD)%MOD)%MOD)%MOD;
            
            int last = li;
            for(int k=0; k<str[idx] - '0'; k++) {
                for(int j = idx+1; j < last && li < x && li < sum; j++, li++) {
                    str[li] = str[j];
                }
            }
            idx++;
        }

        printf("%lld\n",sum);
    }
    return 0;
}