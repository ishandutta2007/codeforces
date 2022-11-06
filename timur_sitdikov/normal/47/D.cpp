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

int cur[5], v[15];
string st[15], tmp;

void gen_next(int k, int n)
{
    int i, pos;
    pos=n-1;
    for(i=k-1; i>=0 && cur[i]==pos; i--, pos--);
    if (i==-1)
        return;
    cur[i]++;
    for(i++; i<k; i++)
        cur[i]=cur[i-1]+1;
}

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int ans, num, n, k, top, i, j, j1, f;
    cin >> n >> top;
    for(i=0; i<top; i++)
        cin >> st[i] >> v[i];
    k=v[0];
    num=1;
    for(i=n; i>=n-k+1; i--)
        num*=i;
    for(i=1; i<=k; i++)
        num/=i;
    for(i=0; i<k; i++)
        cur[i]=i;
    ans=0;
    for(i=0; i<num; i++)
    {
        tmp.clear();
        for(j=0; j<n; j++)
            tmp.pb('0'+'1'-st[0][j]);
        for(j=0; j<k; j++)
            tmp[cur[j]]='0'+'1'-tmp[cur[j]];
        for(j1=1; j1<top; j1++)
        {
            f=0;
            for(j=0; j<n; j++)
                f+=tmp[j]==st[j1][j];
            if (f!=v[j1])
                break;
        }
        if (j1==top)
            ans++;
        gen_next(k, n);
    }
    cout << ans;

}