#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+9;
int n,a[N],b[N],c[N];
int checked(){
    if(!c[1]) return -1;
    for(int i=c[1];i<=n;i++){
        if(b[i]!=i-c[1]+1) return -1;
    }
    int ans=0;
    for(int i=b[n]+1;i<=n;i++){
        if(i-b[n]-1<c[i]) return -1; 
        ans++;
    }
    return ans;
}
bool check(int x){
    if(!x&&b[n]!=0) return 0;
    for(int i=1;i<=n;i++){
        int step=x+i;
        if(c[i]>=step) return 0;
    }
    return 1;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) scanf("%d",&b[i]);
    for(int i=1;i<=n;i++) c[a[i]]=0;
    for(int i=1;i<=n;i++) c[b[i]]=i;
    int p=checked();
    if(p!=-1){
        printf("%d\n",p);
        return 0;
    }
    int l=0,r=n+1,ans=2*n;
    while(l<=r){
        int mid=(l+r)>>1;
        if(check(mid)) r=mid-1,ans=mid+n;
        else l=mid+1;
    }
    printf("%d\n",ans);
    return 0;
}
/*
9 2 6 0 8 1 7 0 3 0 10
10
x
*/