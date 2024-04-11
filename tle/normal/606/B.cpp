#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<string.h>
#include<math.h>
#include<queue>
#include<map>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;
int n,m,s,t,p,d=1,b[1001][1001],c[1000001];
char a[1000001];
inline void init(){
    scanf("%d%d%d%d%s",&n,&m,&s,&t,&a);p=strlen(a);
    for(int i=0;i<p;i++){
        if(b[s][t]==0) b[s][t]=i+1;
        if(a[i]=='U'&&s>1) s--;
        if(a[i]=='D'&&s<n) s++;
        if(a[i]=='L'&&t>1) t--;
        if(a[i]=='R'&&t<m) t++;
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(b[i][j]==0) b[i][j]=p+1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            c[b[i][j]]++;
    for(int i=1;i<=p+1;i++)
        printf("%d ",c[i]);
}
int main(){
    init();
    return 0;
}