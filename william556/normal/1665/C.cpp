#include<bits/stdc++.h>
using namespace std;
inline int in(){
    int x;
    scanf("%d",&x);
    return x;
}
const int N=2e5+5;
int n;
int fa[N],d[N];
bool check(int mid){
    int sum=0,tot=0;
    for(int i=0;i<=n&&d[i];i++){
        tot++;
        sum+=max(0,d[i]-(mid-i));
    }
    if(tot+sum>mid)return 0;
    return 1;
}
void solve(){
    n=in();
    for(int i=1;i<=n;i++)d[i]=0;
    for(int i=2;i<=n;i++)d[in()]++;
    d[0]=1;
    sort(d,d+n+1,greater<int>());
    int l=0,r=n,mid,res;
    while(l<=r){
        mid=l+r>>1;
        if(check(mid))r=mid-1,res=mid;
        else l=mid+1;
    }
    printf("%d\n",res);
}
int main(){
    int t=in();
    while(t--)solve();
    return 0;
}