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
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n-1; i++)
    {
        printf("? %d %d\n",i,n);
        fflush(stdout);
        scanf("%d",&sum[i]);
        if(i>1){
            ans[i-1]=sum[i-1]-sum[i];
        }
    }
    printf("? %d %d\n",n-2,n-1);
    fflush(stdout);
    int val;scanf("%d",&val);
    ans[n-1]=val-ans[n-2];
    ans[n]=sum[n-1]-ans[n-1];
    printf("! ");
    for(int i=1;i<=n;i++){
        printf("%d ",ans[i]);
    }
    return 0;
}