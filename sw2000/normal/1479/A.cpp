#include<bits/stdc++.h>
#define fi first
#define se second
#define lo (o<<1)
#define ro (o<<1|1)
#define mid (l+r>>1)
//#define endl '\n'
using namespace std;
typedef long long ll;
typedef vector<int>vi;
typedef pair<int, int>pii;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const int N = 2e5 + 10;
const int mod = 1e9 + 7;
pii a,b,c;
int n;
int main()
{
    cin>>n;
    a={0,inf},c={n+1,inf};
    b={(n+1)/2,0};
    cout<<"? "<<(n+1)/2<<endl;
    cin>>b.se;
    while(a.fi!=b.fi-1||b.fi!=c.fi-1)
    {
        int l1=b.fi-a.fi,l2=c.fi-b.fi;
        if(l1>l2)
        {
            pii t={a.fi+l1/2,0};
            cout<<"? "<<t.fi<<endl;
            cin>>t.se;
            if(t.se>b.se)a=t;
            else c=b,b=t;
        }
        else
        {
            pii t={b.fi+l2/2,0};
            cout<<"? "<<t.fi<<endl;
            cin>>t.se;
            if(t.se>b.se)c=t;
            else a=b,b=t;
        }
    }
    cout<<"! "<<b.fi<<endl;
	return 0;
}