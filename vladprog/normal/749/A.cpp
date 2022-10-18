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
#define fort0(i,a,b) for(int i=a;i<b;i++)
#define for0(i,n) fort0(i,0,n)
#define fort1(i,a,b) for(int i=0;i<=n;i++)
#define for1(i,n) fort1(i,1,n)
#define fort(i,a,b) for(int i=0;i<=n;i++)
#define forc(i,c) typedef typeof(c) t_##c;\
                  for(t_##c::it i=c.begin();i!=c.end();i++)
#define forr(i,c) typedef typeof(c) t_##c;\
                  for(t_##c::rit i=c.rbegin();i!=c.rend();i++)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int main()
{
    int n;
    scanf("%d",&n);
    int k=n/2;
    printf("%d\n",k);
    for0(i,k-1)
        printf("2 "),n-=2;
    printf("%d\n",n);
}