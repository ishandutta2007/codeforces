#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 1000
#define mod 1000000007
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

struct rec
{
    int x1,y1,x2,y2;
}a[maxn+5];

bool cmpx(rec A,rec B) {return A.x1<B.x1;}
bool cmpy(rec A,rec B) {return A.y1<B.y1;}

bool check(int l,int r)
{
    if(l==r) return 1;
    sort(a+l,a+r+1,cmpx);
    int mx=a[l].x2;
    rep(i,l+1,r)
    {
        if(mx<=a[i].x1) return check(l,i-1) && check(i,r);
        mx=max(mx,a[i].x2);
    }
    sort(a+l,a+r+1,cmpy);
    mx=a[l].y2;
    rep(i,l+1,r)
    {
        if(mx<=a[i].y1) return check(l,i-1) && check(i,r);
        mx=max(mx,a[i].y2);
    }
    return 0;
}

int main()
{
    int n; scanf("%d",&n);
    rep(i,1,n) scanf("%d%d%d%d",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2);
    if(check(1,n)) puts("YES");
    else puts("NO");
    return 0;
}