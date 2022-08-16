#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pb push_back
#define REP(i,n) for(int i = 0; i < n; i ++)
#define FOR(i,a,b) for(int i = a; i < b; i ++)
#define remax(a,b) a = max(a,b)
#define pii pair<int,int>
#define F first
#define S second

const int MX = 200005;
const int BLOCK = 500;

int n;
int a[MX];
int freq[MX];
vi gg[MX];
int last[10*MX];
int nxt[MX],prv[MX];

signed main(){
    cin >> n;
    FOR(i,1,n+1){
        cin >> a[i];
        freq[a[i]]++;
        gg[a[i]].pb(i);
    }
    int mf = 1;
    FOR(i,2,n+1){
        if(freq[i] > freq[mf]) mf = i;
    }
    FOR(i,1,n+1){
        if(i != mf and freq[i] == freq[mf]){
            cout << n << "\n";
            return 0;
        }
    }
    nxt[n+1] = n+1;
    for(int i = n; i >= 1; i --){
        if(a[i] == mf) nxt[i] = i;
        else nxt[i] = nxt[i+1];
    }
    prv[0] = 0;
    FOR(i,1,n+1){
        if(a[i] == mf) prv[i] = i;
        else prv[i] = prv[i-1];
    }
    int ans = 0;
    FOR(i,1,n+1){
        if(i == mf) continue;
        if(freq[i] > BLOCK){
            REP(j,2*n+1) last[j] = n+1;
            int cur = n;
            last[n] = 0;
            FOR(j,1,n+1){
                if(a[j] == mf) cur++;
                if(a[j] == i) cur--;
                if(last[cur] == n+1) last[cur] = j;
                else remax(ans,j-last[cur]);
            }
        }
        else{
            vector<pii> v;
            int lft = 1,rgt,cur,cnt = 0;
            REP(j,(int)gg[i].size()){
                if(j == (int)gg[i].size()-1) rgt = n;
                else rgt = gg[i][j+1]-1;

                cur = gg[i][j]-1;
                cnt = 0;
                stack<int> st;
                while(prv[cur] >= lft and cnt <= freq[i]){
                    st.push(prv[cur]);
                    cur = prv[cur]-1;
                    cnt++;
                }
                while(!st.empty()){
                    v.pb({st.top(),1});
                    st.pop();
                }
                v.pb({gg[i][j],-1});
                cur = gg[i][j]+1;
                lft = cur;
                cnt = 0;
                while(nxt[cur] <= rgt and cnt <= freq[i]){
                    v.pb({nxt[cur],1});
                    cur = nxt[cur]+1;
                    lft = cur;
                    cnt++;
                }
            }
            cur = (int)v.size();
            REP(j,2*cur+1) last[j] = n+1;
            last[cur] = 0;
            v.pb({n+1,0});
            // cout << i << "----\n";
            REP(j,v.size()-1){
                // cout << x.F << " " << x.S << "\n";
                cur += v[j].S;
                if(last[cur] == n+1) last[cur] = v[j].F;
                else remax(ans,v[j+1].F-1-last[cur]);
            }
        }
    }
    cout << ans << "\n";
}