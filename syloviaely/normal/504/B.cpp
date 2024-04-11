#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
int n,x[210000],y[210000],A[210000],w[210000],num[2100000];
int find(int k){
    int ans=0; for (;k;k-=k&(-k)) ans+=A[k]; return ans;
}
void add(int k){
    for (;k<=n;k+=k&(-k)) A[k]++;
}
int find(int k1,int k2,int k3,int k4){
    if (k2==k3) return k2;
    int mid=k2+k3>>1,lsize=mid-k2+1-num[k1*2];
    if (lsize>=k4) return find(k1*2,k2,mid,k4); else return find(k1*2+1,mid+1,k3,k4-lsize);
}
void add(int k1,int k2,int k3,int k4){
    if (k2==k3){num[k1]++; return;}
    int mid=k2+k3>>1; num[k1]++;
    if (mid>=k4) add(k1*2,k2,mid,k4); else add(k1*2+1,mid+1,k3,k4);
}
int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        scanf("%d",&x[i]); x[i]++;
    }
    for (int i=1;i<=n;i++){
        scanf("%d",&y[i]); y[i]++;
    }
    memset(A,0x00,sizeof A);
    for (int i=1;i<=n;i++){
        int k1=find(x[i]); w[n-i]=x[i]-k1-1; add(x[i]);
    }
    memset(A,0x00,sizeof A);
    for (int i=1;i<=n;i++){
        int k1=find(y[i]); w[n-i]+=y[i]-k1-1; add(y[i]);
    }
    for (int i=0;i<n;i++){
        w[i+1]+=w[i]/(i+1); w[i]%=i+1;
    }
    for (int i=n-1;i>=0;i--){
        int k1=find(1,1,n,w[i]+1); printf("%d ",k1-1); add(1,1,n,k1);
    }
    cout<<endl;
    return 0;
}