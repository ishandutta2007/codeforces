#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define maxn 100
#define mod 1000000007
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

int a[maxn+5];

int main()
{
    int n,k; scanf("%d%d",&n,&k);
    rep(i,1,n)
    {
        int x; scanf("%d",&x);
        a[x]++;
    }
    int cnt=0,M=0;
    rep(i,1,100) if(a[i]) M=max(M,a[i]),cnt++;
    int s=(M+k-1)/k;
    printf("%d\n",s*k*cnt-n);
    return 0;
}