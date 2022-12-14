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
double solve()
{
    int n;scanf("%d",&n);
    vector<double>a,b;
    for(int i=0;i<n*2;i++)
    {
        double x,y;
        scanf("%lf%lf",&x,&y);
        if(x==0)a.push_back(abs(y));
        else b.push_back(abs(x));
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    double ans=0;
    for(int i=0;i<n;i++)
    {
        ans+=sqrt(a[i]*a[i]+b[i]*b[i]);
    }
    return ans;
}
int main()
{
//	ios::sync_with_stdio(0),cin.tie(0);
//	freopen("1.txt","r",stdin);
	int _;cin>>_;
	while(_--)
    {
        cout<<fixed<<setprecision(15)<<solve()<<endl;
    }
	return 0;
}