#include <bits/stdc++.h>
using namespace std;

int n,k,arr[200000];
int main() {
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++) scanf("%1d",arr+i);

    int carry = 0;
    for(int i=n-1;i>=k;i--) {
        int idx = i % k, nxt = (arr[i]+carry) / 10, rem = (arr[i] + carry) % 10;
        if(rem > arr[i%k]) {
            carry = 1;
        } else carry = nxt;
    }

    for(int i=k-1;i>=0;i--) {
        arr[i] += carry;
        if(arr[i] >= 10) {
            arr[i] %= 10;
            carry = 1;
            if(i == 0) {
                printf("%d\n",n+1);
                for(int j=0;j<=n;j++) {
                    if(j%k==0) printf("1");
                    else printf("0");
                }
                return 0;
            }
        } else {
            carry = 0;
        }
    }
    printf("%d\n",n);
    for(int i=0;i<n;i++) printf("%d",arr[i%k]);
    
    return 0;
}