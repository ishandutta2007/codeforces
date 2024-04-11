#include<bits/stdc++.h>
#pragma GCC optimize(3)
using namespace std;
const int N=5e4+10;
int a[N],val[2000000],n,m,ans[N];
struct node{
    int l,r,num;
    bool operator<(const node b)const{
        return r>b.r;
    }
}dat[N];
int main(){
    for(int i=1;i<=1000000;i++)val[i]=val[i-1]^i;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=m;i++)scanf("%d%d",&dat[i].l,&dat[i].r),dat[i].num=i;
    stable_sort(dat+1,dat+m+1);
    for(int i=1;i<=n;i++){
        vector<node>vec;
        for(int o=1;o<=m;o++){
            if(dat[o].l<=i&&dat[o].r>=i)vec.push_back({dat[o].r,dat[o].num});
        }
        int res=0;
        for(int o=i;o<=n;o++){
            if(a[o]>=a[i])res=max(res,val[a[o]]^val[a[i]-1]);
            else res=max(res,val[a[o]-1]^val[a[i]]);
            while(vec.size()&&vec.back().l==o)ans[vec.back().r]=max(ans[vec.back().r],res),vec.pop_back();
        }
    }
    for(int i=1;i<=m;i++)printf("%d\n",ans[i]);
    return  0;
}