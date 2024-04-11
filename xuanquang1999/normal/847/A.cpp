#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

const int maxn=200;

int l[maxn],r[maxn],H[maxn],E[maxn],n1,n;

int dfs(int u)
{
    if (r[u]==0) return u;
    else dfs(r[u]);
}

int main()
{
    cin >> n;
    for (int i=1; i<=n; ++i) cin >> l[i] >> r[i];
    for (int i=1; i<=n; ++i) 
        if (l[i]==0) 
        {
            n1++;
            H[n1]=i;
            E[n1]=dfs(i);
        }
    r[E[1]]=H[2];
    for (int i=2; i<n1; ++i)
    {
        l[H[i]]=E[i-1];
        r[E[i]]=H[i+1];
    }
    l[H[n1]]=E[n1-1];
    for (int i=1; i<=n; ++i)
        cout << l[i] << " " << r[i] << endl;
}