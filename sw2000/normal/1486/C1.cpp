#include<bits/stdc++.h>
#define fi first
#define se second
#define lo (o<<1)
#define ro (o<<1|1)
#define mid (l+r>>1)
using namespace std;
typedef long long ll;
typedef vector<int>vi;
typedef pair<int, int>pii;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const int N = 2e5 + 10;
const int mod = 1e9 + 7;
vi v{0};
int main()
{
	int l=1,r,n,p;
	cin>>n;
	cout<<"? 1 "<<n<<endl;
	cin>>p;
	for(int i=1;i<=n;i++)if(i!=p)
    {
        v.push_back(i);
    }
    r=n-1;
	while(1)
    {
        if(l==r)
        {
            cout<<"! "<<v[l]<<endl;
            return 0;
        }
        int a;
        if(p<=v[mid])
        {
            cout<<"? 1 "<<v[mid]<<endl;
            cin>>a;
            if(a==p)
            {
                r=mid;
            }
            else
            {
                l=mid+1;
            }
        }
        else
        {
            cout<<"? "<<min(p,v[mid+1])<<' '<<n<<endl;
            cin>>a;
            if(a==p)
            {
                l=mid+1;
            }
            else
            {
                r=mid;
            }
        }
    }
	return 0;
}