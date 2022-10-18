#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll

const int N=2e5+100;

int x[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>x[i];
    sort(x+1,x+n+1);
    set<int> mn;
    for(int i=1;i<=n;i++)
        if(!mn.count(x[i]-1)&&!mn.count(x[i]))
            mn.insert(x[i]+1);
    set<int> mx;
    for(int i=1;i<=n;i++)
        if(!mx.count(x[i]-1))
            mx.insert(x[i]-1);
        else if(!mx.count(x[i]))
            mx.insert(x[i]);
        else
            mx.insert(x[i]+1);
    cout<<mn.size()<<" "<<mx.size();
}