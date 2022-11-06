#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <complex>
using namespace std;
#define pb push_back
#define mp make_pair
#define point complex<double>
#define xx first
#define yy second

int mm[13];
map<pair<int, int>, int> ind;

const int maxn=1000000;

void init()
{
    mm[1]=mm[3]=mm[5]=mm[7]=mm[8]=mm[10]=mm[12]=31;
    mm[4]=mm[6]=mm[9]=mm[11]=30;
    mm[2]=29;
    int i, j, cur;
    for(cur=1, i=1; i<=12; i++)
        for(j=1; j<=mm[i]; j++)
        {
            ind[mp(i, j)]=cur++;
        }
}

struct date
{
    int mm, dd, hh, m, s;
    date(int mm, int dd, int hh, int m, int s)
    {
        this->mm=mm;
        this->dd=dd;
        this->hh=hh;
        this->m=m;
        this->s=s;
    }
    date(){}
}dt[maxn];

const int ddd=60*60*24;
int get_time(date &dt)
{
    int ans=dt.s+60*dt.m+60*60*dt.hh+ind[mp(dt.mm, dt.dd)]*ddd;
    return ans;
}

pair<int, int> mas[maxn];

void prn(int v)
{
    printf("%d%d", v/10, v%10);

}

void output(int ind)
{
    ind=mas[ind].second;
    printf("2012-");
    prn(dt[ind].mm);
    putchar('-');
    prn(dt[ind].dd);
    putchar(' ');
    prn(dt[ind].hh);
    putchar(':');
    prn(dt[ind].m);
    putchar(':');
    prn(dt[ind].s);
}

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
    init();
    int i, n, nn, mm, yy, dd, hh, m, s, tmp;
    char c;
    scanf("%d %d", &n, &nn);
    for(i=0; ;i++)
    {
        scanf("%d-%d-%d %d:%d:%d", &yy, &mm, &dd, &hh, &m, &s);
        dt[i]=date(mm, dd, hh, m, s);
        tmp=get_time(dt[i]);
        mas[i]=mp(tmp, i);
        for(; (c=getchar())!='\n'; )
            if (c==-1)
                goto ll;
    }
ll: sort(mas, mas+i);
    m=nn;
    nn=n;
    n=i;
    for(i=m-1; i<n; i++)
        if (mas[i].first-mas[i-m+1].first<nn)
        {
            output(i);
            return 0;
        }
    printf("-1");
}