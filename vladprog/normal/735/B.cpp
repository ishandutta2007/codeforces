#include<bits/stdc++.h>

//#define DEBUG
#ifdef DEBUG
    #define IFD(...) __VA_ARGS__
#else
    #define IFD(...)
#endif // DEBUG

#define it iterator
#define rit reverse_iterator
#define mp make_pair
#define all(c) (c).begin() , (c).end()
#define fort0(i,a,b) for(ll i=a,i##_TO=b;i<i##_TO;i++)
#define for0(i,n) fort0(i,0,n)
#define fort1(i,a,b) for(ll i=a,i##_TO=b;i<=i##_TO;i++)
#define for1(i,n) fort1(i,1,n)
#define ford(i,a,b) for(ll i=a,i##_TO=b;i>=i##_TO;i--)
#define forc(i,c) typedef typeof(c) _T_##i##_;\
                  for(_T_##i##_::it _N_##i##_=c.begin(),i=(_N_##i##_==c.end())?_N_##i##_:(_N_##i##_++);\
                      i!=c.end();\
                      i=(_N_##i##_==c.end())?_N_##i##_:(_N_##i##_++))
#define forr(i,c) typedef typeof(c) _T_##i##_;\
                  for(_T_##i##_::rit _N_##i##_=c.rbegin(),i=(_N_##i##_==c.rend())?_N_##i##_:(_N_##i##_++);\
                      i!=c.rend();\
                      i=(_N_##i##_==c.rend())?_N_##i##_:(_N_##i##_++))

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

class mstream
{
private:
    int res;
    string p;
public:
    operator int(){return res;}
    mstream(const char* np="")
    {
        res=0;
        p=np;
    }
    mstream operator()(const char* np="")
    {
        res=0;
        p=np;
        return *this;
    }
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
        char s[1000000];
        int r=scanf("%s",s);
        if(r!=EOF)
            x=s,res+=r;
        return *this;
    }
    mstream operator<<(int x)
    {
        int r=printf("%d%s",x,p.c_str());
        if(r>0)
            res+=r;
        return *this;
    }
    mstream operator<<(long long x)
    {
        int r=printf("%I64d%s",x,p.c_str());
        if(r>0)
            res+=r;
        return *this;
    }
    mstream operator<<(float x)
    {
        int r=printf("%f",x,p.c_str());
        if(r>0)
            res+=r;
        return *this;
    }
    mstream operator<<(double x)
    {
        int r=printf("%lf",x,p.c_str());
        if(r>0)
            res+=r;
        return *this;
    }
    mstream operator<<(char x)
    {
        int r=printf("%c%s",x,p.c_str());
        if(r>0)
            res+=r;
        return *this;
    }
    mstream operator<<(string x)
    {
        int r=printf("%s%s",x.c_str(),p.c_str());
        if(r>0)
            res+=r;
        return *this;
    }
};
mstream mstr=mstream();

int main()
{
    int n,n1,n2;
    mstr>>n>>n1>>n2;
    if(n1>n2)
        swap(n1,n2);
    int a[n];
    for0(i,n)
        mstr>>a[i];
    sort(a,a+n,greater<int>());
    double ans=0;
    for0(i,n1)
        ans+=(double)a[i]/n1 IFD( ,mstr<<a[i]<<" " ) ;
    IFD( mstr<<"\n"; )
    fort0(i,n1,n1+n2)
        ans+=(double)a[i]/n2 IFD( ,mstr<<a[i]<<" " ) ;
    IFD( mstr<<"\n"; )
    mstr<<ans;
}