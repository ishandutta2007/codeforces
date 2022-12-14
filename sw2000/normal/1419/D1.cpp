#include <cmath> //
#include <cstdio> //
#include <cstdlib> //
#include <cstring> //
#include <algorithm> //STL 
#include <cmath>
#include <list> //STL 
#include <map> //STL 
#include <iostream>
#include <queue> //STL 
#include <set> //STL #
#include <stack> //STL 
#include <string> //
#include <vector> //STL 
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
const ll mod=998244353;
const double PI=acos(0)*2;
int n,arr[N];
vi v;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
//    freopen("in.txt","r",stdin);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>arr[i];
    sort(arr+1,arr+1+n);
    if(n&1^1)v.push_back(arr[n/2]);
    for(int i=1;i<=(n-1)/2;i++)
    {
        v.push_back(arr[n/2+i]);
        v.push_back(arr[i]);
    }
    v.push_back(arr[n]);
    int ans=0;
    for(int i=1;i<v.size()-1;i++)
        if(v[i-1]>v[i]&&v[i]<v[i+1])ans++;
    cout<<ans<<endl;
    for(auto i:v)cout<<i<<' ';
    return 0;
}