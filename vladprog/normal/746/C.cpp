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
#define read(...) RW::READ(__VA_ARGS__,0)
#define write(...) RW::WRITE("",__VA_ARGS__,0,"")
#define writeln(...) RW::WRITE("",__VA_ARGS__,0,"\n")
#define print(...) RW::WRITE(" ",__VA_ARGS__,0,"")
#define println(...) RW::WRITE(" ",__VA_ARGS__,0,"\n")

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

struct RW
{
    static int READ(int* f, ...)
    {
        va_list ap;
        va_start(ap, f);
        int res=0;
        while(f!=0)
        {
            if(scanf("%d",f)==EOF)
                return res?res:EOF;
            res++;
            f=va_arg(ap,int*);
        }
        va_end(ap);
        return res;
    }

    static int READ(ll* f, ...)
    {
        va_list ap;
        va_start(ap, f);
        int res=0;
        while(f!=0)
        {
            if(scanf("%I64d",f)==EOF)
                return res?res:EOF;
            res++;
            f=va_arg(ap,ll*);
        }
        va_end(ap);
        return res;
    }

    static int READ(char* f, ...)
    {
        va_list ap;
        va_start(ap, f);
        int res=0;
        while(f!=0)
        {
            if(scanf("%c",f)==EOF)
                return res?res:EOF;
            res++;
            f=va_arg(ap,char*);
        }
        va_end(ap);
        return res;
    }

    static int READ(string* f, ...)
    {
        va_list ap;
        va_start(ap, f);
        int res=0;
        const int SIZE=1e6;
        char c[SIZE];
        while(f!=0)
        {
            if(scanf("%s",c)==EOF)
                return res?res:EOF;
            res++;
            *f=c;
            f=va_arg(ap,string*);
        }
        va_end(ap);
        return res;
    }

    static int WRITE(string s, int* f, ...)
    {
        va_list ap;
        va_start(ap, f);
        int res=0;
        while(f!=0)
        {
            res+=printf("%d%s",*f,s.c_str());
            f=va_arg(ap,int*);
        }
        char* e=va_arg(ap,char*);
        res+=printf("%s",e);
        va_end(ap);
        return res;
    }

    static int WRITE(string s, ll* f, ...)
    {
        va_list ap;
        va_start(ap, f);
        int res=0;
        while(f!=0)
        {
            res+=printf("%I64d%s",*f,s.c_str());
            f=va_arg(ap,ll*);
        }
        char* e=va_arg(ap,char*);
        res+=printf("%s",e);
        va_end(ap);
        return res;
    }

    static int WRITE(string s, char* f, ...)
    {
        va_list ap;
        va_start(ap, f);
        int res=0;
        while(f!=0)
        {
            res+=printf("%c%s",*f,s.c_str());
            f=va_arg(ap,char*);
        }
        char* e=va_arg(ap,char*);
        res+=printf("%s",e);
        va_end(ap);
        return res;
    }

    static int WRITE(string s, string* f, ...)
    {
        va_list ap;
        va_start(ap, f);
        int res=0;
        while(f!=0)
        {
            res+=printf("%s%s",f->c_str(),s.c_str());
            f=va_arg(ap,string*);
        }
        char* e=va_arg(ap,char*);
        res+=printf("%s",e);
        va_end(ap);
        return res;
    }
};

int main()
{
    int s,x1,x2,t1,t2,p,d;
    read(&s,&x1,&x2,&t1,&t2,&p,&d);
    if(x1>x2)
    {
        x1=s-x1;
        x2=s-x2;
        p=s-p;
        d=-d;
    }
    int ans1=(x2-x1)*t2,ans2;
    if(d==-1)
        ans2=p+x2;
    else if(p>x1)
        ans2=s-p+s+x2;
    else
        ans2=x2-p;
    ans2*=t1;
    int ans=min(ans1,ans2);
    writeln(&ans);
}