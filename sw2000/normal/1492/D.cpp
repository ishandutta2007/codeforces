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
	int a,b,k;
	cin>>a>>b>>k;
    string s(a+b,'0');
    for(int i=0;i<b;i++)s[i]='1';
	if(k==0)
    {
        cout<<"YES"<<endl<<s<<endl<<s<<endl;
        return 0;
    }
	if(k>=a+b-1||a==0||b==1)
    {
        cout<<"No"<<endl;
        return 0;
    }
    cout<<"Yes"<<endl;
    cout<<s<<endl;

    if(k<=a)s[b-1]='0',s[b-1+k]='1';
    else s[b+a-k-1]='0',s[a+b-1]='1';

    cout<<s<<endl;
	return 0;
}