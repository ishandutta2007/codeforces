#include <bits/stdc++.h>
using namespace std;

const int MN = 200;
int arr[MN], i, n, ans;

int main(){
        for(scanf("%d",&n),i=1;i<=n;i++)
                scanf("%d",&arr[i]);
        for(i=2;i<n;i++){
                if(arr[i]==0&&arr[i-1]==arr[i+1]&&arr[i+1]==1){
                        arr[i+1]=0; ans++;
                }
        }
        printf("%d\n",ans);
        return 0;
}