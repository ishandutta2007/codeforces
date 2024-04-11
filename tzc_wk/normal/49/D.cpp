#include <bits/stdc++.h>
#define Rep(i,a,b) for(register int i=(a),i##end=(b);i<=i##end;++i)
using namespace std;
const int MAXN=1007;
template<typename T>inline void read(T &x)
{
    T s=0,f=1;char k=getchar();
    while(!isdigit(k)&&(k^'-'))k=getchar();
    if(!isdigit(k)){f=-1;k=getchar();}
    while(isdigit(k)){s=s*10+(k^48);k=getchar();}
    x=s*f;
}
static int n,ans;
bitset<MAXN>a;
string s;
void work()
{
    read(n);
    cin>>s;
    bitset<MAXN>w(s);
    Rep(i,1,n/2)a.set(2*i-1);
    ans=(w^a).count();
    cout<<min(ans,n-ans);
}
int main()
{
    work();
    return 0;
}