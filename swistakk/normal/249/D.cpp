#include <iostream>
#include <vector>
#include <set>
#include <cstring>
#include <string>
#include <utility>
#include <cstdio>
#include <algorithm>
#define M 131072
#define N 100005
#define uint long long int
using namespace std;
uint drz[2*M+5];
void akt(uint a, uint war)
{
    a+=M-1;
    // drz[a]=max(drz[a], war);
    while(a)
    {
        drz[a]=max(drz[a], war);
        a/=2;
    }
}
int czyt(uint a, uint b)
{
    a+=M-1;
    b+=M-1;
    uint wyn=0;
    wyn=drz[a];
    wyn=max(wyn, drz[b]);
    while(a/2!= b/2)
    {
        if(a%2==0)
        {
            wyn=max(wyn, drz[a+1]);
        }
        if(b%2==1)
        {
            wyn=max(wyn, drz[b-1]);
        }
        a/=2;
        b/=2;
    }
    return wyn;
}
struct pkt
{
    uint x;
    uint y;
    int nr;
};
pkt p[N];
uint kier[5];
int k1, k2, l1, l2;
uint ilow(pkt a, pkt b, pkt c)
{
    return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
}
bool cmp1(pkt a, pkt b)
{
      pkt c;
      c.x=a.x+kier[1];
      c.y=a.y+kier[2];
      uint bla=ilow(a, c, b);
      if(bla!=0)
      return bla<0;
      return b.y<a.y;
}
bool cmp2(pkt a, pkt b)
{
    pkt c;
    c.x=a.x+kier[3];
    c.y=a.y+kier[4];
    uint bla=ilow(a, c, b);
    if(bla!=0)
    return bla>0;
    else
    return b.x<a.x;
}
pkt nowe[N];      
char buff[100];       
bool cmp3(pkt a, pkt b)
{
    return a.y<b.y;
} 
int main()
{
    // ios_base::sync_with_stdio(0);
    uint n;
    cin>>n;
    int f, e;
    char c;
    cin>>kier[1]>>c>>kier[2]>>kier[3]>>c>>kier[4];
    /* cout<<f<<" "<<e<<endl;
    fgets(buff+1, 1000001, stdin);
    char* tmp = strtok(buff+1, " \n");
    cout<<buff[2]<<endl;
    cout<<buff[1]<<" "<<buff[3]<<" "<<buff[4]<<endl;
    // scanf("%s", buff+1);
    int dlug1=1;
    while(buff[dlug1])
    {
        dlug1++;
    }
    dlug1--;
    // scanf("%s ", buff+dlug1+2);
    int dlug2=dlug1+2;
    while(buff[dlug2])
    {
        dlug2++;
    }
    dlug2--;
    int licz=1;
    for(int i=1; i<=dlug1; i++)
    {
        if(buff[i]=='/' || buff[i]==' ')
        {
            licz++;
        }
        else
        {
            kier[licz]*=10;
            kier[licz]+=int(buff[i])-int('0');
        }
    }
    licz=3;
    for(int i=dlug1+2; i<=dlug2; i++)
    {
        if(buff[i]=='/' || buff[i]==' ')
        {
            licz++;
        }
        else
        {
            kier[licz]*=10;
            kier[licz]+=int(buff[i])-int('0');
        }
    }
    int heh;
    cin>>heh;
    cout<<heh<<" hehe"<<endl;
    cout<<dlug1<<" "<<dlug2<<endl; */
    /* for(int i=1; i<=4; i++)
    {
        cout<<kier[i]<<" ";
    }
    cout<<endl; */
    for(int i=1; i<=n; i++)
    {
        int zia;
        // scanf("%d", &zia);
        //cin>>zia;
        //cout<<zia<<endl;
        cin>>p[i].y>>p[i].x;
        p[i].nr=i;
    }
    /* for(int i=1; i<=n; i++)
    {
        cout<<p[i].x<<" "<<p[i].y<<endl;
    }
    cout<<endl; */
    sort(p, p+1+n, cmp2);
    for(int i=0; i<=n; i++)
    {
        nowe[p[i].nr].y=i+1;
        nowe[p[i].nr].nr=p[i].nr;
        //cout<<p[i].x<<" "<<p[i].y<<endl;
    }
    sort(p, p+1+n, cmp1);
    //cout<<endl;
    for(int i=0; i<=n; i++)
    {
        nowe[p[i].nr].x=i+1;
        //cout<<p[i].x<<" "<<p[i].y<<endl;
    }
    // cout<<endl;
    /* for(int i=1; i<=n; i++)
    {
        cout<<nowe[i].x<<" "<<nowe[i].y<<endl;
    } */
    sort(nowe, nowe+1+n, cmp3);
    uint wynik=0;
    for(int i=0; i<=n; i++)
    {
        uint cos=czyt(1, nowe[i].x);
        if(nowe[i].nr==0 || cos>0)
        {
            wynik=max(wynik, cos+1);
            akt(nowe[i].x, cos+1);
        }
    }
cout<<wynik-1<<endl;
    return 0;
}