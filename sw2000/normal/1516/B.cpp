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
const int N = 1e5 + 10;

int n,k,arr[N];
bool solve()
{
    cin>>n;
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        sum^=arr[i];
    }
    if(!sum)return 1;

    int l=inf,r=-1,tmp=0;
    for(int i=1;i<=n;i++)
    {
        tmp^=arr[i];
        if(tmp==sum)
        {
            l=i;
            break;
        }
    }
    tmp=0;
    for(int i=n;i;i--)
    {
        tmp^=arr[i];
        if(tmp==sum)
        {
            r=i;
            break;
        }
    }
    return l<r;
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
//    freopen("1.txt","r",stdin);
    int _;
    cin>>_;
    while(_--)
    {
        cout<<(solve()?"YES":"NO")<<endl;
    }
	return 0;
}