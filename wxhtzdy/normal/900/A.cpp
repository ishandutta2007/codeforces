#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;scanf("%i",&n);
    int cnt=0;
    for(int i=1;i<=n;i++){
        int x,y;scanf("%i %i",&x,&y);
        if(x<0)cnt++;
    }
    if(cnt<=1||cnt>=n-1)printf("YES\n");
    else printf("NO\n");
    return 0;
}