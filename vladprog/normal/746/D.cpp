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
#define fort0(i,a,b) for(int i=a,i##_to=b;i<i##_to;i++)
#define for0(i,n) fort0(i,0,n)
#define fort1(i,a,b) for(int i=a,i##_to=b;i<=i##_to;i++)
#define for1(i,n) fort1(i,1,n)
#define ford(i,a,b) for(int i=a,i##_to=b;i>=i##_to;i--)
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
    int n,k,a,b;
    mstr>>n>>k>>a>>b;
    char ca='G',cb='B';
    if(a<b)
        swap(a,b),swap(ca,cb);
    int kp=a/(b+1),kl=b+1-(a-kp*(b+1));
    IFD( mstr(" ")<<"kp="<<kp<<"kl="<<kl; mstr()<<'\n'; )
    if(kp>k||(kp==k&&kl<b+1))
        mstr<<"NO";
    else
    {
        int v=0;
        for0(i,kl)
        {
            for0(j,kp)
                mstr<<ca;
            v++;
            if(v<b+1)
                mstr<<cb;
        }
        for0(i,b+1-kl)
        {
            for0(j,kp+1)
                mstr<<ca;
            v++;
            if(v<b+1)
                mstr<<cb;
        }
    }
}