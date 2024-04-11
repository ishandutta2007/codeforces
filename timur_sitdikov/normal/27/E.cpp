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

vector<int> st, best, pr;
vector<int> del, deldel[100];
double mn=1e+30;

long long bin_pow(long long a, int st)
{
    long long ans=1;
    while(st)
    {
        if (st&1) ans=ans*a;
        a=a*a;
        st>>=1;
    }
    return ans;
}

double bin_pow(double a, int st)
{
    double ans=1;
    while(st)
    {
        if (st&1) ans=ans*a;
        a=a*a;
        st>>=1;
    }
    return ans;
}

void rec_sol(int num)
{
    int i, ind;
    if (num==1)
    {
        double tmp=1., tmp1;
        for(i=0; i<(int)st.size(); i++)
            tmp*=bin_pow((double)pr[i], st[i]-1);
        if (tmp<mn) {mn=tmp; best=st;}
        return;         
    }
    for(i=0; i<(int)del.size(); i++)
        if (del[i]==num) {ind=i; break;}
    for(i=0; i<(int)deldel[ind].size(); i++)
    {
        if (st.size()==0 || deldel[ind][i]<=st[st.size()-1]) 
        {
            st.push_back(deldel[ind][i]);
            rec_sol(num/deldel[ind][i]);
            st.pop_back();
        }
        else break;
    }
}

int main()
{   
   /* freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);*/
    int i, j, f, n;
    long long ans=1;
    scanf("%d", &n);
    for(i=2; i<=100; i++)
    {
        f=0;
        for(j=2; j<i; j++)
            if (!(i%j)) f=1;
        if (!f) pr.push_back(i);
    }
    for(i=2; i<=n; i++)
        if (!(n%i)) del.push_back(i);
    for(i=0; i<(int)del.size(); i++)
        for(j=2; j<=del[i]; j++)
            if (!(del[i]%j)) deldel[i].push_back(j);
    rec_sol(n);
    for(i=0; i<(int)best.size(); i++)
        ans*=bin_pow((long long)pr[i], best[i]-1);
    printf("%I64d", ans);

}