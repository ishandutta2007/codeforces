#include<bits/stdc++.h>

//#define DEBUG
#ifdef DEBUG
    #define IFD(...) __VA_ARGS__
    #define IFN(...)
    #define L cout<<__LINE__<<"\n";
    #define PRINT(...) __VA_ARGS__ cout<<#__VA_ARGS__<<"\n"
    #define PRT(x) cout<<#x<<"="<<x<<"\n"
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

const int nap[4][2]={1,0,-1,0,0,1,0,-1};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin>>n>>m;
    string s[n+2];
    s[0]=s[n+1]=string(m+2,'#');
    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
        s[i]='#'+s[i]+'#';
    }
    string t;
    cin>>t;
    int sx,sy;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(s[i][j]=='S')
                sx=i,sy=j,s[i][j]='.';
    int k=0;
    int d[4];
    #define D(x) for(d[x]=0;d[x]<4;d[x]++)
    D(0)D(1)D(2)D(3)
    {
        if(d[0]==d[1])continue;
        if(d[0]==d[2])continue;
        if(d[0]==d[3])continue;
        if(d[1]==d[2])continue;
        if(d[1]==d[3])continue;
        if(d[2]==d[3])continue;
        int x=sx,y=sy;
        IFD(cout<<"!";)
        for(char c:t)
        {
            IFD(cout<<c;)
            x+=nap[d[c-'0']][0];
            y+=nap[d[c-'0']][1];
            if(s[x][y]!='.')
                break;
        }
        IFD(cout<<"\n";)
        if(s[x][y]=='E')
            k++;
    }
    cout<<k;
}