#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int maxn=1e5+10;
const int inf=0x3f3f3f3f;
const ll mod=1e9+7;
const ll linf=0x3f3f3f3f3f3f3f3f;

int main()
{
//    freopen("in.txt","r",stdin);
    int n,m;
    cin>>n>>m;
    string a[30],b[30];
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<m;i++)cin>>b[i];
    string ans[900];
    for(int i=0;i<n*m;i++)
    {
        ans[i]=a[i%n]+b[i%m];
    }
    int t;
    cin>>t;
    while(t--)
    {
        int x;
        cin>>x;
        cout<<ans[(x-1)%(n*m)]<<endl;
    }

    return 0;
}