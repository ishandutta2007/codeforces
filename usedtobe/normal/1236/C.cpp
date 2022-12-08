#include<bits/stdc++.h>
using namespace std;
 
int main() {
    int n;
    cin>>n;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n/2;++j) {
            printf("%d ",j*n-n+i);
        }
        for (int j=n/2+1;j<=n;++j) {
            printf("%d ",j*n-n+n+1-i);
        }
        puts("");
    }
    return 0;
}