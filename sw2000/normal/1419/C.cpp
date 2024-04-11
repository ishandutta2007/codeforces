#include <bits/stdc++.h>
#define x first
#define y second
#define mid (l+r>>1)
#define lo (o<<1)
#define ro (o<<1|1)
using namespace std;
typedef long long ll;
typedef vector<int>vi;
typedef pair<int,int>pii;
struct tri{int x,y,z;};
const int inf=0x3f3f3f3f;
const ll linf=0x3f3f3f3f3f3f3f3f;
const int N=1e5+10;
const ll mod=1e9+7;
const double PI=acos(0)*2;
int solve()
{
    int n,x;cin>>n>>x;
    int sum=0,cnt=0;
    for(int i=0;i<n;i++)
    {
        int a;cin>>a;
        if(a==x)cnt++;
        sum+=a;
    }
    if(cnt==n)return 0;
    if(cnt||n*x==sum)return 1;
    return 2;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
//    freopen("in.txt","r",stdin);
    int _;cin>>_;
    while(_--)
    {
        cout<<solve()<<endl;
    }
    return 0;
}