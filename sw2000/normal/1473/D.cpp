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
char s[N];
int n,m;
struct tri
{
    int a,b,c;
}arr[N],brr[N];
void solve()
{
    cin>>n>>m;
    cin>>(s+1);
    for(int i=1;i<=n;i++)
    {
        arr[i]=arr[i-1];
        if(s[i]=='+')arr[i].b++;
        else arr[i].b--;
        arr[i].a=min(arr[i].a,arr[i].b);
        arr[i].c=max(arr[i].c,arr[i].b);
    }
    brr[n+1]={0,0,0};
    for(int i=n;i;i--)
    {
        brr[i]=brr[i+1];
        if(s[i]=='+')brr[i].b++;
        else brr[i].b--;
        brr[i].a=min(brr[i].a,brr[i].b);
        brr[i].c=max(brr[i].c,brr[i].b);
//        cout<<brr[i].a<<' '<<brr[i].b<<' '<<brr[i].c<<endl;
    }
    while(m--)
    {
        int l,r;
        cin>>l>>r;
        int a=min(arr[l-1].b+brr[r+1].b-brr[r+1].c,arr[l-1].a);
        int c=max(arr[l-1].b+brr[r+1].b-brr[r+1].a,arr[l-1].c);

//        cout<<a<<' '<<c<<endl;
        cout<<(c-a+1)<<endl;
    }
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
//    freopen("1.txt","r",stdin);
    int _;cin>>_;
    while(_--)
    {
        solve();
    }
    return 0;
}