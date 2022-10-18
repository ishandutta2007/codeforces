#pragma GCC optimize("O3")
#include<bits/stdc++.h>

using namespace std;

#define int short

const int N=5000;

#define y1 aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1
#define y2 aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa2

int x1[N],y1[N],x2[N],y2[N];
bitset<N> b[N];

#define row(x,y,z) x<=y&&y<=z

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>x1[i]>>y1[i]>>x2[i]>>y2[i];
        if(x1[i]>x2[i]||y1[i]>y2[i])
            swap(x1[i],x2[i]),
            swap(y1[i],y2[i]);
    }
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            if((row(x1[i],x1[j],x2[i])||row(x1[i],x2[j],x2[i])||row(x1[j],x1[i],x2[j])||row(x1[j],x2[i],x2[j]))&&
               (row(y1[i],y1[j],y2[i])||row(y1[i],y2[j],y2[i])||row(y1[j],y1[i],y2[j])||row(y1[j],y2[i],y2[j])))
                b[i].set(j),
                b[j].set(i);
    long long ans=0;
    int h=0,v=0;
    for(int i=0;i<n;i++)
        if(x1[i]==x2[i])
            v++;
        else
            h++;
    if(v<h)
    {
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
                if(x1[i]==x2[i]&&x1[j]==x2[j])
                {
                    signed k=(b[i]&b[j]).count();
                    ans+=k*(k-1);
                }
    }
    else
    {
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
                if(y1[i]==y2[i]&&y1[j]==y2[j])
                {
                    signed k=(b[i]&b[j]).count();
                    ans+=k*(k-1);
                }
    }
    cout<<(ans>>1);
}