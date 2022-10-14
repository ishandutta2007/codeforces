#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
#include <deque>
#include <stack>
#include <stdio.h>
#include <map>
#include <set>
#include <time.h>
#include <string>
#include <fstream>
#include <queue>
#include <bitset>
#include <cstdlib>
#include <assert.h>
#include <list>
#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define pdd pair<double,double>
#define pii pair<ll,ll>
#define PI 3.14159265358979323846
#define MOD 1000000007
#define MOD2 1000000009
#define INF ((ll)1e+18)
#define x1 fldgjdflgjhrthrl
#define x2 fldgjdflgrtyrtyjl
#define y1 fldggfhfghjdflgjl
#define y2 ffgfldgjdflgjl
#define N 131072
#define SUM 377
#define MAG 33554431
#define RED 0
#define BLUE 1
#define ALP 26
typedef long long ll;
typedef long double ld;
using namespace std;
ll i,j,n,k,l,m,tot, flag,r,ans,z, K,x1,y1,x2,y2,x3,y3,x,y,h,num,h2,timer,sz,q,nn;
string s,t,s1;
ll a[1000500], b[1000500], is_one[100500], res[5], cur[100500];
vector<string> Xor, Or, And;
map<string, ll> f;
pii queries[100500];
ll op[100500];
ll d[5005][1005];
char c[1005];
string min_ans, max_ans;
int main() {
	//freopen("input.txt","r",stdin);
 	//freopen("output.txt","w",stdout);
 	cin >> n >> m;
 	for (i = 0; i < n; i++)
    {
        cin >> s;
        cin >> t;
        f[s] = i;
        scanf("%s", c);
        if (c[0] == '0' || c[0] == '1')
        {
            for (j = 0; j < m; j++)
                d[i][j] = c[j] - '0';
            is_one[i] = 1;
        } else
        {
            if (c[0] == '?')
                queries[i].X = n;
            else
            {
                t.clear();
                k = strlen(c);
                for (j = 0; j < k; j++)
                    t.push_back(c[j]);
                queries[i].X = f[t];
            }
            cin >> t;
            if (t == "OR")
                op[i] = 0;
            else
            if (t == "AND")
                op[i] = 1;
            else
                op[i] = 2;
            cin >> t;
            if (t == "?")
                queries[i].Y = n;
            else
                queries[i].Y = f[t];

        }
    }
    for (j = 0; j < m; j++)
    {
        for (k = 0; k < 2; k++)
        {
            cur[n] = k;
            ll tmp = 0;
            for (i = 0; i < n; i++)
            {
                if (is_one[i])
                {
                    cur[i] = d[i][j];
                } else
                {
                    //cout << queries[i].X << " " << queries[i].Y << endl;
                    if (op[i] == 0)
                        cur[i] = (cur[queries[i].X]|cur[queries[i].Y]);
                    else
                    if (op[i] == 1)
                        cur[i] = (cur[queries[i].X]&cur[queries[i].Y]);
                    else
                        cur[i] = (cur[queries[i].X]^cur[queries[i].Y]);
                }
                tmp += cur[i];
                //cout << j << " " << k << " " << i << " " << cur[i] << endl;
            }
            res[k] = tmp;
        }
        if (res[0] == res[1])
        {
            min_ans.push_back('0');
            max_ans.push_back('0');
        } else
        if (res[0] > res[1])
        {
            min_ans.push_back('1');
            max_ans.push_back('0');
        } else
        {
            min_ans.push_back('0');
            max_ans.push_back('1');
        }
    }
    cout << min_ans << endl << max_ans << endl;
    return 0;
}