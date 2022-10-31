#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int n,arr[300000];

int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",arr+i);
    lli res = 0;
    for(int i=0;i<n;i++) res += arr[i]/2, arr[i]%=2;
    
    stack<int> stk;
    for(int i=n-1;i>=0;i--) {
        if(arr[i]) {
            int val = i%2;
            if(!stk.empty() && stk.top() != val) {
                res++;
                stk.pop();
            } else stk.push(val);
        }
    }
    printf("%lld\n", res);

    return 0;
}