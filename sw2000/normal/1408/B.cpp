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
    int n,k,a[110],cnt=1;
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(i&&a[i]!=a[i-1])cnt++;
    }
    if(k==1)
    {
        if(cnt==1)return 1;
        else return -1;
    }
    if(cnt<=k)return 1;
    else return (cnt-2)/(k-1)+1;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
//    freopen("in.txt","r",stdin);
    int _;cin>>_;
    while(_--)
        cout<<solve()<<endl;
    return 0;
}