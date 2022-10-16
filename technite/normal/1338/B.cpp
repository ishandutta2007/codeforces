#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define F first
#define S second
#define append push_back
#define forn(i, n) for(int i = 0; i < n; ++i)
#define forl(i, n) for(long long i=0;i<n;++i)
#define endl "\n";
typedef long long ll;
ll exp(ll n, ll m, ll md){
    ll a = 1;
    while (m > 0){
        if (m&1) a = (a * n%md) % md;
        m /= 2;
        n = (n*n) % md;
    }
    return a % md;
}
int main()
{
    fast;
    int n, a, b, index, count = 0;
    cin>>n;
    std::vector<int> adj[n];
    for (int i=0;i<n-1;i++)
    {
        cin>>a>>b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }
    bool leaf[n];
    for (int i=0;i<n;i++)
    {
        leaf[i] = (adj[i].size() == 1);
        if (leaf[i])
        {
            index = i;
            count++;
        }
    }
    queue<int> q;                          
    bool visited[n] = {false};
    int distance[n];
 
    visited[index] = true;
    distance[index] = 0;
    q.push(index);
    while (!q.empty())
    {
        int s = q.front();
        q.pop();
        for (auto u : adj[s])
        {
            if (visited[u]) continue;
            visited[u] = true;
            distance[u] = distance[s] + 1;
            q.push(u);
        }
    }
    bool x = true;
    for (int i=0;i<n;i++)
    {
        if (leaf[i]&&distance[i]%2==1)
        {
            x = false;
            break;
        }
    }
    if (x)
        cout<<"1 ";
    else
        cout<<"3 ";
    set<int> s;
    for (int i=0;i<n;i++)
    {
        if (leaf[i])
            s.insert(adj[i][0]);
    }
    cout<<(n-1) - (count - s.size());
}