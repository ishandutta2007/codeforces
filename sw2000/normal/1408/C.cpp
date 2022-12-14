#include <bits/stdc++.h>
#define x first
#define y second
#define mid (l+r>>1)
#define lo (o<<1)
#define ro (o<<1|1)
using namespace std;
typedef long long ll;
typedef vector<int>vi;
typedef pair<int,int>pii;
struct tri{int x,y,z;};
const int inf=0x3f3f3f3f;
const ll linf=0x3f3f3f3f3f3f3f3f;
const int N=1e5+10;
const ll mod=1e9+7;
const double PI=acos(0)*2;
double arr[N];
double solve()
{
    double ret=0;
    int n;
    double m;
    cin>>n>>m;
    int l=0,r=n-1;
    for(int i=0;i<n;i++)cin>>arr[i];
    double vl=1,vr=1,dl=0,dr=m;
    while(l<=r)
    {
        double tl=(arr[l]-dl)/vl;
        double tr=(dr-arr[r])/vr;
        if(tl<tr)
        {
            dl=arr[l];
            l++;
            vl++;
            dr-=tl*vr;
            ret+=tl;
        }
        else
        {
            dr=arr[r];
            r--;
            vr++;
            dl+=tr*vl;
            ret+=tr;
        }
    }
    ret+=(dr-dl)/(vl+vr);
    return ret;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
//    freopen("in.txt","r",stdin);
    int _;cin>>_;
    while(_--)
        cout<<fixed<<setprecision(10)<<solve()<<endl;
    return 0;
}