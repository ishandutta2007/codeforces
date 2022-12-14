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
const int N = 1e6 + 10;
const int mod = 1e9 + 7;

int n,k;
ll sum=1;
int c[N],arr[N];
bool solve(int h)
{
    memset(c,0,sizeof(c));
    c[0]=1;
    c[1]=-1;
    sum=1;
    int st=0;

    for(int i=0;i<n;i++)
    {
        while(!c[st])st++;

        c[st]--;
        c[st+1]++;
        sum+=min(arr[i]-2,(h-st)*2-3);
        c[st+2]+=2;
        c[st+arr[i]/2+2]--;
        c[st+(arr[i]+1)/2+1]--;
//        if(h==5)
//        {
//            for(int j=0;j<20;j++)
//                cout<<c[j]<<' ';
//            cout<<endl;
//        }
        if(sum>=k)return 1;
    }
    return 0;
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0);
//	freopen("1.txt","r",stdin);
	cin>>n>>k;
	for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        sum+=arr[i]-2;
    }
    if(sum<k)
    {
        cout<<-1;
        return 0;
    }
    sort(arr,arr+n,greater<int>() );
    int l=1,r=inf;
    while(l<r-1)
    {
        if(solve(mid))r=mid;
        else l=mid;
    }
    cout<<r;
	return 0;
}