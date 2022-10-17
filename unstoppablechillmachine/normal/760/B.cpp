#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define itn int
#define fro for
#define ld long double
#define ll long long
#define f first
#define sec second

struct coor
{
    int x,y;
};

struct graph
{
    int from,to,cost;
};


bool t;
queue <int> q;
set<int> st;
string s;
char ch;
vector <int> Vec;
long long a,kol,m,sum,day,ans,n,k,l,r,mid,x,y,d,b=1,xx,yy;


int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin>>n>>m>>k;
    l=1;
    r=m*2;
    y=k-1;
    x=n-k;
    while (r-l-1)
    {
        sum=0;
        mid=(r+l)/2;
        xx=x;
        yy=y;

        if (x>mid)
        {
            sum+=x-mid+1;
            xx=mid;
        }
        if (y>mid)
        {
            sum+=y-mid+1;
            yy=mid;
        }
        sum+=mid+xx*mid-(xx*(xx+1)/2)+yy*mid-(yy*(yy+1)/2);
        if (sum<=m && m-mid>=n-1)
        {
            l=mid;
            d=max(d,mid);
        }
        else r=mid;
    }

    cout<<max(d,b);

    return 0;
}