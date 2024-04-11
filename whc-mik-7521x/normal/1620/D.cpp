#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
typedef long long ll;
typedef long double lb;
template<typename T> inline void read(T &x)
{
    x=0;char c=getchar();bool flag=false;
    while(!isdigit(c)){if(c=='-')flag=true;c=getchar();}
    while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
    if(flag)x=-x;
}
template<typename T> inline void wrt(T x)
{
    short st[105],tp=0;
    if(x<0) putchar('-'),x=-x;
    do st[++tp]=x%10,x/=10; while(x);
    while(tp) putchar('0'|st[tp--]);
}
ll T,n,ans,p[N];
int main(){
    read(T);
    while(T--){
        read(n);
        for(ll i=1;i<=n;i++)read(p[i]);
        ans=INT_MAX;
        for(ll _1=0;_1<2;_1++)for(ll _2=0;_2<3;_2++){
            ll _3=0;
            for(ll i=1;i<=n;i++){
                ll __3=INT_MAX;
                for(ll __1=0;__1<=_1;__1++)for(ll __2=0;__2<=_2;__2++){
                    ll c=p[i]-__1-2*__2;
                    if(c>=0&&c%3==0)__3=min(__3,c/3);
                }
                _3=max(_3,__3);
            }
            // printf("%d %d %d\n",_1,_2,_3);
            ans=min(ans,_1+_2+_3);
        }
        wrt(ans);
        puts("");
    }
    return 0;
}