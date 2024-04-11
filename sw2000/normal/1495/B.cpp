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
const int mod = 1e9 + 7;

int n,arr[N],l[N],r[N];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0);
//	freopen("1.txt","r",stdin);
	cin>>n;
	for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        l[i]=r[i]=1;
    }
    for(int i=2;i<=n;i++)
    {
        if(arr[i]>arr[i-1])l[i]=l[i-1]+1;
    }
    for(int i=n-1;i;i--)
    {
        if(arr[i]>arr[i+1])r[i]=r[i+1]+1;
    }

    int ma=0,cnt,id;
    for(int i=1;i<=n;i++)
    {
//        cout<<l[i]<<" "<<r[i]<<endl;
        if(max(l[i],r[i])>ma)
        {
            ma=max(l[i],r[i]);
            cnt=1;
            id=i;
        }
        else if(max(l[i],r[i])==ma)
        {
            cnt++;
        }
    }
    if(cnt!=1||l[id]!=r[id]||ma%2==0)
    {
        cout<<0;
        return 0;
    }
    cout<<1;
	return 0;
}