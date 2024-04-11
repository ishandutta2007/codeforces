#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdio>
using namespace std;
struct atom{
    int x,h;
    void scan(){
        scanf("%d%d",&x,&h);
    }
}x[210000];
int n,l[210000],R[210000][18],w[210000][18],A[210000][18],Log2[210000],lim=2e9,len,m;
struct tree{
    int l,r,num;
}t[10000000];
void add(int k1,long long k2,long long k3,int k4,int k5){
    if (k2==k3){t[k1].num=k5; return;}
    long long mid=k2+k3>>1;
    if (mid>=k4){
        if (t[k1].l==0) t[k1].l=++len; add(t[k1].l,k2,mid,k4,k5);
    } else{
        if (t[k1].r==0) t[k1].r=++len; add(t[k1].r,mid+1,k3,k4,k5);
    }
    t[k1].num=max(t[t[k1].l].num,t[t[k1].r].num);
}
int find(int k1,long long k2,long long k3,int k4,int k5){
    if (k2>k5||k3<k4||k1==0) return 0;
    if (k2>=k4&&k3<=k5) return t[k1].num;
    long long mid=k2+k3>>1;
    return max(find(t[k1].l,k2,mid,k4,k5),find(t[k1].r,mid+1,k3,k4,k5));
}
int findmax(int k1,int k2){
    int k3=Log2[k2-k1+1]; return max(A[k2][k3],A[k1+(1<<k3)-1][k3]);
}
int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++) Log2[i]=trunc(log(i)/log(2)+1e-6);
    for (int i=1;i<=n;i++) x[i].scan();
    for (int i=1;i<=n;i++) l[i]=x[i].x+x[i].h;
    memset(t,0x00,sizeof t);
    R[n][0]=n; len=1; add(1,1,lim,x[n].x,n);
    for (int i=n-1;i;i--){
        R[i][0]=max(find(1,1,lim,x[i].x,l[i]),i); add(1,1,lim,x[i].x,R[i][0]);
    }
    for (int i=1;i<=n;i++) A[i][0]=l[i];
    for (int i=1;i<=17;i++)
        for (int j=(1<<i);j<=n;j++)
            A[j][i]=max(A[j][i-1],A[j-(1<<i-1)][i-1]);
    for (int i=1;i<=17;i++)
        for (int j=1;j<=n;j++)
            if (R[j][i-1]==n){
                R[j][i]=n; w[j][i]=w[j][i-1];
            } else {
                R[j][i]=R[R[j][i-1]+1][i-1];
                w[j][i]=w[j][i-1]+x[R[j][i-1]+1].x-findmax(j,R[j][i-1])+w[R[j][i-1]+1][i-1];
            }
    scanf("%d",&m);
    for (;m;m--){
        int l,r; scanf("%d%d",&l,&r);
        int ans=0;
        for (int i=17;i>=0;i--) 
            if (R[l][i]<r){
                ans+=w[l][i]+x[R[l][i]+1].x-findmax(l,R[l][i]);
                l=R[l][i]+1;
            }
        printf("%d\n",ans);
    }
    return 0;
}