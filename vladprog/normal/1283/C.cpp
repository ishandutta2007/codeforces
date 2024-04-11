#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll

const int N=2e5+100;

int f[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>f[i];
    set<int> zero,non;
    for(int i=1;i<=n;i++)
        if(f[i]==0)
            zero.insert(i);
        else
            non.insert(i);
    for(int i=1;i<=n;i++)
        zero.erase(f[i]),
        non.erase(f[i]);
    vector<int> from,to;
    for(int i=1;i<=n;i++)
        if(f[i]==0)
        {
            from.push_back(i);
            if(zero.count(i))
                to.push_back(i);
            else
                to.push_back(*non.begin()),
                non.erase(non.begin());
        }
    int k=from.size();
    for(int i=0;i<k;i++)
        f[from[i]]=to[(i+1)%k];
    for(int i=1;i<=n;i++)
        cout<<f[i]<<" ";

}