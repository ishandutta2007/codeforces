#pragma GCC optimize("O3")
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>

#define DEBUG
#ifdef DEBUG
    #define IFD(...) __VA_ARGS__
    #define IFN(...)
    #define L cout<<__LINE__<<"\n";
    #define PRINT(...) __VA_ARGS__ cout<<__LINE__<" : "<<#__VA_ARGS__<<"\n"
    #define PRT(x) cout<<__LINE__<<" : "<<#x<<" = "<<x<<"\n"
#else // DEBUG
    #define IFD(...)
    #define IFN(...) __VA_ARGS__
    #define L
    #define PRINT(...) __VA_ARGS__
    #define PRT(x)
#endif // DEBUG

#define it iterator
#define rit reverse_iterator
#define mp make_pair
#define mems(a,b) memset(a,b,sizeof(a))
#define mem0(a) mems(a,0)
#define mem1(a) mems(a,1)
#define mem255(a) mems(a,255)
#define halt exit(0)
#define all(c) (c).begin() , (c).end()
#define sz(c) ((long long)((c).size()))
#define phb push_back
#define ppb pop_back
#define phf push_front
#define ppf pop_front
#define fort0(i,a,b) for(ll i=a,i##_TO=b;i<i##_TO;i++)
#define for0(i,n) fort0(i,0,n)
#define fort1(i,a,b) for(ll i=a,i##_TO=b;i<=i##_TO;i++)
#define for1(i,n) fort1(i,1,n)
#define ford(i,a,b) for(ll i=a,i##_TO=b;i>=i##_TO;i--)

using namespace __gnu_pbds;
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template
<
    class key,
    class val=null_type,
    class comp=less<key>
>
using ord_set=tree
<
    key,
    val,
    comp,
    rb_tree_tag,
    tree_order_statistics_node_update
>;

const int N = 1e6;
int lp[N+1];
    vector<int> pr;

void prime()
{
    for (int i=2; i<=N; ++i)
    {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back (i);
        }
        for (int j=0; j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]<=N; ++j)
            lp[i * pr[j]] = pr[j];
    }
}

int main()
{
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);


    prime();


    int x2;
    scanf("%d",&x2);
    int t=x2,ans=x2;
    for(;;t/=lp[t])
    {
        int p=lp[t];
        if(p==0)
            break;
//        printf("%d\n",p);
        for(int x1=max(x2-p+1,p);x1<=x2;x1++)
        {
            if(x1==1)
                continue;
            int t1=x1;
            while(true)
            {
                ans=min(ans,max(x1-lp[t1]+1,lp[t1]));
//                printf("%d -> %d -> %d\n",x1,lp[t1],max(x1-lp[t1]+1,lp[t1]));
                if(t1==lp[t1])
                    break;
                t1/=lp[t1];
            }
        }
        if(x2==lp[x2])
            break;
    }
    printf("%d",ans);
}