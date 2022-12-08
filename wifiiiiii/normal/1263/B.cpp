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

string ans[20];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        vector<string> vs;
        vector<pair<string,int>> vs2;
        map<string,int> mp;
        int n;
        cin>>n;
        int cnt=0;
        for(int i=1;i<=n;++i)
        {
            string s;
            cin>>s;
            vs.push_back(s);
            if(mp[s]) {
                cnt++;
                vs2.push_back({s,i});
            }
            mp[s] = 1;
            ans[i] = s;
        }
        for(auto p:vs2) {
            string s=p.first;
            int id=p.second;
            int ok = 0;
            for(int i=0;i<4;++i) {
                if(ok) break;
                char tmp = s[i];
                for(char j='0';j<='9';++j) {
                    s[i] = j;
                    if(!mp[s]) {
                        ok = 1;
                        break;
                    }
                    s[i] = tmp;
                }
            }
            mp[s] = 1;
            ans[id] = s;
        }
        cout<<cnt<<endl;
        ii cout<<ans[i]<<endl;
    }
}