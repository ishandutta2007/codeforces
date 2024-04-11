#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define i128 __int128
#define mp make_pair
#define ld long double
typedef pair<int, int> pii;
typedef priority_queue<int, vector<int>, greater<int> > small_heap;
typedef priority_queue<int> big_heap;
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
#define lb(x) (x&(-x))
#define ch(a) (int(a-'a')+1)
#define rep(i, a, b) for(int i=a;i<=b;i++)
#define mkp(a, b) make_pair(a,b)
#define flush fflush(stdout)
const double pi=acos(-1);
const int maxn=300010;
const ll Mod = 998244353;
int sum[1009],ans[1009];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        int f1=0,f2=0;
        if(b||c)
            f2=1;
        if(a||d)
            f1=1;
        if((a+b)%2)
        {
            if(f1)
                printf("Ya ");
            else
                printf("Tidak ");
            if(f2)
                printf("Ya ");
            else
                printf("Tidak ");
            printf("Tidak ");
            printf("Tidak\n");
        }
        else
        {
            printf("Tidak ");
            printf("Tidak ");
            if(f2)
                printf("Ya ");
            else
                printf("Tidak ");
            if(f1)
                printf("Ya\n");
            else
                printf("Tidak\n");
        }
    }
    return 0;
}