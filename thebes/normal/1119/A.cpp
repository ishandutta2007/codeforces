#include <bits/stdc++.h>
using namespace std;

const int MN = 3e5+5;
int arr[MN], i, n, a, b, ans;

int main(){
    for(scanf("%d",&n),i=1;i<=n;i++)
        scanf("%d",&arr[i]);
    for(i=1;i<=n;i++){
        if(arr[i]!=arr[1]){
            ans = max(i-1, ans);
        }
    }
    for(i=n;i>=1;i--){
        if(arr[i]!=arr[n]){
            ans = max(n-i, ans);
        }
    }
    printf("%d\n",ans);
    return 0;
}