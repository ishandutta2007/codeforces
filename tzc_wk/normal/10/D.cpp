#include<cstdio>
int a[502],b[502],f[502],g[502];    //
void Print(int p) {
    if(!p)
        return ;
    Print(g[p]);
    printf("%d ",b[p]);
}
int main() {
    int n,m,p=0;
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
        scanf("%d",a+i);
    scanf("%d",&m);
    for(int i=1;i<=m;++i)
        scanf("%d",b+i);
    for(int i=1,t=0;i<=n;++i,t=0)
        for(int j=1;j<=m;++j) {
            if(a[i]==b[j]) {
                f[j]=f[t]+1;
                g[j]=t;
            }
            if(a[i]>b[j]&&f[t]<f[j])
                t=j;
        }
    for(int i=1;i<=m;++i)
        if(f[i]>f[p])
            p=i;
    printf("%d\n",f[p]);
    Print(p);
    return 0;
}