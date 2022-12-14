#include <bits/stdc++.h>
#define fi first
#define se second
#define mid (l+r>>1)
#define lo (o<<1)
#define ro (o<<1|1)
using namespace std;
typedef long long ll;
typedef vector<int>vi;
typedef pair<int, int>pii;
struct tri {int a, b, c;};
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const int N = 1e5 + 10;
const ll mod = 1e9 + 7;
const double PI = acos(0) * 2;

int solve()
{
    int n,k,ret=0;
    cin>>n>>k;
    string s;
    cin>>s;
    vi v;
    int left=0;
    int st=0;
    while(st<n&&s[st]=='L')st++;
    if(st==n)
    {
        k=min(k,n);
        if(k==0)return 0;
        return k*2-1;
    }
    int cnt=0;
    for(int i=st;i<n;i++)
    {
        if(s[i]=='L')cnt++;
        else
        {
            if(cnt)v.push_back(cnt);
            cnt=0;

            if(i&&s[i-1]=='W')ret+=2;
            else ret++;
        }
    }
    st+=cnt;
    sort(v.begin(),v.end());
    for(int i:v)
    {
        if(i<=k)
        {
            ret+=i*2+1;
            k-=i;
        }
        else
        {
            ret+=k*2;
            return ret;
        }
    }
    k=min(k,st);
    ret+=k*2;
    return ret;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
//    freopen("in.txt", "r", stdin);
    int _;
    cin>>_;
    while(_--)
    {
        cout<<solve()<<endl;
    }
    return 0;
}