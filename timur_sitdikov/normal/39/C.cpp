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

const int maxn=4005;
int dp[maxn][maxn], x_left[maxn], ind_left[maxn], x_right[maxn];
char prv[maxn][maxn];
vector<int> ans;

struct brace
{
    int ind, type, x;
} br[maxn];

bool cmp(brace &b1, brace &b2)
{
    if (b1.x!=b2.x)
        return b1.x<b2.x;
    if (b1.type!=b2.type)
        return b1.type>b2.type;
    if (!b1.type)
        return x_right[b1.ind]>x_right[b2.ind];
    else 
        return x_left[b1.ind]>x_left[b2.ind]; 
}

int get_dp(int l, int r)
{
    if (r<l)
        return 0;
    return dp[l][r];
}

void get_ans(int l, int r)
{
    if (r<=l)
        return;
    if (prv[l][r])
    {
        ans.pb(br[r].ind);
        int tmp=ind_left[br[r].ind];
        get_ans(l, tmp-1);
        get_ans(tmp+1, r-1);
    }
    else get_ans(l, r-1);
}

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n, i, j, k, c, r, tmp;
    cin >> n;
    for(i=0; i<n; i++)
    {
        cin >> c >> r;
        x_left[i]=c-r;
        x_right[i]=c+r;
        br[2*i].ind=br[2*i+1].ind=i;
        br[2*i].type=0;
        br[2*i+1].type=1;
        br[2*i].x=c-r;
        br[2*i+1].x=c+r;
    }
    sort(br, br+2*n, cmp);
    for(i=0; i<2*n; i++)
        if (!br[i].type)
            ind_left[br[i].ind]=i;
    for(i=2*n-2; i>=0; i--)
        for(j=i+1; j<2*n; j++)
        {
            dp[i][j]=dp[i][j-1];
            prv[i][j]=0;
            k=ind_left[br[j].ind];
            if (br[j].type && k>=i)
            {
                tmp=get_dp(i, k-1)+get_dp(k+1, j-1)+1;
                if (tmp>dp[i][j])
                {
                    dp[i][j]=tmp;
                    prv[i][j]=1;
                }
            }
        }
    get_ans(0, 2*n-1);
    cout << (int)ans.size() << endl;
    for(i=0; i<(int)ans.size(); i++)
        cout << ans[i]+1 << " ";
}