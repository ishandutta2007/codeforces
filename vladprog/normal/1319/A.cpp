#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=110;

int r[N],b[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>r[i];
    for(int i=1;i<=n;i++)
        cin>>b[i];
    int cnt10=0,cnt01=0;
    for(int i=1;i<=n;i++)
        if(r[i]&&!b[i])
            cnt10++;
        else if(!r[i]&&b[i])
            cnt01++;
    if(cnt10>cnt01)
        cout<<1,exit(0);
    if(!cnt10)
        cout<<-1,exit(0);
    cout<<(cnt01+1+cnt10-1)/cnt10;
}