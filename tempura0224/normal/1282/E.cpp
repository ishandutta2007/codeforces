#include<bits/stdc++.h>
using namespace std;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)

void solve(){
    int n;
    cin>>n;
    vector<vector<int>> a(n-2,vector<int>(3));
    map<pair<int,int>,vector<int>> mp;
    rep(i,n-2){
        rep(j,3)cin>>a[i][j];
        rep(j,3){
            mp[minmax(a[i][j],a[i][(j+1)%3])].push_back(i);
        }
    }
    vector<int> cnt(n-2);
    vector<vector<int>> nxt(n+1);
    for(auto& s:mp){
        if(s.second.size()==1){
            nxt[s.first.first].push_back(s.first.second);
            nxt[s.first.second].push_back(s.first.first);
            cnt[s.second[0]]++;
        }
    }
    vector<int> p(n);
    vector<int> used(n+1);
    p[0]=1;
    used[1]=1;
    rep(i,n-1){
        for(auto e:nxt[p[i]]){
            if(!used[e]){
                used[e]=1;
                p[i+1]=e;
                break;
            }
        }
    }
    queue<int> que;
    rep(i,n-2)if(cnt[i]>=2)que.push(i);
    vector<int> q;
    while(que.size()){
        int x=que.front();que.pop();
        q.push_back(x+1);
        rep(j,3){
            for(auto e:mp[minmax(a[x][j],a[x][(j+1)%3])]){
                if(++cnt[e]==2)que.push(e);
            }
        }
    }
    rep(i,n)cout<<p[i]<<" \n"[i+1==n];
    rep(i,n-2)cout<<q[i]<<" \n"[i+1==n-2];
}
int main(){
    int t;
    cin>>t;
    rep(i,t)solve();    
    return 0;
}