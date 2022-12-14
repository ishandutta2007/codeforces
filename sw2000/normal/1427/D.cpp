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
int n,st,a[100],b[100];
int ans_cnt;
vi ans[100];
void f()
{
    vi ret;
    if(st!=1)ret.push_back(st-1);
    int p=a[st];
    while(a[st+1]==a[st]+1)st++;
    ret.push_back(st);
    while(a[st]!=p-1)st++;
    ret.push_back(st);
    if(st!=n)ret.push_back(n);

    int cnt=n;
    for(int i=0;i<ret.size();i++)
    {
        for(int j=ret[i];;j--)
        {
            if(j==0)break;
            if(i&&j==ret[i-1])break;
            b[cnt--]=a[j];
        }
    }
    for(int i=1;i<=n;i++)a[i]=b[i];

    for(int i=ret.size()-1;i;i--)
    {
        ret[i]-=ret[i-1];
    }
    ans[++ans_cnt].swap(ret);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
//    freopen("in.txt", "r", stdin);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=0;;i++)
    {
        st=1;
        while(a[st]==a[st-1]+1)st++;
//        cout<<st<<endl;
        if(st==n+1)break;
        f();
    }
    cout<<ans_cnt<<endl;
    for(int i=1;i<=ans_cnt;i++)
    {
        cout<<ans[i].size()<<' ';
        for(auto j:ans[i])
            cout<<j<<' ';
        cout<<endl;
    }
    return 0;
}