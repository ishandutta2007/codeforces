#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=1e6+5;
int pr[maxn];
vector <int> ch[maxn];
int cnt[maxn];
string s;
void upd(int i)
{
    if(ch[i].size()==0)
    {
        if(s[i]=='?')
        {
            cnt[i]=2;
        }
        else
        {
            cnt[i]=1;
        }
        if(pr[i]!=(-1)) upd(pr[i]);
        return;
    }
    if(s[i]=='0')
    {
        cnt[i]=cnt[ch[i][0]];
    }
    else if(s[i]=='1')
    {
        cnt[i]=cnt[ch[i][1]];
    }
    else
    {
        cnt[i]=cnt[ch[i][0]]+cnt[ch[i][1]];
    }
    if(pr[i]!=(-1)) upd(pr[i]);
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<(1<<n);++i)
    {
        cnt[i]=1;
        for(int j=(n-1);j>=0;j--)
        {
            if(!(i & (1<<j)))
            {
                pr[i]=(i+(1<<j)-(i%(1<<j)+1)/2);
                ch[pr[i]].push_back(i);
                break;
            }
        }
    }
    pr[(1<<n)-2]=(-1);
    cin>>s;
    for(int i=0;i<s.size();++i)
    {
        upd(i);
    }
    int q;
    cin>>q;
    while(q--)
    {
        int pos;char c;
        cin>>pos>>c;
        pos--;
        s[pos]=c;
        upd(pos);
        cout<<cnt[(1<<n)-2]<<'\n';
    }
    return 0;
}