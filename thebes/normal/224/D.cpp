#include <bits/stdc++.h>
using namespace std;

string s, t;

bool solve()
{
    int sn=s.size(),tn=t.size();
    vector<int> a[256];
    for (int i=0;i<tn;++i)
        a[t[i]].push_back(i);
    int b[256],cnt=0;
    memset(b,-1,sizeof(b));
    vector<int> x(sn);
    for (int i=0;i<sn;++i)
    {
        if (a[s[i]].empty())
            continue;
        if (a[s[i]].size()>b[s[i]]+1 && cnt==a[s[i]][b[s[i]]+1])
        {
            b[s[i]]++;
            cnt++;
        }
        if (b[s[i]]>=0)
            x[i]=a[s[i]][b[s[i]]]+1;
    }
    for (int i=0;i<sn;++i)
        fprintf(stderr,"%d ",x[i]);
    fprintf(stderr,"\n");
    vector<int> y(sn);
    for (int i=0;i<256;++i)
        b[i]=a[i].size();
    cnt = tn-1;
    for (int i=sn-1;i>=0;--i)
    {
        if (a[s[i]].empty())
            continue;
        if (b[s[i]]-1>=0 && cnt==a[s[i]][b[s[i]]-1])
        {
            b[s[i]]--;
            cnt--;
        }
        if (b[s[i]]<a[s[i]].size())
            y[i]=tn-a[s[i]][b[s[i]]];
    }
    for (int i=0;i<sn;++i)
        fprintf(stderr,"%d ",y[i]);
    fprintf(stderr,"\n");
    bool yes=true;
    for (int i=0;i<sn;++i)
        if (x[i]+y[i]<=tn)
            yes = false;
    if (yes)
        printf("Yes\n");
    else
        printf("No\n");
    return true;
}

int main()
{
    cin >> s >> t;
    solve();
    return 0;
}