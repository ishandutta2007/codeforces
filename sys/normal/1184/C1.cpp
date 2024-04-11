#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<queue>
#include<map>
#include<bitset>
#include<stack>
#include<set>
#include<vector>
#include <time.h>
#include<string.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;

const int maxn = 1e5+5;
const int Mod=1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const double e=exp(1);
const db PI = acos(-1);
const db ERR = 1e-10;

#define Se second
#define Fi first
#define pb push_back
#define ok cout<<"OK"<<endl
#define dbg(x) cout<<#x<<" = "<< (x)<< endl
#define dbg2(x1,x2) cout<<#x1<<" = "<<x1<<" "<<#x2<<" = "<<x2<<endl
#define dbg3(x1,x2,x3) cout<<#x1<<" = "<<x1<<" "<<#x2<<" = "<<x2<<" "<<#x3<<" = "<<x3<<endl
struct P
{
    int x,y;
}p[maxn];
int n;
int main()
{
    //ios::sync_with_stdio(false);
    //freopen("a.txt","r",stdin);
    //freopen("b.txt","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=4*n+1;i++) scanf("%d %d",&p[i].x,&p[i].y);
    for(int i=0;i<=50;i++)
    {
        for(int j=i+1;j<=50;j++)
        {
            for(int k=0;k<=50;k++)
            {
                for(int l=k+1;l<=50;l++)
                {
                    int no = 0;
                    int flag = -1;
                    int a=0,b=0,c=0,d=0;
                    for(int t=1;t<=4*n+1;t++)
                    {
                        if(p[t].x==i&&p[t].y>=k&&p[t].y<=l) a++;
                        else if(p[t].x==j&&p[t].y>=k&&p[t].y<=l) b++;
                        else if(p[t].y==k&&p[t].x>=i&&p[t].x<=j) c++;
                        else if(p[t].y==l&&p[t].x>=i&&p[t].x<=j) d++;
                        else
                        {
                            flag=t;
                            no++;
                        }
                    }
                    if(no==1)
                    {
                        printf("%d %d\n",p[flag].x,p[flag].y);
                        return 0;
                    }
                }
            }
        }
    }
    //cout << "time: " << (long long)clock() * 1000 / CLOCKS_PER_SEC << " ms" << endl;
    return 0;
}