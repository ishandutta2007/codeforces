#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef vector<int>vi;
typedef pair<int,int> pii;
const int inf=0x3f3f3f3f;
const ll linf=0x3f3f3f3f3f3f3f3f;
const int maxn=1e6+10;
const ll mod=1e9+7;
const double PI=acos(0)*2;

int arr[maxn];
ll solve()
{
    string s;cin>>s;
    int cnt=0,pre=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='-')pre++;
        else pre--;

        if(pre>cnt)
        {
            arr[cnt++]=i+1;
        }
    }

    ll ret=s.size();
    for(int i=0;i<cnt;i++)
        ret+=arr[i];
    return ret;
}

int main()
{
//    freopen("in.txt","r",stdin);
    ios::sync_with_stdio(false);cin.tie(0);
    int _;cin>>_;
    while(_--)
    {
        cout<<solve()<<endl;
    }
}