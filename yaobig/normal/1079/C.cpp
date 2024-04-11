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

int a[maxn+5],b[maxn+5];
int n;
bool solve(int st)
{
    b[1]=st;
    rep(i,2,n)
    {
        if(a[i]>a[i-1])
        {
            if(i==n || a[i+1]>=a[i]) b[i]=b[i-1]+1;
            else b[i]=max(5,b[i-1]+1);
        }
        else if(a[i]<a[i-1])
        {
            if(i==n || a[i+1]<=a[i]) b[i]=b[i-1]-1;
            else b[i]=min(1,b[i-1]-1);
        }
        else
        {
            if(i==n)
            {
                if(b[i-1]==3) b[i]=4;
                else b[i]=3;
            }
            else if(a[i+1]>a[i])
            {
                if(b[i-1]==1) b[i]=2;
                else b[i]=1;
            }
            else if(a[i+1]<a[i])
            {
                if(b[i-1]==5) b[i]=4;
                else b[i]=5;
            }
            else
            {
                if(b[i-1]==3) b[i]=4;
                else b[i]=3;
            }
        }

        if(b[i]<1 || b[i]>5) return 0;
    }
    return 1;
}

int main()
{
    scanf("%d",&n);
    rep(i,1,n) scanf("%d",&a[i]);
    int f=0;
    rep(i,1,5)
    {
        if(solve(i))
        {
            f=1;
            break;
        }
    }
    if(f) rep(i,1,n) printf("%d%c",b[i]," \n"[i==n]);
    else printf("%d\n",-1);
    return 0;
}