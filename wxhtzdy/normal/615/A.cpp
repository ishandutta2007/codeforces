#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    scanf("%i %i",&n,&m);
    map<int,int> H;
    for(int i=0;i<n;i++){
        int x;
        scanf("%i",&x);
        for(int j=0;j<x;j++){
            int b;
            scanf("%i",&b);
            H[b]=1;
        }
    }
    int cnt=0;
    for(int i=1;i<=m;i++) cnt+=H[i];
    if(cnt==m)printf("YES");
    else printf("NO");
    return 0;
}