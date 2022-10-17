#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
//random_device rng;
//mt19937 mrand(rng());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define alll(x) x+1,x+1+n
#define asd cout<<"ok"<<endl;
#define endl '\n'

int nxt[100005][27];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s,t;
        cin>>s>>t;
        vector<int> vis(26);
        for(char c:s) vis[c-'a']++;
        int ok=1;
        for(char c:t) if(!vis[c-'a']) ok=0;
        if(!ok) {cout<<-1<<endl;continue;}
        vector<int> b(26,-1);
        for(int i=s.size();i>=0;--i) {
            for(int j=0;j<26;++j) nxt[i][j] = b[j];
            if(i) b[s[i-1]-'a'] = i;
            
        }
        int cur = 0, ans = 1;
        for(int i=0;i<t.size();++i) {
            if(nxt[cur][t[i]-'a'] == -1) cur = 0, ++ans;
            cur = nxt[cur][t[i]-'a'];
        }
        cout << ans << endl;
    }
}