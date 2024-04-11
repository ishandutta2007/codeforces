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

int main()
{
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    if(!k) return cout<<s<<endl,0;
    if(s.size() == 1) return cout<<0<<endl,0;
    if(s[0] != '1') --k, s[0]='1';
    for(int i=1;i<s.size();++i)
    {
        if(!k) break;
        if(s[i] != '0') s[i]='0',k--;
    }
    cout << s << endl;
}