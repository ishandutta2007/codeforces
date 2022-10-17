#include<bits/stdc++.h>

typedef long long ll;
using namespace std;
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define fs(i,s) for(int i=0;i<s.size();++i)
#define sz(x) ((int) x.size())
#define all(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;
#define endl '\n'

int a[11];
int main()
{
    int n;cin>>n;
    string s;cin>>s;
    int l=0,r=9;
    fs(i,s)
    {
        if(s[i]=='L')
            {for(int i=0;i<=9;++i) if(!a[i]) {a[i]=1;break;}}
        else if(s[i]=='R')
            {for(int i=9;i>=0;--i) if(!a[i]) {a[i]=1;break;}}
        else
            {a[s[i]-'0']=0;}
    }
    for(int i=0;i<=9;++i) cout<<a[i];
}