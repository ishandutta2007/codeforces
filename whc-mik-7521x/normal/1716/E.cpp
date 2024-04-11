#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,a[N],q;
struct node{
    long long l,r,mx,sum;
    node operator+(const node b)const{
        return {max(l,sum+b.l),max(r+b.sum,b.r),max(mx,max(b.mx,r+b.l)),sum+b.sum};
    }
};
vector<node>solve(int l,int r,int len){
    if(len==0)return {node{max(0,a[l]),max(0,a[l]),max(0,a[l]),a[l]}};
    int mid=(l+r)>>1;
    auto L=solve(l,mid,len-1),R=solve(mid+1,r,len-1);
    vector<node>res(r-l+1);
    for(int i=0;i<r-l+1;i++){
        res[i]=(i&(1<<(len-1)))?(R[i^(1<<(len-1))]+L[i^(1<<(len-1))]):(L[i]+R[i]);
    }
    return res;
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<1<<n;i++)scanf("%d",&a[i]);
    auto it=solve(0,(1<<n)-1,n);
    int q;
    scanf("%d",&q);
    int now=0;
    while(q--){
        int x;
        scanf("%d",&x);
        now^=1<<x;
        printf("%lld\n",it[now].mx);
    }
    return 0;
}