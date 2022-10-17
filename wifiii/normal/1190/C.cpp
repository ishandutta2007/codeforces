#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define F(i,n) for(int i=1;i<=n;++i)
#define FF(i,n) for(int i=0;i<n;++i)
#define ALL(i) i.begin(),i.end()

int chk1(string s,int k)
{
    int l1=1e9,r1=0,l0=1e9,r0=0;
    FF(i,s.size())
    {
        if(s[i]=='1') l1=min(l1,i),r1=i;
        if(s[i]=='0') l0=min(l0,i),r0=i;
    }
    if(r1-l1<k || r0-l0<k) return 1;
    return 0;
}
int chk2(string s,int k)
{
    if(2*k<s.size() || s[0]==s[s.size()-1]) return 0;
    for(int i=0;i<s.size()-k-1;++i) if(s[i]!=s[0]) return 0;
    for(int i=k+2;i<s.size();++i) if(s[i]!=s[s.size()-1]) return 0;
    return 1;
}
int main()
{
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    if(chk1(s,k)) cout<<"tokitsukaze"<<endl;
    else if(chk2(s,k)) cout<<"quailty"<<endl;
    else cout<<"once again"<<endl;
}