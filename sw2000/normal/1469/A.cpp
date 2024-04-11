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

bool solve()
{
    string s;cin>>s;
    if(s.size()%2)return 0;

    int a=0,b=0;
    for(auto i:s)
    {
        if(i=='(')a++;
        else if(i=='?')b++;
        else
        {
            if(a)a--;
            else if(b)b--;
            else return 0;
        }
    }
    a=0,b=0;
    for(int i=s.size()-1;~i;i--)
    {
        if(s[i]==')')a++;
        else if(s[i]=='?')b++;
        else
        {
            if(a)a--;
            else if(b)b--;
            else return 0;
        }
    }
    return 1;
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
//	freopen("1.txt","r",stdin);
    int _;cin>>_;
    while(_--)
        cout<<(solve()?"YES":"NO")<<endl;
	return 0;
}