#include <bits/stdc++.h>

using namespace std;

const int N=2e5+10;

int n,m;
int a[N],need[N];
int h[N];

void modified(int& lar,int pos,int val){
        if (h[pos]>=need[pos]) lar--;
        h[pos]+=val;
        if (h[pos]>=need[pos]) lar++;
}
int solve(){
        int sum=0;
        for(int i=1;i<=m;i++) sum+=need[i];
        int ans=n+1;
        int lar=count(need+1,need+m+1,0);
        for(int st=1,en=1;en<=n;en++){
                modified(lar,a[en],1);
                while (1){
                        modified(lar,a[st],-1);
                        if (lar==m) st++;
                        else{
                                modified(lar,a[st],1);
                                break;
                        }
                }
                if (lar==m)
                        ans=min(ans,en-st+1-sum);
        }
        if (ans==n+1) return -1;
        return ans;
}
int main(){
        cin>>n>>m;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=m;i++) cin>>need[i];

        cout<<solve();
}