#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

#define maxn 100010

int n, nn, ch, nc, nr, k;
struct trie
{
    int f[27];
    int d[3];
} t[maxn];
string s;

void df(int nod)
{
  //  cerr<<nod;
    int nrf=0, fiu;

    for(int i=0; i<26; ++i)
        if(t[nod].f[i]!=0)
        {
            cerr<<"*";
            fiu=t[nod].f[i];
            ++nrf;
            df(fiu);
            for(int j=0; j<2; ++j)
                if(t[fiu].d[j]==0)
                    t[nod].d[j]=1;
        }

    if(nrf==0)
    {
        t[nod].d[0]=0;
        t[nod].d[1]=1;
    }
}

int main()
{
   // freopen("b.in", "r", stdin);
   // freopen("b.out", "w", stdout);

    cin>>n>>k;

    nn=1;

    while(n--)
    {
        cin>>s;
        nr=s.size();

        nc=1;
      //  cerr<<s;

        for(int i=0; i<nr; ++i)
        {
            ch=s[i]-'a';
            if(ch<0 || ch>=26)
                break;
            if(t[nc].f[ch]==0)
                t[nc].f[ch]=++nn;
            nc=t[nc].f[ch];
          //  cerr<<nc<<"\n";
        }
    }
  //  cerr<<"*"<<nn<<"\n";

    df(1);

    if(k==1)
    {
        if(t[1].d[0]==1)
            printf("First\n");
        else
            printf("Second\n");

        return 0;
    }

    if(t[1].d[1]==1 && t[1].d[0]==1)
    {
        printf("First\n");
        return 0;
    }
    if(t[1].d[0]==1 && t[1].d[1]==0)
    {
        if(k%2==0)
            printf("Second\n");
        else
            printf("First\n");
        return 0;
    }
    if(t[1].d[0]==0 && t[1].d[1]==1)
    {
        printf("Second\n");
        return 0;
    }
    if(t[1].d[0]==0 && t[1].d[1]==0)
    {
        printf("Second\n");
        return 0;
    }

    return 0;
}