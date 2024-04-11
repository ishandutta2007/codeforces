#include<bits/stdc++.h>
#define fi first
#define se second
#define lo (o<<1)
#define ro (o<<1|1)
#define endl '\n'
using namespace std;
typedef long long ll;
typedef vector<int>vi;
typedef pair<int, int>pii;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const int N = 2e5 + 10;

int n,k,arr[N];
bool vis[N];
int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
//    freopen("1.txt","r",stdin);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    while(1)
    {
        int f=0;
        for(int i=1;i<=n;i++)
        {
            if(arr[i]%2)f=1;
        }
        if(f)break;

        for(int i=1;i<=n;i++)
        {
            arr[i]/=2;
        }
    }

    int sum=0;
    for(int i=1;i<=n;i++)sum+=arr[i];
    if(sum%2)
    {
        cout<<0;
        return 0;
    }
    vis[0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=N-1;j>=arr[i];j--)
        {
            if(vis[j-arr[i]])vis[j]=1;
        }
    }
    if(!vis[sum/2])
    {
        cout<<0;
        return 0;
    }
    cout<<1<<endl;
    for(int i=1;i<=n;i++)
    {
        if(arr[i]%2)
        {
            cout<<i<<endl;
            return 0;
        }
    }
	return 0;
}