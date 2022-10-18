#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int M=1e5+100;

int l[M],mx[M];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
        cin>>l[i];
    int s=0;
    for(int i=1;i<=m;i++)
        s+=l[i];
    if(s<n)
        cout<<-1,exit(0);
    for(int i=m;i>=1;i--)
        mx[i]=max(mx[i+1],l[i]+i-1);
    if(mx[1]>n)
        cout<<-1,exit(0);
    int cur=0;
    cout<<1<<" ";
    for(int i=2;i<=m;i++)
        cur+=min(n-mx[i]-cur,l[i-1]-1),
        cout<<i+cur<<" ";
}