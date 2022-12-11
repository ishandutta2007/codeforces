#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
int n,t,a[N];
void solve(int l,int r){
    if(l==r)return printf("! %d\n",l),fflush(stdout),void();
    int mid=(l+r)>>1;
    printf("? %d %d\n",l,mid);
    fflush(stdout);
    int cnt=0,ct=0;
    for(int i=l,x;i<=mid;i++)scanf("%d",&x),cnt+=x>=l&&x<=mid,ct+=x>mid&&x<=r;
    if(cnt&1)solve(l,mid);
    else solve(mid+1,r);
}
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        solve(1,n);
    }
    return  0;
}