#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 200000
#define mod 1000000007
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

int a[maxn+5];
ll S[maxn+5];
db ans;
int pos,ansl;
int main()
{
    int n; scanf("%d",&n);
    rep(i,1,n) scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    rep(i,1,n) S[i]=S[i-1]+a[i];
    ans=-1;
    rep(i,1,n)
    {
        int l=0,r=min(i-1,n-i);
        while(l<r)
        {
            int mid=(l+r)>>1;
            db mean1=(a[i]+S[i-1]-S[i-1-mid-1]+S[n]-S[n-mid-1])/(db)(mid*2+3);
            db mean0=(a[i]+S[i-1]-S[i-1-mid]+S[n]-S[n-mid])/(db)(mid*2+1);
            if(mean1<mean0) r=mid;
            else l=mid+1;
        }
        db mean=(a[i]+S[i-1]-S[i-1-l]+S[n]-S[n-l])/(db)(l*2+1);
        if(mean-a[i]>ans)
        {
            ans=mean-a[i];
            pos=i;
            ansl=l;
        }
    }
    int N=ansl*2+1;
    printf("%d\n",N);
    rep(i,1,ansl) printf("%d ",a[pos-i]);
    rep(i,1,ansl) printf("%d ",a[n+1-i]);
    printf("%d\n",a[pos]);
    return 0;
}