#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,a[N];
bool check(int len){
    vector<int>vec;
    for(int i=len,o=1;i>=o;i--,o++){
        if(i==o){vec.push_back(a[i]);continue;}
        vec.push_back(a[i]),vec.push_back(a[o]);
    }
    for(int i=0;i+1<(int)vec.size();i++)if(vec[i]+vec[i+1]>m)return 0;
    return 1;
}
int main(){
    scanf("%d%d",&n,&m);
    long long res=0;
    for(int i=1;i<=n;i++)scanf("%d",&a[i]),res+=a[i];
    stable_sort(a+1,a+n+1);
    int l=1,r=n,mid,ans=1;
    while(l<=r){
        mid=(l+r)>>1;
        if(check(mid))ans=mid,l=mid+1;
        else r=mid-1;
    }
    printf("%lld",res+n-(ans-1));
    return 0;
}