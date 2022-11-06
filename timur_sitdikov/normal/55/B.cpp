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

string s[3];
long long mn=-1;

void rec_sol(vector<long long> v)
{
    if (v.size()==1)
    {
        if (mn==-1 || mn>v[0])
            mn=v[0];
        return;
    }
    int i, j, k, n=v.size();
    for(i=0; i<n; i++)
        for(j=i+1; j<n; j++)
        {
            vector<long long> tmp;
            for(k=0; k<n; k++)
                if (k!=i && k!=j)
                    tmp.pb(v[k]);
            if (s[n-2][0]=='+')
                tmp.pb(v[i]+v[j]);
            else tmp.pb(v[i]*v[j]);
            rec_sol(tmp);
        }
}

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n, i;
    vector<long long> tmp;
    for(i=0; i<4; i++)
    {
        cin >> n;
        tmp.pb(n);
    }
    cin >> s[2] >> s[1] >> s[0];
    rec_sol(tmp);
    cout << mn;
}