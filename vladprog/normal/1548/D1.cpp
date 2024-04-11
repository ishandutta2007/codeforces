#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    int cnt[4][4]={};
    for(int i=1;i<=n;i++)
    {
        int x,y;
        cin>>x>>y;
        cnt[x%4][y%4]++;
    }
    cout<<(cnt[0][0]*(cnt[0][0]-1)*(cnt[0][0]-2)/6+
           cnt[0][0]*(cnt[0][0]-1)/2*cnt[0][2]+
           cnt[0][0]*(cnt[0][0]-1)/2*cnt[2][0]+
           cnt[0][0]*(cnt[0][0]-1)/2*cnt[2][2]+
           cnt[0][2]*(cnt[0][2]-1)/2*cnt[0][0]+
           cnt[2][0]*(cnt[2][0]-1)/2*cnt[0][0]+
           cnt[2][2]*(cnt[2][2]-1)/2*cnt[0][0]+
           cnt[0][2]*(cnt[0][2]-1)*(cnt[0][2]-2)/6+
           cnt[0][2]*(cnt[0][2]-1)/2*cnt[2][0]+
           cnt[0][2]*(cnt[0][2]-1)/2*cnt[2][2]+
           cnt[2][0]*(cnt[2][0]-1)/2*cnt[0][2]+
           cnt[2][2]*(cnt[2][2]-1)/2*cnt[0][2]+
           cnt[2][0]*(cnt[2][0]-1)*(cnt[2][0]-2)/6+
           cnt[2][0]*(cnt[2][0]-1)/2*cnt[2][2]+
           cnt[2][2]*(cnt[2][2]-1)/2*cnt[2][0]+
           cnt[2][2]*(cnt[2][2]-1)*(cnt[2][2]-2)/6);
}