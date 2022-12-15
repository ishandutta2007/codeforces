#include <bits/stdc++.h>
using namespace std;

const int MN = 2e5+5;
int arr[MN], n, i, x, tmp, ans;

int main(){
    for(scanf("%d",&n),i=1;i<=n;i++)
        scanf("%d",&arr[i]);
    for(i=1;i<=n;i++){
        if(arr[i]>2*x){
            ans = max(ans, tmp);
            tmp = 1; x = arr[i];
        }
        else tmp++, x = arr[i];
    }
    printf("%d\n",max(ans,tmp));
    return 0;
}