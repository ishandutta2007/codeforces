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
void solve()
{
    int n;string s;cin>>n>>s;
    if(s[0]=='0'||s.back()=='0')
    {
        cout<<"NO";
        return;
    }
    int cnt=0,id[2]{};
    for(int i=0;i<n;i++)
    {
        if(s[i]=='0')cnt++;
        if(s[i]=='0')id[1]=i;
    }
    for(int i=n-1;~i;i--)
    {
        if(s[i]=='0')id[0]=i;
    }
    if(cnt%2)
    {
        cout<<"NO";
        return;
    }
    cout<<"YES"<<endl;
    if(!cnt)
    {
        for(int i=0;i<n;i++)cout<<(i%2?')':'(');
        cout<<endl;
        for(int i=0;i<n;i++)cout<<(i%2?')':'(');
        return;
    }
    s[id[0]-1]=' ';
    s[id[1]+1]=' ';
    string ans(n,' ');
    ans[id[0]-1]='(';
    ans[id[1]+1]=')';
    bool f=0;
    for(int i=0;i<n;i++)if(s[i]=='1')
    {
        if(!f)ans[i]='(',f=1;
        else ans[i]=')',f=0;
    }
    for(int i=0;i<n;i++)if(s[i]=='0')
    {
        if(!f)ans[i]='(',f=1;
        else ans[i]=')',f=0;
    }
    cout<<ans<<endl;
    for(int i=0;i<n;i++)if(s[i]=='0')
    {
        if(!f)ans[i]=')',f=1;
        else ans[i]='(',f=0;
    }
    cout<<ans;
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0);
//	freopen("1.txt","r",stdin);
    int _;cin>>_;
    while(_--)
    {
        solve();
        cout<<endl;
    }
	return 0;
}