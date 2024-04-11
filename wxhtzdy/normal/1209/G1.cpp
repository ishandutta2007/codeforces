#include <bits/stdc++.h>
using namespace std;
const int N=200050;
int n,q,a[N],fir[N],lst[N],cnt[N];
int main(){
    scanf("%i%i",&n,&q);
    for(int i=1;i<=n;i++){
        scanf("%i",&a[i]);
        if(fir[a[i]]==0)fir[a[i]]=i;
        lst[a[i]]=i,cnt[a[i]]++;
    }
    int ans=0,mx=0,nxt=0,bal=0,sz=0;
    for(int i=1;i<=n;i++){
        mx=max(mx,cnt[a[i]]);
        nxt=max(nxt,lst[a[i]]);
        sz++;
        if(nxt==i){
            ans+=sz-mx;
            mx=sz=nxt=0;
        }
    }
    printf("%i",ans);
    return 0;
}