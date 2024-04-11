#include<bits/stdc++.h>

//#define DEBUG
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
#define sz(c) ((int)((c).size()))
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

class mstream
{
private:
    int res=0;
    bool right=0,sign=0,space=0,zero=0;
    int width=0,precision=0,maxwidth=1e6;
    string interval="";
    const char* formstr(bool ri,bool si,bool sp,bool ze,
                        bool wi,bool pr,
                        string ty)
    {
        string f="%";
        if(ri&&right)f+="-";
        if(si&&sign)f+="+";
        if(sp&&space)f+=" ";
        if(ze&&zero)f+="0";
        if(wi)f+="*";
        if(pr)f+=".*";
        f+=ty;
        f+="%s";
        return f.c_str();
    }
public:
    operator int(){return res;}
    mstream(){}
    mstream operator()()
        {res=0;return*this;}
    mstream setright(bool n=1)
        {right=n;return*this;}
    mstream setleft(bool n=1)
        {right=!n;return*this;}
    mstream setsign(bool n=1)
        {sign=n;return*this;}
    mstream notsign(bool n=1)
        {sign=!n;return*this;}
    mstream setspace(bool n=1)
        {space=n;return*this;}
    mstream notspace(bool n=1)
        {space=!n;return*this;}
    mstream setzero(bool n=1)
        {zero=n;return*this;}
    mstream notzero(bool n=1)
        {zero=!n;return*this;}
    mstream setwidth(int n=0)
        {width=n;return*this;}
    mstream setprecision(int n=6)
        {precision=n;return*this;}
    mstream setmaxwidth(int n=1e6)
        {maxwidth=n;return*this;}
    mstream setinterval(string n=" ")
        {interval=n;return*this;}
    mstream notinterval(string n="")
        {interval=n;return*this;}
    mstream operator>>(int& x)
    {
        int r=scanf("%d",&x);
        if(r!=EOF)
            res+=r;
        return *this;
    }
    mstream operator>>(long long& x)
    {
        int r=scanf("%I64d",&x);
        if(r!=EOF)
            res+=r;
        return *this;
    }
    mstream operator>>(float& x)
    {
        int r=scanf("%f",&x);
        if(r!=EOF)
            res+=r;
        return *this;
    }
    mstream operator>>(double& x)
    {
        int r=scanf("%lf",&x);
        if(r!=EOF)
            res+=r;
        return *this;
    }
    mstream operator>>(char& x)
    {
        int r=scanf("%c",&x);
        if(r!=EOF)
            res+=r;
        return *this;
    }
    mstream operator>>(string& x)
    {
        char s[maxwidth+1];
        int r=scanf("%s",s);
        if(r!=EOF)
            x=s,res+=r;
        return *this;
    }
    mstream operator<<(int x)
    {
        int r=printf(formstr(1,1,1,1,1,0,"d"),
                     width,x,interval.c_str());
        if(r>0)
            res+=r;
        return *this;
    }
    mstream operator<<(long long x)
    {
        int r=printf(formstr(1,1,1,1,1,0,"I64d"),
                     width,x,interval.c_str());
        if(r>0)
            res+=r;
        return *this;
    }
    mstream operator<<(float x)
    {
        int r=printf(formstr(1,1,1,1,1,1,"f"),
                     width,precision,x,interval.c_str());
        if(r>0)
            res+=r;
        return *this;
    }
    mstream operator<<(double x)
    {
        int r=printf(formstr(1,1,1,1,1,1,"lf"),
                     width,precision,x,interval.c_str());
        if(r>0)
            res+=r;
        return *this;
    }
    mstream operator<<(char x)
    {
        int r=printf(formstr(1,0,0,1,1,0,"c"),
                     width,x,interval.c_str());
        if(r>0)
            res+=r;
        return *this;
    }
    mstream operator<<(string x)
    {
        int r=printf(formstr(1,0,0,1,1,1,"s"),
                     width,maxwidth,x.c_str(),interval.c_str());
        if(r>0)
            res+=r;
        return *this;
    }
};
mstream mstr=mstream();

ll f(ll a,ll b)
{
    if(a==b)
        return 0;
    if((a+3-b)%3==1)
        return 1;
    else
        return 2;
}

ll fa(ll a,ll b)
{
    return f(a,b)&1;
}

ll fb(ll a,ll b)
{
    return (f(a,b)&2)/2;
}

int main()
{
    ll k,a,b;
    mstr>>k>>a>>b;
    a--;
    b--;
    ll A[3][3];
    for0(i,3)
        for0(j,3)
            mstr>>A[i][j],A[i][j]--;
    ll B[3][3];
    for0(i,3)
        for0(j,3)
            mstr>>B[i][j],B[i][j]--;
    bool U[3][3];
    mem0(U);
    ll ka=0,kb=0,i=0;
    while(!U[a][b])
    {
        IFD( mstr<<"a="<<a<<" b="<<b<<"\n"; )
        U[a][b]=true;
        ka+=fa(a,b);
        kb+=fb(a,b);
        ll na=A[a][b],nb=B[a][b];
        a=na;
        b=nb;
        i++;
        if(i==k)
            mstr<<ka<<" "<<kb,halt;
    }
    IFD( mstr<<"k="<<k<<" "<<" ka="<<ka<<" kb="<<kb<<
               " i="<<i<<"\n"; )
    k-=i;
    i=0;
    mem0(U);
    ll ka2=0,kb2=0;
    IFD( mstr<<"k="<<k<<" "<<" ka="<<ka<<" kb="<<kb<<
               " i="<<i<<" ka2="<<ka2<<" kb2="<<kb2<<"\n"; )
    while(!U[a][b])
    {
        IFD( mstr<<"a="<<a<<" b="<<b<<"\n"; )
        U[a][b]=true;
        ka2+=fa(a,b);
        kb2+=fb(a,b);
        ll na=A[a][b],nb=B[a][b];
        a=na;
        b=nb;
        i++;
        if(i==k)
            mstr<<ka+ka2<<" "<<kb+kb2,halt;
    }
    IFD( mstr<<"k="<<k<<" "<<" ka="<<ka<<" kb="<<kb<<
               " i="<<i<<" ka2="<<ka2<<" kb2="<<kb2<<"\n"; )
    ka2*=k/i;
    kb2*=k/i;
    k%=i;
    IFD( mstr<<"k="<<k<<" "<<" ka="<<ka<<" kb="<<kb<<
               " i="<<i<<" ka2="<<ka2<<" kb2="<<kb2<<"\n"; )
    if(k==0)
        mstr<<ka+ka2<<" "<<kb+kb2,halt;
    i=0;
    while(true)
    {
        IFD( mstr<<"a="<<a<<" b="<<b<<"\n"; )
        ka2+=fa(a,b);
        kb2+=fb(a,b);
        ll na=A[a][b],nb=B[a][b];
        a=na;
        b=nb;
        i++;
        if(i==k)
            mstr<<ka+ka2<<" "<<kb+kb2,halt;
    }
}