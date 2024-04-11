#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define maxn 100000
#define mod 1000000007
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

int a[maxn+5];

int main()
{
    int n; scanf("%d",&n);
    rep(i,1,n) scanf("%d",&a[i]);
    int sum=0;
    rep(i,1,n) sum+=a[i];
    sum*=2;
    int k=sum/n+1;
    rep(i,1,n) k=max(k,a[i]);
    printf("%d\n",k);
    return 0;
}