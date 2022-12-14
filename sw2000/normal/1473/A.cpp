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
const ll mod = 1e9 + 7;
bool solve()
{
    int n,d,arr[110];
    cin>>n>>d;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int m1=inf,m2=inf;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>d)break;
        else if(i==n-1)return 1;
    }
    for(int i=0;i<n;i++)
    {
        if(arr[i]<m1)
        {
            m2=m1;
            m1=arr[i];
        }
        else if(arr[i]<m2)
        {
            m2=arr[i];
        }
    }
    if(m1+m2<=d)return 1;
    else return 0;
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
//    freopen("1.txt","r",stdin);
    int _;cin>>_;
    while(_--)
    {
        cout<<(solve()?"YES":"NO")<<endl;
    }
    return 0;
}