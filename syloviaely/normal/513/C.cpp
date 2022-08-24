#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdio>
using namespace std;
struct atom{
    int l,r;
}x[6];
int n;
long double find(int l,int r,int mid){
    int k1=0;
    if (mid<l) k1=0; else if (mid<=r) k1=mid-l+1; else k1=r-l+1;
    return (long double)k1/(long double)(r-l+1);
}
int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d%d",&x[i].l,&x[i].r);
    long double ans=0;
    for (int i=1;i<=n;i++)
        for (int j=x[i].l;j<=x[i].r;j++){
            long double k1=0;
            for (int k=1;k<=n;k++)
                if (i!=k){
                    long double k2=1;
                    if (k<i) k2=(1-find(x[k].l,x[k].r,j)); else k2=(1-find(x[k].l,x[k].r,j-1));
                    for (int now=1;now<=n;now++)
                        if (i!=now&&k!=now){
                            if (now<i) k2=k2*(find(x[now].l,x[now].r,j)); else k2=k2*(find(x[now].l,x[now].r,j-1));
                        }
                    k1+=k2;
                }
            ans=ans+j*k1/(x[i].r-x[i].l+1);
        }
    printf("%.11lf\n",(double)ans);
}