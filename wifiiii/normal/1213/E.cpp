#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i )
#define sz(x) ((int) x.size())
#define all(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;
#define endl '\n'

string case1[] = {"ab","bc","ca"};
string case2[] = {"ac","cb","ba"};
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
    int n;
    cin>>n;
    string s,t;
    cin>>s>>t;
    cout<<"YES"<<endl;
    
    int ok;
    
    ok = 1;
    for(int i=0;i<3;++i) if(s==case1[i] || t==case1[i]) ok = 0;
    if(ok)
    {
        string ans;
        for(int i=1;i<=n;++i) ans+="abc";
        cout<<ans<<endl;
        return 0;
    }

    ok = 1;
    for(int i=0;i<3;++i) if(s==case2[i] || t==case2[i]) ok = 0;
    if(ok)
    {
        string ans;
        for(int i=1;i<=n;++i) ans+="acb";
        cout<<ans<<endl;
        return 0;
    }
    
    string qaq = "abc";
    do
    {
        string qaq1 = qaq.substr(0,2), qaq2 = qaq.substr(1,2);
        int ok = 1;
        if(qaq1==s || qaq1==t || qaq2==s || qaq2==t) ok = 0;
        if(ok)
        {
            string ans1(n,qaq[0]),ans2(n,qaq[1]),ans3(n,qaq[2]);
            cout<<ans1+ans2+ans3<<endl;
            return 0;
        }
    } while(next_permutation(qaq.begin(),qaq.end()));
    
    while(1) cout<<"qaqaqaq"<<endl;
}