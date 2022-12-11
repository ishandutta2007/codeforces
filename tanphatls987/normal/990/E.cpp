#include <bits/stdc++.h>

using namespace std;

const int N=1e6+10;
const long long linf=1e16+10;

int k,n,m;
int a[N],b[N];
int last[N];


long long solve(){
        if (a[0]) return -1;
        int gap=1;
        for(int i=1;i<n;i++) if (a[i]){
                int cgap=1;
                while (a[i]) i++,cgap++;
                gap=max(gap,cgap);
        }
        if (gap>k) return -1;
        for(int i=1;i<=n;i++) 
                if (a[i]) last[i]=last[i-1];
                else last[i]=i;
        long long ans=linf;
        for(int len=gap;len<=k;len++){
                
                int st=0,cans=0;
                while (1){
                        cans++;
                        st+=len;
                        if (st>=n) break;
                        st=last[st];
                }
                ans=min(ans,1LL*cans*b[len]);
        }
        return ans;
}
int main(){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cin>>n>>m>>k;
        for(int i=1;i<=m;i++){
                int pos;
                cin>>pos;
                a[pos]=1;
        }
        for(int i=1;i<=k;i++) cin>>b[i];
        cout<<solve();
}