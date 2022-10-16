#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define maxn 500
#define mod 1000000007
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

int a[maxn+5];
map<int,int> M;
vi vec;
pii e[maxn+5];
int main()
{
    int n; scanf("%d",&n);
    rep(i,1,n) scanf("%d",&a[i]);
    rep(i,1,n) if(a[i]>=2) vec.pb(i);
    int tot=0;
    bool FUCK=0;

    int l=vec.size();
    rep(i,0,l-1)
    {
        int x=vec[i];
        if(i==0 || i==l-1)
        {
            if(l==1) M[x]=a[x];
            else M[x]=a[x]-1;
        }
        else if(a[x]>2) M[x]=a[x]-2;
    }
    rep(i,1,l-1) e[++tot]=mp(vec[i-1],vec[i]);
    int used1=0,used2=0;
    rep(i,1,n)
    {
        if(a[i]==1)
        {
            if(M.empty()) FUCK=1;
            else if(used1==0)
            {
                used1=1;
                e[++tot]=mp(i,vec[0]);
                if(--M[vec[0]]==0) M.erase(vec[0]);
            }
            else if(used2==0)
            {
                used2=1;
                e[++tot]=mp(i,vec[l-1]);
                if(--M[vec[l-1]]==0) M.erase(vec[l-1]);
            }
            else
            {
                int x=M.begin()->first;
                e[++tot]=mp(i,x);
                if(--M[x]==0) M.erase(x);
            }
        }
    }
    if(FUCK) printf("NO\n");
    else
    {
        assert(tot==n-1);
        printf("YES %d\n%d\n",l+used1+used2-1,n-1);
        rep(i,1,n-1) printf("%d %d\n",e[i].first,e[i].second);
    }
    return 0;
}