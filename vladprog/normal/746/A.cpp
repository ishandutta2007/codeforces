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
#define read(...) READ(__VA_ARGS__,0)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int READ(int* f, ...)
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

int READ(ll* f, ...)
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

int READ(char* f, ...)
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

int READ(string* f, ...)
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

typedef set<int> si;
typedef pair<int,si> task;
typedef set<task> st;

int main()
{
    int a,b,c;
    read(&a,&b,&c);
    b/=2;
    c/=4;
    printf("%d",min(a,min(b,c))*7);
}