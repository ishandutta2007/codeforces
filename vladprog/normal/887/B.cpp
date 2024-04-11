#include<bits/stdc++.h>

#define DEBUG
#ifdef DEBUG
    #define IFD(...) __VA_ARGS__
    #define IFN(...)
    #define L mstr<<__LINE__<<"\n";
    #define PRINT(...) __VA_ARGS__ mstr<<#__VA_ARGS__<<"\n"
    #define PRT(x) mstr<<#x<<"="<<x<<"\n"
#else
    #define IFD(...)
    #define IFN(...) __VA_ARGS__
    #define L
    #define PRINT(...) __VA_ARGS__
    #define PRT(x)
#endif // DEBUG

#define it iterator
#define rit reverse_iterator
#define mp make_pair
#define mems(a,b) memset(a,b,sizeof(a))
#define mem0(a) mems(a,0)
#define mem1(a) mems(a,1)
#define mem255(a) mems(a,255)
#define halt exit(0)
#define all(c) (c).begin() , (c).end()
#define sz(c) ((long long)((c).size()))
#define phb push_back
#define ppb pop_back
#define phf push_front
#define ppf pop_front
#define fort0(i,a,b) for(ll i=a,i##_TO=b;i<i##_TO;i++)
#define for0(i,n) fort0(i,0,n)
#define fort1(i,a,b) for(ll i=a,i##_TO=b;i<=i##_TO;i++)
#define for1(i,n) fort1(i,1,n)
#define ford(i,a,b) for(ll i=a,i##_TO=b;i>=i##_TO;i--)
#define forc(i,c) for(auto _N_##i##_=c.begin(),i=(_N_##i##_==c.end())?_N_##i##_:(_N_##i##_++);\
                      i!=c.end();\
                      i=(_N_##i##_==c.end())?_N_##i##_:(_N_##i##_++))
#define forr(i,c) for(auto _N_##i##_=c.rbegin(),i=(_N_##i##_==c.rend())?_N_##i##_:(_N_##i##_++);\
                      i!=c.rend();\
                      i=(_N_##i##_==c.rend())?_N_##i##_:(_N_##i##_++))

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    bool b[3][10]={{false}};
    for0(i,n)
        for0(j,6)
        {
            int t;
            cin>>t;
            b[i][t]=true;
        }
    fort1(i,1,9)
    {
        if(b[0][i])continue;
        if(b[1][i])continue;
        if(b[2][i])continue;
        cout<<i-1,halt;
    }
    fort1(i,10,99)
    {
        int x=i/10,y=i%10;
        if(b[0][x]&&b[1][y])continue;
        if(b[0][x]&&b[2][y])continue;
        if(b[1][x]&&b[0][y])continue;
        if(b[1][x]&&b[2][y])continue;
        if(b[2][x]&&b[0][y])continue;
        if(b[2][x]&&b[1][y])continue;
        cout<<i-1,halt;
    }
    fort1(i,100,999)
    {
        int x=i/100,y=i%10,z=i/10%10;
        if(b[0][x]&&b[1][y]&&b[2][z])continue;
        if(b[0][x]&&b[2][y]&&b[1][z])continue;
        if(b[1][x]&&b[0][y]&&b[2][z])continue;
        if(b[1][x]&&b[2][y]&&b[0][z])continue;
        if(b[2][x]&&b[0][y]&&b[1][z])continue;
        if(b[2][x]&&b[1][y]&&b[0][z])continue;
        cout<<i-1,halt;
    }
    cout<<999;
}