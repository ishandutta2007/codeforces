
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int cnt[11];
int main()
{
    int n;
    cin>>n;
    int ans = 0;
    for(int i=1;i<=n;++i)
    {
        int tmp;
        cin>>tmp;
        cnt[tmp]++;
        int ok = 1;
        vector<int> v;
        for(int j=1;j<=10;++j)
        {
            if(!cnt[j]) continue;
            v.push_back(cnt[j]);
        }
        sort(v.begin(),v.end());
        for(int i=0;i<v.size()-1;++i) if(v[i]!=v[0]) ok = 0;
        if(v.size()>1 && v[v.size()-1] != v[0]+1) ok = 0;
        if(ok) ans = max(ans, i);
        ok = 1;
        if(v[0]==1)
        {
            for(int i=1;i<v.size();++i) if(v[i]!=v[1]) ok = 0;
        }
        else ok = 0;
        if(ok) ans=max(ans,i);
    }
    cout << ans << endl;
}