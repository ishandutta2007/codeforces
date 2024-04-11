#include <iostream>
#include <cstdio>
#include <utility>
#include <algorithm>
#define N 1000005
#define M 1048576
#define INF 100000000
#define uint long long int
using namespace std;
int odp[N];
struct wez
{
    int w;
    int m;
    int ind;
};
wez drz[2*M+5];
void aktu(int a, int war)
{
    drz[a].w+=war;
    if(a>=M)
    {
        drz[a].m=drz[a].w;
        // drz[a].ind=a-M+1;
    }
    else
    {
        int g;
        if(drz[2*a].m<=drz[2*a+1].m)
        {
            g=1;
        }
        else
        {
            g=0;
        }
        drz[a].m=drz[2*a+g].m+drz[a].w;
        drz[a].ind=drz[2*a+g].ind;
    }
}
void dodaj(int a, int b, int w)
{
    a+=M-1;
    b+=M-1;
    aktu(a, w);
    if(a!=b)
    {
        aktu(b, w);
    }
    while(a)
    {
        if(a/2 !=b/2)
        {
            if(a%2==0)
            {
                aktu(a+1, w);
            }
            if(b%2==1)
            {
                aktu(b-1, w);
            }
        }
        aktu(a, 0);
        aktu(b, 0);
        a/=2;
        b/=2;
    }
}
pair<int, int> wyciagnij()
{
    return make_pair(drz[1].m, drz[1].ind);
}
int czyt(int a)
{
    a+=M-1;
    uint licz=0;
    while(a)
    {
        licz+=drz[a].w;
        a/=2;
    }
    return licz;
}
int a[N];
pair<int, int> pkt[N];
int main()
{
    //ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        a[i] -= i;
        dodaj(i, i, -i);
        pkt[i]=make_pair(a[i], i);
    }
    for(int i=1; i<=M; i++)
    {
        drz[i+M-1].ind=i;
    }
    for(int i=2*M-1; i>=1; i--)
    {
        aktu(i, 0);
    }
    sort(pkt+1, pkt+1+n);
    dodaj(n+1, M, -INF);
    int last=0;
    uint wynik=0;
    //cout<<"cos"<<endl;
    for(int i=1; i<=n; i++)
    {
        /* for(int j=1; j<=n; j++)
        {
            cout<<j<<" "<<czyt(j)<<endl;
        } */
        pair<int, int> b=pkt[i];
        pair<int, int> c;
        if(last<b.second)
        {
        dodaj(b.second, n, 2);
        do
        {
            c=wyciagnij();
            //cout<<c.first<<" lol "<<c.second<<endl;
            //cout<<czyt(c.second)<<endl;
            if(c.first>=0)
            {
                for(int j=last+1; j<=c.second; j++)
                {
                    wynik+=abs(a[j]-b.first);
                    odp[j]=b.first;
                }
                dodaj(last+1, c.second, -INF);
                last=c.second;
                if(c.first==1)
                {
                    dodaj(last+1, n, -1);
                }
            }
        }while(c.first>=0);
        }
    }
    cout<<wynik<<endl;
    return 0;
}