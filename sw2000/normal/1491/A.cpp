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
typedef pair<int, int>pii;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const int N = 2e5 + 10;
const int mod = 1e9 + 7;
int arr[N];
int cnt=0;
int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
//    freopen("1.txt","r",stdin);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        if(arr[i])cnt++;
    }
    for(int i=0;i<m;i++)
    {
        int x,y;cin>>x>>y;
        if(x==1)
        {
            if(arr[y])cnt--;
            else cnt++;
            arr[y]=1-arr[y];
        }
        else
        {
            if(y<=cnt)cout<<1<<endl;
            else cout<<0<<endl;
        }
    }

    return 0;
}