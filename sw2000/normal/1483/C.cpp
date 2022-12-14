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
int n;
struct A
{
    int id,a,b,l,r;
}arr[N];
ll c[N];
int lb(int a){return a&-a;}
void add(int p,ll v)
{
    for(;p<=n;p+=lb(p))
        c[p]+=v;
}
ll query(int p)
{
    ll ret=0;
    for(;p;p-=lb(p))
        ret+=c[p];
    return ret;
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0);
//	freopen("1.txt","r",stdin);
	cin>>n;
	for(int i=1;i<=n;i++)
    {
        cin>>arr[i].a;
        arr[i].id=i;
    }
    for(int i=1;i<=n;i++)cin>>arr[i].b;
    sort(arr+1,arr+1+n,[](A a,A b){return a.a>b.a;});

    set<int>s;
    s.insert(-1);
    s.insert(n+2);
    for(int i=n;i;i--)
    {
        arr[i].l=*(--s.lower_bound(arr[i].id));
        arr[i].r=*(s.lower_bound(arr[i].id));
        s.insert(arr[i].id);
    }

    for(int i=1;i<=n;i++)
    {
        ll w=arr[i].b;
        if(arr[i].r!=n+2)
        {
            w=max(w,-(query(arr[i].r-1)-query(arr[i].id)));
        }
        if(arr[i].l!=-1)
        {
            w=max(w,-(query(arr[i].id)-query(arr[i].l)));
        }
        add(arr[i].id,w);
    }
    cout<<query(n);
	return 0;
}