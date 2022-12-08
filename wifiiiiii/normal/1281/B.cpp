#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
random_device rng;
mt19937 mrand(rng());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;
#define endl '\n'

int main()
{
    
    int T;
    cin>>T;
    while(T--)
    {
        string s,t;
        cin>>s>>t;
        if(s<t) {cout<<s<<endl;continue;}
        vector<int> dp(s.size()+1);
        dp[s.size()] = 1e9;
        for(int i=s.size()-1;i>=0;--i) dp[i]=min(dp[i+1],int(s[i]));
        for(int i=0;i<s.size();++i) {
            if(dp[i] != s[i]){
                for(int j=s.size();j>=i;--j) {
                    if(s[j] == dp[i]) {swap(s[i],s[j]);break;}
                }
                break;
            }
        }
        if(s>=t) cout << "---" << endl;
        else cout << s << endl;
    }
}