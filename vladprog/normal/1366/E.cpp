#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=2e5+100,MOD=998244353;

int a[N],b[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int j=1;j<=m;j++)
        cin>>b[j];
    if(*min_element(a+1,a+n+1)!=b[1])
        cout<<0,exit(0);
    map<int,int> cnt;
    for(int i=n,cur=a[n];i>=1;i--,cur=min(cur,a[i]))
        cnt[cur]++;
    int ans=1;
    for(int i=2;i<=m;i++)
        ans=ans*cnt[b[i]]%MOD;
    cout<<ans;
}