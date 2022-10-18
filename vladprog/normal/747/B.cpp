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
#define forc(i,c) typedef typeof(c) _T_##c##_;\
                  for(_T_##c##_::it i=c.begin();i!=c.end();i++)
#define forr(i,c) typedef typeof(c) _T_##c##_;\
                  for(_T_##c##_::rit i=c.rbegin();i!=c.rend();i++)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int main()
{
    int n;
    scanf("%d",&n);
    if(n%4!=0)
        printf("==="),exit(0);
    char s[n+1];
    scanf("%s",s);
    int a=0,c=0,g=0,t=0;
    for0(i,n)
        switch(s[i])
        {
        case 'A':
            a++;
            break;
        case 'C':
            c++;
            break;
        case 'G':
            g++;
            break;
        case 'T':
            t++;
            break;
        }
    int m=n/4;
    if(a>m||c>m||g>m||t>m)
        printf("==="),exit(0);
    a=m-a;
    c=m-c;
    g=m-g;
    t=m-t;
    for0(i,n)
        if(s[i]=='?')
            if(a>0)
                s[i]='A',a--;
            else if(c>0)
                s[i]='C',c--;
            else if(g>0)
                s[i]='G',g--;
            else if(t>0)
                s[i]='T',t--;
    printf("%s",s);
}