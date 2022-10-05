#include <bits/stdc++.h>
using namespace std;
const int inf=1e9;
int main()
{
    string s, t;
    cin>>s>>t;
    if (s.size()!=t.size()) {
        cout<<"-1"<<endl;
        return 0;
    }
    int k;
    cin>>k;
    vector<vector<int> >g(26,vector<int>(26,inf));
    for (int i=0;i<26;i++) {
        g[i][i] = 0;
    }
    while(k--){
        char a,b;
        int C;
        cin>>a>>b>>C;
        g[a-'a'][b-'a']=min(g[a-'a'][b-'a'],C);
    }
    for (k=0;k<26;k++) {
        for (int i=0;i<26;i++) {
            for (int j=0;j<26;++j) {
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }
    int ans=0;
    string p="";
    for (int i=0;i<s.size();++i) {
        if (s[i]==t[i]) {
            p+=s[i];
            continue;
        }
        char r=' ';
        int R=inf;
        for (int c=0;c<26;c++) {
            if (g[s[i]-'a'][c]+g[t[i]-'a'][c]<R) {
                R=g[s[i]-'a'][c]+g[t[i]-'a'][c];
                r=(char)(c+'a');
            }
        }
        if(R==inf) {
            cout<<"-1"<<endl;
            return 0;
        }
        ans+=R;
        p+=r;
    }
    cout<<ans<<endl<<p<<endl;
    return 0;
}