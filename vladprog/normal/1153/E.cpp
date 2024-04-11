#pragma GCC optimize("O3")
#include <bits/stdc++.h>

typedef long long ll;
#define int ll
typedef long double ld;

using namespace std;

typedef array<int,4> rect;

#define y0 erjgeribneribner0
#define y1 erjgeribneribner1
#define y2 erjgeribneribner2

map<rect,int> mem;
int q=0;

bool query(int x1,int y1,int x2,int y2)
{
    if(mem.count(rect{x1,y1,x2,y2}))
        return mem[rect{x1,y1,x2,y2}];
    q++;
    if(q>2019)
        exit(1);
    cout<<"? "<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
    int res;
    cin>>res;
    mem[rect{x1,y1,x2,y2}]=res;
    return res%2;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    int x1=n+1,x2=0;
    for(int x=1;x<=n;x++)
        if(query(1,1,x,n))
            x1=min(x1,x),
            x2=max(x2,x+1);
    int y1=n+1,y2=0;
    for(int y=1;y<=n;y++)
        if(query(1,1,n,y))
            y1=min(y1,y),
            y2=max(y2,y+1);
    if(x2&&y2)
    {
        if(!query(x1,y1,x1,y1))
            swap(y1,y2);
        cout<<"! "<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
        exit(0);
    }
    if(x2)
    {
        int l=1,r=n;
        while(l<r)
        {
            int m=(l+r)/2;
            if(query(x1,1,x1,m))
                r=m;
            else
                l=m+1;
        }
        y1=l;
        l=1,r=n;
        while(l<r)
        {
            int m=(l+r)/2;
            if(query(x2,1,x2,m))
                r=m;
            else
                l=m+1;
        }
        y2=l;
    }
    else
    {
        int l=1,r=n;
        while(l<r)
        {
            int m=(l+r)/2;
            if(query(1,y1,m,y1))
                r=m;
            else
                l=m+1;
        }
        x1=l;
        l=1,r=n;
        while(l<r)
        {
            int m=(l+r)/2;
            if(query(1,y2,m,y2))
                r=m;
            else
                l=m+1;
        }
        x2=l;
    }
    cout<<"! "<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
}