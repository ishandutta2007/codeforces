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
using namespace std;

vector <pair<long long, int> > del1, del2, del3, del4;
long long n1, p, q, r, mn=-1, mx=-1;

void rec_find2(int n)
{
    int i, j, sz, sz2;
    long long tmp;
    if (n==(int)del2.size())
    {
        p=q=r=1;
        sz=del2.size();
        for(i=0; i<sz; i++)
        {
            for(j=0; j<del3[i].second; j++)
                p*=del3[i].first;
            for(j=0; j<del4[i].second; j++)
                q*=del4[i].first;
            for(j=0; j<del2[i].second-del4[i].second; j++)
                r*=del2[i].first;
        }
        tmp=(p+1)*(q+2)*(r+2);
        if (mx==-1 || tmp-n1>mx)
        {
            mx=tmp-n1;
        }
        if (mn==-1 || tmp-n1<mn)
        {
            mn=tmp-n1;
        }
        return;
    }
    for(i=0; i<=del2[n].second; i++)
    {
        del4.push_back(make_pair(del2[n].first, i));
        rec_find2(n+1);
        del4.pop_back();
    }
    return;
}

void rec_find(int n)
{
    int i, sz, sz2;
    if (n==(int)del1.size())
    {
        sz=del3.size();
        del2.clear();
        for(i=0; i<sz; i++)
            del2.push_back(make_pair(del1[i].first, del1[i].second-del3[i].second));
        rec_find2(0);
        return;
    }
    for(i=0; i<=del1[n].second; i++)
    {
        del3.push_back(make_pair(del1[n].first, i));
        rec_find(n+1);
        del3.pop_back();
    }
    return;
}

void factor(long long n)
{
    long long i;
    for(i=2; i*i<=n; i++)
    {
        if (!(n%i))
        {
            del1.push_back(make_pair(i, 0));
            while(!(n%i))
            {
                del1[del1.size()-1].second++;
                n/=i;
            }
        }
    }
    if (n>1)
        del1.push_back(make_pair(n, 1));
}

int main()
{   
    int i, sz;
    scanf("%I64d", &n1);

    factor(n1);
    rec_find(0);
    printf("%I64d %I64d\n", mn, mx);

}