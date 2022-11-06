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

const int maxn=1000005, inf=100000000;
vector<int> vals, divs;
char cpr[maxn], sym[200];
vector<int> goods;
string ans;
int v, n;

void my_gcd(int a, int b)
{
    if (b==1)
    {
        if (a!=1)
            vals.pb(a-1);
        return;
    }
    my_gcd(b, a%b);
    vals.pb(a/b);
}

void make_divs(int v)
{
    for(int i=2; i*i<=v; i++)
        if (!(v%i))
        {
            divs.pb(i);
            while(!(v%i))
                v/=i;
        }
    if (v>1)
        divs.pb(v);
}

int calc(int a, int b, int is_odd)
{
    a--;
    int ans=(b-a)>>1;
    if ((!(b&1)) && (!((a+1)&1)))
        ans++;
    if (is_odd)
        ans=b-a-ans;
    return ans;
}

int check(int i)
{
    int cnt, j;
    vals.clear();
    cnt=0;
    my_gcd(v, i);
    for(j=0; j<vals.size(); j++)
        cnt+=vals[j];
    return cnt==n-1;
}

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int i, j, k, mn, f_mn, f_cur, cur, sum, mini, cnt, p, q;
    cin >> n >> v;
    make_divs(v);
    for(i=0; i<(int)divs.size(); i++)
        for(j=divs[i]; j<=v; j+=divs[i])
            cpr[j]=1;
    mn=inf;
    for(i=1; i<=v; i++)
        if (!cpr[i])
            goods.pb(i);
    for(i=0; i<goods.size(); i++)
    {
        if (cpr[goods[i]])
            continue;
        vals.clear();
        cnt=0;
        my_gcd(v, goods[i]);
        for(j=0; j<vals.size(); j++)
            cnt+=vals[j];
        if (cnt!=n-1)
            continue;
        cur=0;
        sum=0;
        for(j=0; j<vals.size(); j++)
        {
            //cur+=calc(sum, sum+vals[j]-1, 1^(j&1));
            cur+=vals[j]-1;
            sum+=vals[j];
        }
        if (cur<n-vals.size())
            f_cur=0;
        else
        {
            cur=n-vals.size();
            f_cur=1;
        }
        if (cur<mn)
        {
            mn=cur;
            mini=goods[i];
            f_mn=f_cur;
        }
    }
    if (mn==inf)
    {
        printf("IMPOSSIBLE");
        return 0;
    }
    printf("%d\n", mn);
    ans.pb('T');
    vals.clear();
    my_gcd(v, mini);
    if (f_mn)
    {
        sym[0]='T';
        sym[1]='B';
    }
    else
    {
        sym[1]='T';
        sym[0]='B';
    }
    for(i=0; i<(int)vals.size(); i++)
        for(j=0; j<vals[i]; j++)
            ans.pb(sym[i&1]);
    cout << ans;
}