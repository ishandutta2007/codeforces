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

map<string, int> prior;

pair<string, string> pp[200];
char used[200];

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
    prior["rat"] = 5;
    prior["child"] = prior["woman"] = 4;
    prior["man"] = 3;
    prior["captain"] = 2;
    int n, i, j, mx, maxi;
    cin >> n;
    for(i = 0; i < n; i++)
        cin >> pp[i].first >> pp[i].second;
    for(i=0; i<n; i++)
    {
        mx = -1;
        for(j = 0; j<n; j++)
        {
            if (!used[j] && prior[pp[j].second]>mx)
            {
                mx = prior[pp[j].second];
                maxi = j;
            }

        }
        cout << pp[maxi].first << endl;
        used[maxi]=1;
    }
}