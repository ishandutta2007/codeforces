#include<bits/stdc++.h>
#define fi first
#define se second
#define lo (o<<1)
#define ro (o<<1|1)
#define mid (l+r>>1)
#define endl '\n'
using namespace std;
typedef long long ll;
typedef vector<string>pol;
typedef pair<int, int>pii;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const int N = 1e6 + 10;
const int mod = 1e9+7;
int n,L,arr[N],brr[N];
bool can(int d)
{
    int r=inf,l=-inf;
    for(int i=0;i<n;i++)
    {
        r=min(r,(int)(upper_bound(brr,brr+n*3,arr[i]+d)-brr-1-i));
        l=max(l,(int)(lower_bound(brr,brr+n*3,arr[i]-d)-brr-i));
    }
    return l<=r;
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
//	freopen("1.txt","r",stdin);
	cin>>n>>L;
	for(int i=0;i<n;i++)cin>>arr[i];
	for(int i=0;i<n;i++)cin>>brr[i];
	sort(arr,arr+n);
	sort(brr,brr+n);
	for(int i=n;i<n*3;i++)brr[i]=brr[i-n];
	for(int i=0;i<n;i++)brr[i]-=L;
	for(int i=n*2;i<n*3;i++)brr[i]+=L;

	int l=-1,r=L/2;
	while(l<r-1)
    {
        if(can(mid))r=mid;
        else l=mid;
    }
    cout<<r;
//    cout<<can(1)<<endl;
	return 0;
}