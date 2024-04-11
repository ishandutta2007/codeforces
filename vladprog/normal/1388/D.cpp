#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=2e5+100;

int a[N],b[N];
bool used[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        cin>>b[i];
    vector<int> ord;
    for(int i=1;i<=n;i++)
    {
        vector<int> cur;
        for(int j=i;j!=-1&&!used[j];j=b[j])
            cur.push_back(j),
            used[j]=true;
        ord.insert(ord.end(),cur.rbegin(),cur.rend());
    }
    reverse(ord.begin(),ord.end());
    vector<int> p1,p2;
    int ans=0;
    for(int i:ord)
    {
        ans+=a[i];
        if(a[i]>0)
            a[b[i]]+=a[i],
            p1.push_back(i);
        else
            p2.push_back(i);
    }
    reverse(p2.begin(),p2.end());
    cout<<ans<<"\n";
    for(int x:p1)
        cout<<x<<" ";
    for(int x:p2)
        cout<<x<<" ";
}