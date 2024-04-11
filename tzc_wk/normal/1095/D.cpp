#include <bits/stdc++.h>
using namespace std;
int n;
int a1[200010],a2[200010],fa[200010];
bool rel(int a,int b){
    return (b==a1[a]||b==a2[a]);
}
int main(){
    cin>>n;
    if(n==3)	return puts("1 2 3"),0;
    for(int i=1;i<=n;i++)	cin>>a1[i]>>a2[i];
    for(int i=1;i<=n;i++){
        if(rel(a1[i],a2[i]))	fa[i]=a1[i];
        else					fa[i]=a2[i];
    }
    int cur=1;
    while(fa[cur]!=1){
        printf("%d ",cur);
        cur=fa[cur];
    }
    printf("%d\n",cur);
}