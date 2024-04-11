#include <cstdio>
int n,ans,k;
bool calc(int x) {
    int s=x;
    if (s>=n) return(true);
    for (int i=k;x/i!=0;i*=k) {
       s+=x/i;
       if (s>=n) return(true);
    } 
    return(false);
}
void go(int l,int r) {
    if (l>=r) {
        if (calc(l)) ans=l;  return;
    }
    int mid=(l+r)>>1;
    if (calc(mid)) {
        ans=mid;
        go(l,mid-1);
    }
    else go(mid+1,r);
}
int main() {
    scanf("%d%d",&n,&k);
    go(1,n);
    printf("%d",ans);
}