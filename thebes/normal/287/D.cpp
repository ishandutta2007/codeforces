#include <bits/stdc++.h>
using namespace std;

const int MN = 2e6+6;
int arr[MN], st, en, n, i, tmp, w;

int main(){
    for(scanf("%d",&n),i=1;i<=n;i++)
        arr[i]=i;
    st = 1, en = n;
    for(int j=2;j<=n;j++){
        for(i=st;i<=en;i+=j){
            w = arr[i];
            arr[i] = tmp;
            tmp = w;
        }
        arr[++en]=tmp; st++;
    }
    for(i=st;i<=en;i++)
        printf("%d ",arr[i]);
    return 0;
}