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

map<string,int> mp;
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        string s;
        cin>>s;
        if(mp[s]) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        mp[s]++;
    }
}