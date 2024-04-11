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
int arr[N];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0);
//	freopen("1.txt","r",stdin);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>arr[i];
	sort(arr+1,arr+1+n);
	if(arr[n]>=arr[n-1]+arr[n-2])cout<<"NO";
	else
    {
        cout<<"YES"<<endl;
        cout<<arr[n-1];
        for(int i=1;i<=n;i++)if(i!=n-1)cout<<' '<<arr[i];
    }
	return 0;
}