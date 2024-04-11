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
    int n;
    cin>>n;
    string s;
    cin>>s;
    int m=n/2;
    int cnt1=0,cnt2=0;
    int sum1=0,sum2=0;
    for(int i=0;i<m;++i)
    {
        if(s[i]=='?') cnt1++;
        else sum1+=s[i]-'0';
    }
    for(int i=m;i<n;++i)
    {
        if(s[i]=='?') cnt2++;
        else sum2+=s[i]-'0';
    }
    int mn=min(cnt2,cnt1);
    cnt1-=mn,cnt2-=mn;
    if(!cnt1 && !cnt2)
    {
        if(sum1 == sum2) cout << "Bicarp" << endl;
        else cout << "Monocarp" << endl;
        return 0;
    }
    if(!cnt1) swap(sum1,sum2),swap(cnt1,cnt2);
    if(sum1 > sum2) return cout << "Monocarp" << endl, 0;
    if(sum1 + cnt1 / 2 * 9 == sum2) cout << "Bicarp" << endl;
    else cout << "Monocarp" << endl;
}