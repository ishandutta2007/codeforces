#include <cstdio>
#include <map>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int n, m, a, b, c, mdif, mf;
string s, nm;
map<string, int> mp;
int f[20][20], v[20];

void compute()
{
    int xp[4], cl=0, nr[4];
    xp[1]=a;
    xp[2]=b;
    xp[3]=c;

    nr[1]=nr[2]=nr[3]=0;

    for(int i=1; i<=3; ++i)
        for(int c1=1; c1<=7; ++c1)
        {
            if(v[c1]==i)
                ++nr[i];
            for(int c2=1; c2<=7; ++c2)
                if(v[c1]==i && v[c2]==i && f[c1][c2]==1)
                    ++cl;
        }

    if(nr[1]*nr[2]*nr[3]==0)
        return;

    for(int i=1; i<=3; ++i)
        xp[i]/=nr[i];

    int cd=max(max(xp[1], xp[2]), xp[3])-min(min(xp[1], xp[2]), xp[3]);

    if(cd<mdif)
    {
        mdif=cd;
        mf=0;
    }
    if(cd==mdif && cl>mf)
        mf=cl;
}

void get_instr()
{
    getline(cin, s);
    int p=0;
    string nm1="", nm2="";
    while(s[p]!=' ')
        nm1+=s[p++];
    ++p;
    while(s[p]!=' ')
        ++p;
    ++p;
    while(p<s.size())
        nm2+=s[p++];

    f[mp[nm1]][mp[nm2]]=1;
}

void back(int pz)
{
    if(pz==8)
    {
        compute();
        return;
    }
    for(int i=1; i<=3; ++i)
    {
        v[pz]=i;
        back(pz+1);
    }
}

int main()
{
  //  freopen("data.in", "r", stdin);
  //  freopen("data.out", "w", stdout);

    mp["Anka"]=1;
    mp["Chapay"]=2;
    mp["Cleo"]=3;
    mp["Troll"]=4;
    mp["Dracul"]=5;
    mp["Snowy"]=6;
    mp["Hexadecimal"]=7;

    mdif=1000000000;

    scanf("%d\n", &n);
    while(n--)
        get_instr();
    scanf("%d%d%d", &a, &b, &c);

    back(1);

    printf("%d %d\n", mdif, mf);

    return 0;
}