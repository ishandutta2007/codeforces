#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef vector<int>vi;
typedef pair<int,int> pii;
const int inf=0x3f3f3f3f;
const ll linf=0x3f3f3f3f3f3f3f3f;
const int maxn=2e5+10;
const ll mod=1e9+7;
const double PI=acos(0)*2;

int n,arr[maxn];
int solve()
{
    cin>>n;
    bool f=1;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        if(arr[i]!=i)f=0;
    }
    if(f)return 0;
    arr[n+1]=n+1;
    int l=1,r=n;
    while(arr[l]==l)l++;
    while(arr[r]==r)r--;
    for(int i=l;i<=r;i++)
        if(arr[i]==i)return 2;
    return 1;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);
//    freopen("in.txt","r",stdin);
    int _;cin>>_;
    while(_--)
    {
        cout<<solve()<<endl;
    }
    return 0;
}