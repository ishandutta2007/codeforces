#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 200009;
const int M = 1009;
int n,m,a[N],bl[N],unit;ll ans;
vector<int >v[M];
int lower(int i,int l,int r,int x){
    int ans=r+1;
    while(l<=r){
        int mid=(l+r)>>1;
        if(v[i][mid]>x) ans=mid,r=mid-1;
        else l=mid+1;
    }
    return ans;
}
void modify(int x){
    v[x].clear();
    for(int i=(x-1)*unit+1;i<=x*unit;i++)
        v[x].push_back(a[i]);
    sort(v[x].begin(),v[x].end());
    return ;    
}
void query(int l,int r){
    if(l==r) return ;
    for(int i=l+1;i<=min(r-1,bl[l]*unit);i++){
        ans+=(a[i]>a[l]);ans-=(a[i]<a[l]);
        ans-=(a[i]>a[r]);ans+=(a[i]<a[r]);
    }
    if(bl[l]!=bl[r])
        for(int i=(bl[r]-1)*unit+1;i<r;i++){
            ans+=(a[i]>a[l]);ans-=(a[i]<a[l]);
            ans-=(a[i]>a[r]);ans+=(a[i]<a[r]);
        }
    if(a[l]>a[r]) ans-=1;
    if(a[r]>a[l]) ans+=1;
    for(int i=bl[l]+1;i<bl[r];i++){
        int x=lower(i,0,v[i].size()-1,a[r]);
        int y=v[i].size()-x;
        ans=ans+x-y;
    }
    for(int i=bl[l]+1;i<bl[r];i++){
        int x=lower(i,0,v[i].size()-1,a[l]);
        int y=v[i].size()-x;
        ans=ans+y-x;
    }
    swap(a[l],a[r]);
    modify(bl[l]);if(bl[l]!=bl[r]) modify(bl[r]);
}
int main(){
    scanf("%d%d",&n,&m);ans=0,unit=sqrt(n);
    for(int i=1;i<=n;i++){
        a[i]=i,bl[i]=(i-1)/unit+1;
        v[bl[i]].push_back(i);
    }
    for(int i=1;i<=m;i++){
        int l,r;scanf("%d%d",&l,&r);
        if(l>r) swap(l,r);
        query(l,r);
        printf("%lld\n",ans);
    }
    return 0;
}