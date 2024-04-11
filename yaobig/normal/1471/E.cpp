#include "bits/stdc++.h"
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 100000
#define mod 1000000007
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

int ask(int p)
{
    printf("? %d\n",p+1); fflush(stdout);
    int x; scanf("%d",&x);
    return x;
}

void output(int p)
{
    printf("! %d\n",p+1);
    fflush(stdout); 
    exit(0);
}
int n,k; 
int lb(int l,int r)
{
    while(l<r)
    {
        int mid=(l+r)>>1;
        if(ask(mid%n)>k) r=mid;
        else l=mid+1;
    }
    return r-1;
}

int main()
{
    scanf("%d%d",&n,&k);
    if(n<=450)
    {
        rep(i,1,n) ask(0);
        vi A(n,0);
        rep(i,0,n-1) A[i]=ask(i);
        rep(i,0,n-1) if(A[i]==k && A[(i+1)%n]>k) output(i);
    }
    else
    {
        int sq=200;
        rep(i,1,sq) ask(0);
        vi A(n,0);
        int last=0;
        rep(i,0,n-1) if(i%sq==0) A[i]=ask(i),last=i;
        int pos=-1,pre=-1;
        rep(i,0,n-1) if(A[i]>k)
        {
            if(i==0 && A[last]<=k) {pos=i; pre=last; break;}
            if(i>=1 && A[i-sq]<=k) {pos=i; pre=i-sq; break;}
        }
        int res=lb(pre,pos<pre?pos+n:pos);
        output((res+n)%n);
    }
    return 0;
}