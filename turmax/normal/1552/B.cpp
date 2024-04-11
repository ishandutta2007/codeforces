#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector <int> a[n];
        for(int i=0;i<n;++i) {vector <int> v(5);for(int j=0;j<5;++j) {cin>>v[j];v[j]*=(-1);};a[i]=v;}
        set <int> o;
        for(int i=0;i<n;++i) o.insert(i);
        while(o.size()!=1)
        {
            int x=(*o.begin());o.erase(o.begin());int y=(*o.begin());o.erase(o.begin());
            int sum=0;
            for(int i=0;i<5;++i) sum+=(a[x][i]<a[y][i]);
            if(sum>=3) o.insert(y);
            else o.insert(x);
        }
        int x=(*o.begin());bool ok=1;
        for(int i=0;i<n;++i)
        {
            int sum=0;
            for(int j=0;j<5;++j) sum+=(a[x][j]>=a[i][j]);
            ok=(ok && sum>=3);
        }
        if(ok) cout<<x+1<<'\n';
        else cout<<(-1)<<'\n';
    }
    return 0;
}