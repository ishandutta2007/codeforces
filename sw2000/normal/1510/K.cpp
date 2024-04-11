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
const int N = 1e5 + 10;
const int mod = 1e9 + 7;
int n,p[N],tmp[N];
bool ok()
{
    for(int i=1;i<=n*2;i++)if(i!=p[i])return 0;
    return 1;
}
void f1()
{
    for(int i=1;i<=2*n;i+=2)swap(p[i],p[i+1]);
}
void f2()
{
    for(int i=1;i<=n;i++)swap(p[i],p[i+n]);
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0);
//	freopen("1.txt","r",stdin);
    cin>>n;
    for(int i=1;i<=n*2;i++)
    {
        cin>>p[i];
        tmp[i]=p[i];
    }

    int ret=inf;
    if(ok())ret=0;
    for(int i=1;i<=n*4+5;i++)
    {
        if(i%2)f1();
        else f2();
        if(ok())ret=min(ret,i);
    }
    for(int i=1;i<=2*n;i++)p[i]=tmp[i];
    for(int i=1;i<=n*4+5;i++)
    {
        if(i%2)f2();
        else f1();
        if(ok())ret=min(ret,i);
    }
    cout<<(ret==inf?-1:ret);
	return 0;
}