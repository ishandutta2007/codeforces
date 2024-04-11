#include <bits/stdc++.h>
using namespace std;

int n,s;
long long arr[100001];

int main() {
    int test;
    scanf("%d",&test);
    while(test--) {
        scanf("%d%d",&n,&s);
        for(int i=1;i<=n;i++) scanf("%lld",arr+i),arr[i]+=arr[i-1];

        if(arr[n] <= s) {
            puts("0");
            continue;
        }

        int ans=0, idx = -1;
        for(int i=1;i<=n;i++) {
            if(arr[i-1] > s) continue;
            int val = upper_bound(arr,arr+n+1,s+arr[i]-arr[i-1]) - arr - 1;
            if(val > ans) {
                ans = val;
                idx = i;
            }
        }
        printf("%d\n",idx);
    }
    return 0;
}