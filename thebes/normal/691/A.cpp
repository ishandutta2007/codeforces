#include <bits/stdc++.h>
using namespace std;

int N, i, x, cnt;

int main(){
    for(scanf("%d",&N),i=1;i<=N;i++){
        scanf("%d",&x);
        cnt += x;
    }
    if(N==1&&cnt==1) printf("YES\n");
    else if(N!=1&&cnt==N-1) printf("YES\n");
    else printf("NO\n");
    return 0;
}