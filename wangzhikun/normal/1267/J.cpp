#include <bits/stdc++.h>

using namespace std;

int T,n,c[2000020],cnt[2000020] = {0};
bool vis[2000020];
void solve(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>c[i];
        cnt[c[i]]++;
    }
    vector<int> cs;
    for(int i=0;i<n;i++){
        if(!vis[c[i]]){
            cs.push_back(cnt[c[i]]);
            vis[c[i]] = 1;
        }
    }
    int cmi = 1e9,ans = 1e9;
    for(auto ct:cs)cmi = min(cmi,ct);
    for(int i=1;i<=cmi+1;i++){
        int creq = 0;
        for(auto ct:cs){
            int cm = (ct+i-1)/i;
            if(cm*i-ct<=cm){
                creq+=cm;
            }else{
                goto nxt;
            }
        }
        ans = min(ans,creq);
        nxt:;
    }
    cout<<ans<<"\n";
    for(int i=0;i<n;i++){
        vis[c[i]] = cnt[c[i]] = 0;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}