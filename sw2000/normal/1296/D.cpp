#include <bits/stdc++.h>
#define x first
#define y second
#define mid (l + r >> 1)
#define lo (o << 1)
#define ro (lo | 1)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int maxn = 2e5 + 10;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
struct tri{int x,y,z;};

int arr[maxn];
 
int main()
{
    // freopen("in.txt","r",stdin);
    int n,a,b,k;cin>>n>>a>>b>>k;
    for(int i=0;i<n;i++)
    {
        scanf("%d",arr+i);
        arr[i]%=a+b;
        if(!arr[i])arr[i]=a+b;
    }
    for(int i=0;i<n;i++)
    {
        arr[i]=(arr[i]-1)/a;
    }
    sort(arr,arr+n);
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(k>=arr[i])
        {
            k-=arr[i];
            ans++;
        }
        else break;
    }
    cout<<ans;
    return 0;
}