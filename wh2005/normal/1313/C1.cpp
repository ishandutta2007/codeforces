#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int ,int >
const int N = 500009;
int n,a[N],nxt[N],pre[N],top,out[N];
pii s[N];
signed main(){
    memset(pre,0,sizeof(pre));
    memset(nxt,0,sizeof(nxt));
    scanf("%lld",&n);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    top=0;int sum=0;
    for(int i=n;i>=1;i--){
        pii p;p.first=i,p.second=1;
        while(top&&a[s[top].first]>a[i]) 
            p.second+=s[top].second,sum-=a[s[top].first]*s[top].second,top--;
        s[++top]=p;sum+=a[i]*p.second;
        nxt[i]=sum;
    }
    top=0,sum=0;
    for(int i=1;i<=n;i++){
        pii p;p.first=i,p.second=1;
        while(top&&a[s[top].first]>a[i]) 
            p.second+=s[top].second,sum-=a[s[top].first]*s[top].second,top--;
        s[++top]=p;sum+=a[i]*p.second; 
        pre[i]=sum; 
    }
    int ans=0,id=-1;
    for(int i=1;i<=n;i++)
        if(a[i]>=a[i+1]&&a[i]>=a[i-1]){
            if(ans<a[i]+pre[i-1]+nxt[i+1]) ans=a[i]+pre[i-1]+nxt[i+1],id=i;
        }
    out[id]=a[id];
    for(int i=id-1;i>=1;i--) out[i]=min(out[i+1],a[i]);
    for(int i=id+1;i<=n;i++) out[i]=min(out[i-1],a[i]);
    for(int i=1;i<=n;i++) printf("%lld ",out[i]);
    return 0;
}