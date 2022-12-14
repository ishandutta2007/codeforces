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

int l,r;
struct A{int a,b,c;};
vector<A>ans;
int main()
{
//    freopen("1.txt","r",stdin);
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>l>>r;
    ans.push_back({1,32,l});
    l++;
    cout<<"YES"<<endl;
    cout<<"32 ";
    for(int i=0;i<20;i++)
    {
        for(int j=0;j<=i;j++)
        {
            ans.push_back({31-i,32-i+j,1<<i});
        }
        if(r-l+1>=(1<<i))
        {
            ans.push_back({1,31-i,l-(1<<i)});
            l+=1<<i;
        }
    }
    ans.push_back({1,2,1});
    if(r-l+1>0)
    {
        ans.push_back({2,32,l-1});
        l++;
        for(int i=0;i<20;i++)
        {
            if((r-l+1)&1<<i)
            {
                ans.push_back({2,31-i,l-(1<<i)-1});
                l+=1<<i;
            }
        }
    }

    cout<<ans.size()<<endl;
    for(auto i:ans)
    {
        cout<<i.a<<' '<<i.b<<' '<<i.c<<endl;
    }
	return 0;
}