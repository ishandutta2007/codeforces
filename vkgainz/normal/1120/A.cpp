#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define s second
#define f first
const int MX = 5e5+5;
int main() {
    int m,k,n,s;
    cin >> m >> k >> n >> s;
    int a[m];
    int need[MX];
    memset(need,0,sizeof(need));
    for(int i=0;i<m;i++) cin >> a[i];
    for(int i=0;i<s;i++) {
        int b; cin >> b;
        ++need[b];
    }
    s = 0;
    for(int i=0;i<MX;i++) if(need[i]) ++s;
    int en[m];
    memset(en,0,sizeof(en));
    int f[MX];
    memset(f,0,sizeof(f));
    int in = 0;
    int r = 0;
    for(int l=0;l<m;l++) {
        while(r<m) {
            if(in==s) break;
            ++f[a[r]];
            if(need[a[r]] && f[a[r]]==need[a[r]]) ++in;
            ++r;
        }
        if(in==s) en[l] = r-1; //[l, r]
        else en[l] = -1;
        --f[a[l]];
        if(need[a[l]] && f[a[l]]<need[a[l]]) --in;
    }
    memset(f,0,sizeof(f));
    for(int i=0;i<m;i++) {
        if(en[i]==-1) continue;
        int rem = i%k+max(i/k-(n-1),0)*k+max(en[i]-i+1-k,0);
        if(rem<=m-n*k) {
            vector<int> ans;
            for(int x=0;x<i%k;x++) {
                ans.push_back(x);
            }
            for(int x=i;en[i]-i+1-k>0 && x<=en[i];x++) {
                ++f[a[x]];
                if(f[a[x]]>need[a[x]] && ans.size()<m-n*k) {
                    --f[a[x]];
                    ans.push_back(x);
                }
            }
            cout << ans.size() << "\n";
            for(auto &it : ans) cout << it+1 << " ";
            cout << "\n";
            return 0;
        }
    }
    cout << -1 << "\n";
}