#include <bits/stdc++.h>
using namespace std;
const int N=55;
char s[N][N];
int main(){
    int n,m;
    scanf("%i %i",&n,&m);
    for(int i=0;i<n;i++)scanf("%s",&s[i]);
    int minx=n,mx=0,miny=m,my=0;
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)if(s[i][j]=='*'){
        minx=min(minx,i);
        mx=max(mx,i);
        miny=min(miny,j);
        my=max(my,j);
    }
    for(int i=minx;i<=mx;i++){
        for(int j=miny;j<=my;j++)printf("%c",s[i][j]);
        printf("\n");
    }
    return 0;
}