#include <bits/stdc++.h>

using namespace std;

const int N=1e5+10;
const int alp=26;


int n,h[N];
int s[N],f[2][N];
int solve(){
        int top=0;
        for(int i=1;i<=n;i++){
                int idx=upper_bound(s+1,s+top+1,h[i])-s;
                s[idx]=h[i];
                if (idx>top) top++;
                f[0][i]=idx;
        }
        top=0;
        for(int i=n;i>=1;i--){
                int idx=upper_bound(s+1,s+top+1,h[i])-s;
                s[idx]=h[i];
                if (idx>top) top++;
                f[1][i]=idx;
        }
        int ans=0;
        for(int i=1;i<=n;i++) ans=max(ans,f[0][i]+f[1][i]-1);
        return ans;
}
int main(){
        int m;
        cin>>m>>n;
        while (m--){
                int x,y;
                cin>>x>>y;
                h[x]++,h[y+1]--;
        }
        for(int i=1;i<=n;i++) h[i]+=h[i-1];
        cout<<solve();
}