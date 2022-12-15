#include <bits/stdc++.h>
using namespace std;

const int MN = 101;
int arr[MN], N, X, i, x;

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    for(scanf("%d%d",&N,&X),i=1;i<=N;i++){
        scanf("%d",&x);
        arr[i] = (N-i+1)*x;
    }
    sort(arr+1,arr+N+1);
    for(x=0,i=1;i<=N;i++){
        x += arr[i];
        if(x>X) break;
    }
    printf("%d\n",i-1);
    return 0;
}