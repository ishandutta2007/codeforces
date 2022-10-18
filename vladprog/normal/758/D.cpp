#include<bits/stdc++.h>

//#define DEBUG

#ifdef DEBUG
    #define IFD(X) X
#else
    #define IFD(X)
#endif // DEBUG
#define ll long long

using namespace std;

int main()
{
    int n;
    char c[61];
    scanf("%d",&n);
    itoa(n,c,10);
    string s=c;
    int d=s.length();
    if(d>9)d=9;
    IFD(printf("d=%d\n",d);)
    scanf("%s",c);
    s=c;
    ll ans=0,p=1;
    for(int i=0;!s.empty();i++)
    {
        int t=min(d,(int)s.length());
        int add=atoi(s.substr(s.length()-t).c_str());
        IFD(printf("i=%d t=%d add=%I64d\n",i,t,add);)
        if(add>=n)
        {
            t--;
            add=atoi(s.substr(s.length()-t).c_str());
            IFD(printf("    add>n : t=%d add=%I64d\n",t,add);)
        }
        ans+=p*add;
        itoa(add,c,10);
        string ts=c;
        t=ts.length();
        s=s.substr(0,s.length()-t);
        p*=n;
        IFD(printf("    t=%d ans=%I64d p=%I64d\n",t,ans,p);)
    }
    printf("%I64d",ans);
}