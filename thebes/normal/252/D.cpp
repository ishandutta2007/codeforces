#include <bits/stdc++.h>
using namespace std;

const int MN = 105;
int q[MN], s[MN], a[MN], rev[MN], tmp[MN], l=-1, r=-1, n, k, i, j;

int main(){
    for(scanf("%d%d",&n,&k),i=1;i<=n;i++){
        scanf("%d",&q[i]);
        a[i]=i; rev[q[i]]=i;
    }
    for(i=1;i<=n;i++)
        scanf("%d",&s[i]);
    for(i=0;i<=k;i++){
        bool mat=1;
        for(j=1;j<=n;j++)
            if(a[j]!=s[j]) mat=0;
        if(mat&&r==-1) r=i;
        for(j=1;j<=n;j++){
            tmp[j]=a[q[j]];
        }
        for(j=1;j<=n;j++)
            a[j]=tmp[j];
    }
    for(i=1;i<=n;i++) a[i]=i;
    for(i=0;i<=k;i++){
        bool mat=1;
        for(j=1;j<=n;j++)
            if(a[j]!=s[j]) mat=0;
        if(mat&&l==-1) l=i;
        for(j=1;j<=n;j++)
            tmp[j]=a[rev[j]];
        for(j=1;j<=n;j++)
            a[j]=tmp[j];
    }
    if(l==-1&&r==-1) printf("NO\n");
    else if(l==r&&r==0) printf("NO\n");
    else if(l==1&&r==1){
        if(k==1) printf("YES\n");
        else printf("NO\n");
    }
    else{
        if(l!=-1&&r!=-1){
            if(l%2==k%2) printf("YES\n");
            else if(r%2==k%2) printf("YES\n");
            else printf("NO\n");
        }
        else if(l!=-1){
            if(l%2==k%2) printf("YES\n");
            else printf("NO\n");
        }
        else if(r!=-1){
            if(r%2==k%2) printf("YES\n");
            else printf("NO\n");
        }
        else printf("NO\n");
    }
    return 0;
}