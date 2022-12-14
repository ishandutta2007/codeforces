#include<bits/stdc++.h>
#define fi first
#define se second
#define mid (l+r>>1)
#define endl '\n'
#define double long double
using namespace std;
typedef long long ll;
typedef pair<int, int>pii;
typedef vector<int>vi;
struct tri {int a, b, c;};
const int N = 2e5 + 10;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;

int n,arr[N];
bool solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>arr[i];

    int a=inf,b=0;
    for(int i=1;i<=n;i++)
    {
        if(arr[i]<b)return 0;
        arr[i]-=b;
        a=min(a,arr[i]);
        arr[i]-=a;
        b+=arr[i];
    }
    return 1;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
//    freopen("in.txt", "r", stdin);
    int _;cin>>_;
    while(_--)
        cout<<(solve()?"YES":"NO")<<endl;
    return 0;
}