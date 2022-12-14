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
const int M = 1e7 + 10;
const int mod = 1e9 + 7;
int n,k,arr[N];
int to[M];
int solve()
{
    cin>>n>>k;
//    for(int i=0;i<n;i++)
//        cin>>arr[i];
    int ret=1;
    set<int>s;
    for(int i=0;i<n;i++)
    {
        int a;cin>>a;
//        cout<<to[a]<<endl;
        if(s.count(to[a]))
        {
            s.clear();
            ret++;
        }
        s.insert(to[a]);
    }
    return ret;
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0);
//	freopen("1.txt","r",stdin);
    for(int i=0;i<M;i++)to[i]=i;
    for(int i=2;i*i<M;i++)
    {
        for(int j=i*i;j<M;j+=i*i)
        {
            while(to[j]%(i*i)==0)
            {
                to[j]/=i*i;
            }
        }
    }
//    for(int i=0;i<20;i++)cout<<to[i]<<endl;
    int _;cin>>_;
    while(_--)
    {
        cout<<solve()<<endl;
    }
	return 0;
}