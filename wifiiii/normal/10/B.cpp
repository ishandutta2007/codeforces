#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<cmath>
#include<cstring>
using namespace std;
typedef long long ll;

int n,k;
int g[111][111];
int cnt(int x,int y,int len)
{
    int mid = k / 2 + 1;
    int ret = abs(x - mid) * len;
    int l = y, r = y + len - 1;
    if(r<=mid)
    {
        ret += (2*mid-l-r)*len/2;
    }
    else if(mid<=l)
    {
        ret += (l+r-2*mid)*len/2;
    }
    else // y < mid < mid+1 <= y+len-1
    {
        ret += (mid-l)*(mid-l+1)/2 + (r-mid+1)*(r-mid)/2;
    }
    return ret;
}
int main()
{
    cin>>n>>k;
    for(int i=1;i<=k;++i)
    {
        for(int j=1;j<=k;++j)
        {
            g[i][j]=k-j+1;
        }
    }
    while(n--)
    {
        int m;cin>>m;int x,y,minn=1e9,temp;
        for(int i=1;i<=k;++i)
        {
            for(int j=1;j<=k;++j)
            {
                if(g[i][j]<m) continue;
                if((temp=cnt(i,j,m))<minn)
                {
                    x=i,y=j,minn=temp;
                }
                //cout << i << " " << j << " " << cnt(i,j,m) << endl;
            }
        }
        if(minn == 1e9) {cout << -1 << endl;continue;}
        else cout << x << " " << y << " " << y + m - 1 << endl;
        for(int i=y-1,j=1;i>=1&&g[x][i];--i,j++) g[x][i]=j;
        for(int i=y;i<=y+m-1;++i) g[x][i] = 0;
    }
}