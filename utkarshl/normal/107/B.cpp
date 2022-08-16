#include <sstream>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define INF                  (1<<30)
#define LINF                 ((long long)1<<60)
#define PI                   2*acos(0)
#define eps                  1e-7
#define two(x)               (1<<x)
#define twoL(x)              ((long long)1<<x)

#define FOR(i,a,b)           for(i=(a);i<(b);i++)
#define FORD(i,a,b)          for(i=(a);i>(b);i--)
#define REP(i,n)             for(i=0;i<(n);i++)
#define REV(i,n)             for(i=(n-1);i>=0;i--)
#define Sort(s)              sort(s.begin(),s.end())
#define ASort(s,n)           sort(&s[0],&s[n])
#define Reverse(s)           reverse(s.begin(),s.end())
#define Mem(A,c)             memset(A,c,sizeof(A))
#define Split(str)           {vs.clear();istringstream A(str);while(A>>(str))vs.push_back(str);}
#define CLR(s)               s.clear()
#define SZ(s)                s.size()
#define pb                   push_back
#define mp                   make_pair
#define fs                   first
#define sc                   second

#define isBetn(x,a,b)        (x>=a && x<=b)
#define isIntSect(a,b,c,d)   ((a>=c && a<=d) || (b>=c && b<=d) || (c>=a && d<=b))

typedef long long            ll;
typedef pair<int,int>        pii;
typedef pair<string,int>     psi;
typedef pair<string,string>  pss;
typedef vector<int>          vi;
typedef vector<string>       vs;
typedef map<int,int>         mii;
typedef map<string,int>      msi;
typedef map<char,int>        mci;

//int dx[]={1,-1,0,0},dy[]={0,0,1,-1}; // 4-direction delta
//int dc[]={0,1,0,-1,1,1,-1,-1},dr[]={1,0,-1,0,1,-1,-1,1}; // 8-direction delta
//int dk[]={1,2,2,1,-1,-2,-2,-1},dl[]={2,1,-1,-2,-2,-1,1,2}; // Knight's move

int main()
{
    int n,m,h,a[1002];
    int i,sum;

    cin >> n >> m >> h ;

    sum=0;
    REP(i,m)
    {
        cin >> a[i];
        sum+=a[i];
    }

    if(sum<n)
    {
        printf("%lf\n",-1.0);
        return 0;
    }

    double ans=1.0L;
    REP(i,n-1)
    {
        ans*=(double)(sum-a[h-1]-i);
        ans/=(double)(sum-1-i);
    }

    printf("%.8lf\n",1.0-(double)ans);

    return 0;
}