#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
int main() {
    int k; cin >> k;
    vector<vector<ll>> nums(k);
    map<ll,ll> idx;
    vector<ll> tot(k);
    ll sum = 0;
    for(int i=0;i<k;i++) {
        int n; cin >> n;
        nums[i] = vector<ll>(n);
        for(int j=0;j<n;j++) {
            cin >> nums[i][j];
            sum+=nums[i][j];
            idx[nums[i][j]] = i;
            tot[i]+=nums[i][j];
        }
    }
    if(sum%k!=0) {
        cout << "No" << endl;
        return 0;
    }
    sum/=k;
    bool b[1<<15];
    vector<vector<vector<ll>>> m(1<<k);
    for(int i=0;i<k;i++) {
        for(int j=0;j<nums[i].size();j++) {
            bool visited[k];
            memset(visited,false,sizeof(visited));
            ll curr = i;
            ll take = nums[i][j];
            bool work = true;
            vector<vector<ll>> temp;
            while(true) {
                ll need = sum-(tot[curr]-take);
                visited[curr] = true;
                if(idx.find(need)==idx.end()) {
                    work = false;
                    break;
                }
                temp.push_back(vector<ll>(3));
                temp[temp.size()-1][2] = curr;
                curr = idx[need];
                take = need;
                temp[temp.size()-1][0] = curr;
                temp[temp.size()-1][1] = take;
                if(curr==i && take==nums[i][j]) break;
                else {
                    if(visited[curr]) {
                        work = false;
                        break;
                    }
                }
            }
            if(!work) continue;
            int bit = 0;
            for(int x=0;x<k;x++) if(visited[x]) bit+=1<<x;
            b[bit] = 1; 
            m[bit] = temp;
        }
    }
    bool dp[1<<15];
    memset(dp,0,sizeof(dp));
    dp[0] = 1;
    for(int msk=0;msk<1<<k;msk++) {
        for(int s=msk;s;s=(s-1)&msk) {
            if(b[s]) dp[msk] = dp[msk]|dp[msk^s];
        }
    }
    if(dp[(1<<k)-1]) cout << "Yes" << endl;
    else {
        cout << "No" << endl;
        return 0;
    }
    int currmsk = (1<<k)-1;
    vector<pair<ll,int>> ans(k);
    while(currmsk>0) {
        for(int s=currmsk;s;s=(s-1)&currmsk) {
            if(b[s] && dp[currmsk^s]) {
                for(auto &it : m[s]) {
                    ans[it[0]] = {it[1],it[2]};
                }
                currmsk^=s;
                break;
            }
        }
    }
    for(int i=0;i<k;i++) {
        cout << ans[i].f << " " << ans[i].s+1 << endl;
    }
}