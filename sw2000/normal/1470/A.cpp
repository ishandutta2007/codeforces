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
const int N = 3e5 + 10;
const int mod = 1e9 + 7;

int n,m;
int arr[N],brr[N];
ll solve()
{
    ll ret=0;
    priority_queue<int,vector<int>,greater<int> >q,p;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>arr[i];
    for(int i=1;i<=m;i++)
        cin>>brr[i];
    sort(arr+1,arr+1+n);
    for(int i=1,j=0;i<=n;i++)
    {
        while(j<arr[i])
            q.push(brr[++j]);
        q.push(brr[arr[i]]);
        ret+=q.top();
        q.pop();
    }
    return ret;
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
//	freopen("1.txt","r",stdin);
    int _;
    cin>>_;
    while(_--)
    {
        cout<<solve()<<endl;
    }
    return 0;
}