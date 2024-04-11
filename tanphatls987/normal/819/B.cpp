#include <bits/stdc++.h>

using namespace std;

const int N=2e6+10;

typedef long long ll;


int n;
int p[N];
ll ans[N],f[N];

void contribute(int val,int st,int en,int type){
    int len=en-st+1;
    if (type==0){
        if (en-val>=st)
            f[en-val]+=2,f[st-1]-=2;
        f[en]--,f[st-1]++;
    }else {
        if (en-val>=st) f[st-1]-=-val+(en-val+1-st);
        else f[st-1]+=len;
    }
}
void solve(){
    ///do n time for every positions
    ///addition is multiplicative so we can merge n function
    /*for(int i=1;i<=2*n;i++){
        cout<<"Position i:\n";
        fill(f+1,f+2*n+1,0);
        fill(ans+1,ans+2*n+1,0);
        for(int j=0;j<=1;j++){
            int L=max(i-n+1,1);
            if (j==0){
                ans[L]+=p[i];
                ans[i+1]-=p[i];
            }
            contribute(p[i],L,i,j);
            cout<<"Loop "<<j+1<<" :\n";;
            for(int i=1;i<=2*n;i++) cout<<f[i]<<" \n"[i==2*n];
            for(int i=2*n;i>=1;i--) f[i]+=f[i+1];
            for(int i=1;i<=2*n;i++) cout<<f[i]<<" \n"[i==2*n];
        }
        cout<<"Answer:\n";
        for(int i=1;i<=2*n;i++) cout<<ans[i]<<" \n"[i==2*n];
        for(int i=1;i<=2*n;i++) ans[i]+=ans[i-1];
        for(int i=1;i<=2*n;i++) cout<<ans[i]<<" \n"[i==2*n];
        for(int i=1;i<=2*n;i++) ans[i]+=f[i];
        for(int i=1;i<=2*n;i++) cout<<ans[i]<<" \n"[i==2*n];
    }*/
    memset(f,0,sizeof(f));
    memset(ans,0,sizeof(ans));
    for(int j=0;j<=1;j++){
        for(int i=1;i<=2*n;i++){
            int L=max(i-n+1,1);
            if (j==0){
                ans[L]+=p[i];
                ans[i+1]-=p[i];
            }
            contribute(p[i],L,i,j);
        }
        for(int i=2*n;i>=1;i--) f[i]+=f[i+1];
    }
    for(int i=1;i<=2*n;i++) ans[i]+=ans[i-1];
    for(int i=1;i<=2*n;i++) ans[i]+=f[i];

    int pans=min_element(ans+2,ans+n+2)-ans;
    cout<<ans[pans]<<" "<<n+1-pans;
//    ll ans=*min_element(ans+2,ans+n+2);
//    for(int i=1;i<=n;i++) cout<<ans[i]<<" \n"[i==2*n];
}
int main(){
//    freopen("input.txt","r",stdin);
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",p+i);
    for(int i=1;i<=n;i++) p[n+i]=p[i];
    solve();
}