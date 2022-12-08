#include<bits/stdc++.h>
 
typedef long long ll;
using namespace std;
//random_device rng;
//mt19937 rd(rng());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;
#define endl '\n'

const int maxn = 200005;
int par[maxn];
int find(int x) { return x == par[x] ? x : par[x] = find(par[x]);}
vector<int> vs[300];
int main()
{
//    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;cin>>n;
    for(int i=1;i<=n;++i) par[i]=i;
    for(int i=1;i<=n;++i)
    {
        string s;
        cin>>s;
        sort(all(s));
        for(int j=0;j<s.size();++j){
            if(s[j]!=s[j+1]) {
                if(vs[s[j]-'a'].empty()) vs[s[j]-'a'].push_back(i);
                else {
                    for(int k : vs[s[j] - 'a']) {
                        par[find(i)]  = find(k);
                    }
                }
            }
        }
    }
    int ans=0;
    ii if(par[i]==i) ans++;
    cout<<ans<<endl;
}