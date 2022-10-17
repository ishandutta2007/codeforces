#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define fe(i,n) for(int i=1;i<=n;++i)
#define ff(i,n) for(int i=0;i<n;++i)
#define fs(i,s) for(int i=0;i<s.size();++i)
#define sz(x) ((int) x.size())
#define all(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;
#define endl '\n'


int a[200555];
int main()
{
    int k;
    cin>>k;
    string s1,s2;
    cin>>s1>>s2;
    reverse(all(s1)),reverse(all(s2));
    fs(i,s1) a[i]=s1[i]+s2[i]-'a'-'a';
    int i=0;
    for(int i=0;i<=200500;++i)
    {
        a[i+1] += a[i]/26;
        a[i] %= 26;
    }
    for(int j=200500;j>=0;--j) if(a[j]) {i=j;break;}
    int p=i;
    for(;i>=0;--i)
    {
        if(a[i]&1) a[i-1]+=26;
        a[i]/=2;
    }
    string ans;
    for(int j=0;j<=p;++j) ans+=char('a'+a[j]);
    while(ans.size() > k) ans.pop_back();
    while(ans.size() < k) ans+='a';
    reverse(all(ans));
    cout<<ans<<endl;
}