#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int a[100005];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;++i) cin>>a[i];
    int nxt=0,cur=0,ans=0;
    while(cur<n)
    {
        ans++;nxt++;
        while(cur<nxt)
        {
            cur++;
            if(cur>n) break;
            nxt = max(nxt, a[cur]);
        }
        cur = nxt;
    }
    cout << ans << endl;
}