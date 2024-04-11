//
// Created by yamunaku on 2019/08/14.
//

#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < (n); i++)
#define repl(i, l, r) for(int i = (l); i < (r); i++)
#define per(i, n) for(int i = ((n)-1); i >= 0; i--)
#define perl(i, l, r) for(int i = ((r)-1); i >= (l); i--)
#define all(x) (x).begin(),(x).end()
#define MOD9 998244353
#define MOD1 1000000007
#define IINF 1000000000
#define LINF 1000000000000000000
#define SP <<" "<<
#define CYES cout<<"Yes"<<endl
#define CNO cout<<"No"<<endl
#define CFS cin.tie(0);ios::sync_with_stdio(false)
#define CST(x) cout<<fixed<<setprecision(x)

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int>> mti;
typedef vector<ll> vl;
typedef vector<vector<ll>> mtl;

int main(){
    string s;
    cin >> s;
    rep(i,10){
        rep(j,10){
            mti v(10, vi(10,IINF));
            rep(k,10){
                v[k][(k+i)%10]=v[k][(k+j)%10]=1;
                queue<pair<int,int>> q;
                q.push({(k+i)%10,1});
                q.push({(k+j)%10,1});
                while(!q.empty()){
                    auto now=q.front();
                    q.pop();
                    if(v[k][(now.first+i)%10]==IINF){
                        v[k][(now.first+i)%10]=now.second+1;
                        q.push({(now.first+i)%10, now.second+1});
                    }
                    if(v[k][(now.first+j)%10]==IINF){
                        v[k][(now.first+j)%10]=now.second+1;
                        q.push({(now.first+j)%10, now.second+1});
                    }
                }
            }
            int ans=0;
            rep(k,s.size()-1){
                if(v[s[k]-'0'][s[k+1]-'0']==IINF){
                    ans=-1;
                    break;
                }
                ans+=v[s[k]-'0'][s[k+1]-'0']-1;
            }
            cout << ans << " ";
        }
        cout << endl;
    }
    return 0;
}