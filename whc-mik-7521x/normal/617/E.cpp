#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int a[N],n,m,k,t,cnt1[N],cnt2[N];
long long ans[N],tot;
struct node{
    int l,r,num;
    bool operator<(const node b)const{
        return l/t==b.l/t?((l/t)&1?r>b.r:r<b.r):l<b.l;
    }
}q[N];
void dec1(int x){
    tot-=cnt1[k^a[x-1]];
    cnt1[a[x]]--;
    cnt2[a[x-1]]--;
}
void inc1(int x){
    cnt1[a[x]]++;
    cnt2[a[x-1]]++;
    tot+=cnt1[k^a[x-1]];
}
void dec2(int x){
    tot-=cnt2[k^a[x]];
    cnt1[a[x]]--;
    cnt2[a[x-1]]--;
}
void inc2(int x){
    cnt1[a[x]]++;
    cnt2[a[x-1]]++;
    tot+=cnt2[k^a[x]];
}
int main(){
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        a[i]^=a[i-1];
    }
    for(int i=1;i<=m;i++){
        scanf("%d%d",&q[i].l,&q[i].r);
        q[i].num=i;
    }
    t=sqrt(n);
    stable_sort(q+1,q+m+1);
    // puts("?");
    for(int i=1,l=1,r=0;i<=m;i++){
        while(l<q[i].l)dec1(l++);
        while(l>q[i].l)inc1(--l);
        while(r<q[i].r)inc2(++r);
        while(r>q[i].r)dec2(r--);
        ans[q[i].num]=tot;
    }
    for(int i=1;i<=m;i++){
        printf("%lld\n",ans[i]);
    }
    return  0;
}