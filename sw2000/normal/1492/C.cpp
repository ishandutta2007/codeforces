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
struct tri{int a,b,c;};
int n,m,mi[130],ma[130];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0);
//	freopen("1.txt","r",stdin);
	cin>>n>>m;
	string s,t;
	cin>>s>>t;
	vector<int>l,r;
	for(int i=0,j=0;i<n;i++)
    {
        if(j!=m&&s[i]==t[j])
        {
            l.push_back(i);
            j++;
        }
    }
    int ans=0;
    for(int i=n-1,j=m-1;i>=0;i--)
    {
        if(m>=0&&s[i]==t[j])
        {
            j--;
            r.push_back(i);
            l.pop_back();
            if(!l.empty())
            {
                ans=max(ans,r.back()-l.back());
            }
        }
    }
    cout<<ans;
	return 0;
}