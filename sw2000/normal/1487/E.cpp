#include<bits/stdc++.h>
#define fi first
#define se second
#define lo (o<<1)
#define ro (o<<1|1)
#define mid (l+r>>1)
#define endl '\n'
using namespace std;
typedef long long ll;
typedef vector<int>vi;
typedef pair<ll, int>pii;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const int N = 2e5 + 10;
const int mod = 1e9 + 7;
int n[4];
pii arr[4][N];
set<int>s[4][N];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0);
//	freopen("1.txt","r",stdin);
	for(int i=0;i<4;i++)cin>>n[i];
	for(int i=0;i<4;i++)
    {
        for(int j=1;j<=n[i];j++)
        {
            cin>>arr[i][j].fi;
            arr[i][j].se=j;
        }
        arr[i][n[i]+1]={inf,0};
    }
    for(int i=1;i<=3;i++)
    {
        int m;
        cin>>m;
        while(m--)
        {
            int a,b;
            cin>>a>>b;
            s[i][b].insert(a);
        }
    }
    sort(arr[0]+1,arr[0]+n[0]+1);
    for(int i=1;i<=3;i++)
    {
        for(int j=1;j<=n[i];j++)
        {
            for(int k=1;;k++)
            {
                if(!s[i][j].count(arr[i-1][k].se))
                {
                    arr[i][j].fi+=arr[i-1][k].fi;
                    break;
                }
            }
        }
        sort(arr[i]+1,arr[i]+n[i]+1);
    }
    cout<<(arr[3][1].fi>=inf?-1:arr[3][1].fi);
	return 0;
}