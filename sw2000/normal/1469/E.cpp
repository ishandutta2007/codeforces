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

bool arr[N];
void solve()
{
    int n,k;
    cin>>n>>k;
    string str;
    cin>>str;
    set<int>s;
    for(int i=0;i<n;i++)
    {
        arr[i]=(str[i]=='0');
    }
    int a=0,last=inf;
    for(int i=0;i<n;i++)
    {
        a<<=1;
        a|=arr[i];

        last++;
        if(a&1<<min(30,k))
        {
            last=min(30,k);
            a^=1<<min(30,k);
        }

        if(i>=k-1&&last>=k)s.insert(a);
    }
    int ans=0;
    while(s.count(ans))ans++;
    if(k<=30&&ans>=(1<<k))
    {
        cout<<"NO"<<endl;
        return;
    }

    cout<<"YES"<<endl;
    for(int i=k-1;~i;i--)
    {
        if(i>30)cout<<0;
        else cout<<((ans&1<<i)!=0);
    }
    cout<<endl;
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0);
//	freopen("1.txt","r",stdin);
	int _;
	cin>>_;
	while(_--)
	solve();
	return 0;
}