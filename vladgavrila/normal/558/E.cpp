#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

#define sigma 26
#define maxn 100010

int n, m;
int sum[4*maxn][26], t[4*maxn], cc[maxn];
string s;

void build(int nod, int left, int right)
{
    if(left==right)
    {
        sum[nod][s[left-1]-'a']=1;
        t[nod]=s[left-1]-'a';
        return;
    }

    int med=(left+right)/2;

    build(nod*2, left, med);
    build(nod*2+1, med+1, right);

    t[nod]=-1;

    for(int i=0; i<sigma; ++i)
        sum[nod][i]=sum[nod*2][i]+sum[nod*2+1][i];
}

void push(int nod, int left, int med, int right)
{
    t[nod*2]=t[nod];
    for(int i=0; i<sigma; ++i)
        sum[nod*2][i]=0;
    sum[nod*2][t[nod]]=med-left+1;

    t[nod*2+1]=t[nod];
    for(int i=0; i<sigma; ++i)
        sum[nod*2+1][i]=0;
    sum[nod*2+1][t[nod]]=right-med;

    t[nod]=-1;
}

int query(int nod, int left, int right, int qleft, int qright, int w)
{
    if(qleft <= left && right <= qright)
        return sum[nod][w];

    int med=(left+right)/2;

    if(t[nod]!=-1)
        push(nod, left, med, right);

    int ras=0;

    if(qleft<=med)
        ras+=query(nod*2, left, med, qleft, qright, w);
    if(med<qright)
        ras+=query(nod*2+1, med+1, right, qleft, qright, w);

    return ras;
}

void update(int nod, int left, int right, int uleft, int uright, int w)
{
    if(uleft <= left && right <= uright)
    {
        t[nod]=w;
        for(int i=0; i<sigma; ++i)
            sum[nod][i]=0;
        sum[nod][w]=right-left+1;
        return;
    }

    int med=(left+right)/2;

    if(t[nod]!=-1)
        push(nod, left, med, right);

    if(uleft<=med)
        update(nod*2, left, med, uleft, uright, w);
    if(med<uright)
        update(nod*2+1, med+1, right, uleft, uright, w);

    for(int i=0; i<sigma; ++i)
        sum[nod][i]=sum[nod*2][i]+sum[nod*2+1][i];
}

void tell(int nod, int left, int right)
{
    if(left==right)
    {
        printf("%c", t[nod]+'a');
        return;
    }

    int med=(left+right)/2;

    if(t[nod]!=-1)
        push(nod, left, med, right);

    tell(nod*2, left, med);
    tell(nod*2+1, med+1, right);
}

int main()
{
    std::cout.sync_with_stdio(false);

    cin>>n>>m;
    cin>>s;

    build(1, 1, n);

   //     tell(1, 1, n);
  //  printf("\n");

    while(m--)
    {
        int x, y, tt;
        cin>>x>>y>>tt;

        for(int i=0; i<sigma; ++i)
            cc[i]=query(1, 1, n, x, y, i);

        int cr=x;

        if(tt==1)
        {
            for(int i=0; i<sigma; ++i)
            {
                if(cc[i]>0)
                    update(1, 1, n, cr, cr+cc[i]-1, i);
                cr+=cc[i];
            }
        }
        else
        {
            for(int i=sigma-1; i>=0; --i)
            {
                if(cc[i]>0)
                    update(1, 1, n, cr, cr+cc[i]-1, i);
                cr+=cc[i];
            }
        }
      //      tell(1, 1, n);
      //  printf("\n");
    }

    tell(1, 1, n);

    printf("\n");

    return 0;
}