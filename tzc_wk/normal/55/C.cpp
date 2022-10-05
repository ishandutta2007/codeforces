#include <bits/stdc++.h>
using namespace std;
int n,m,k;
int main(){
    cin>>n>>m>>k;
    int flag=0;
    for(int i=1;i<=k;i ++){
        int x,y;
        cin>>x>>y;
        if(x<=5||y<=5||x>=n-4||y>=m-4) flag=1;
    }
    if(flag) puts("YES");
    else puts("NO");
    return 0;
}