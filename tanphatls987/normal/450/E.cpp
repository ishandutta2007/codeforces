#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string.h>
#include <math.h>
#include <deque>
#include <vector>
using namespace std;

#define X first
#define Y second
#define MOD 1000000007
#define INPUT freopen(".inp","r",stdin)
#define OUTPUT freopen(".out","w",stdout)
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define REP(i,l,r) for(int i=l;i<r;i++)
#define FORD(i,l,r) for(int i=l;i>=r;i--)
#define REPD(i,l,r) for(int i=l;i>r;i--)
#define ENDL printf("\n")
#define inf 1000000

const int N=100001;

typedef long long ll;
typedef pair<int,int> ii;
vector <ii> a;
int n,h[N]={0},c,ans=0;
int main()
{
    cin>>n;
    int x;
    for(int i=3;i<=n/2;i+=2) if (!h[i])
    {
        c=0;
        for(int j=i;j<=n;j+=i) if (!h[j]) c++;
        //printf("%d %d\n",i,c);
        ans+=c/2;
        x=0;
        for(int j=i;j<=n;j+=i) if (!h[j])
        {
            if (c%2&&j==2*i) continue;
            h[j]=1;
            if (x==0) x=j;
            else
            {
                a.push_back(ii(x,j));
                x=0;
            }
        }
    }
    x=0;
    for(int i=2;i<=n;i+=2) if (!h[i])
    {
        if (x==0) x=i;
        else
            {
                ans++;
                a.push_back(ii(x,i));
                x=0;
            }
    }
    printf("%d\n",ans);
    REP(i,0,ans) printf("%d %d\n",a[i].X,a[i].Y);
}