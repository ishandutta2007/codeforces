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
#define xx real()
#define yy imag()

const int maxn = 105;
map<string, int> arta[maxn], artb[maxn];
map<string, int>::iterator iti;
map<string, vector<pair<string, int> > > content;
map<string, vector<pair<string, int> > >::iterator it;

map<string, int> ans;

int main()
{   
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int k, n, m, q, i, j, a, v, f;
    char c[1000], c1;
    string s, s1;
    cin >> k >> n >> m >> q;
    for(i = 0; i < n; i++){
        cin >> s;
        for(j = 1; j <= k; j++){
            arta[j][s] = 0;
        }
    }
    for(i = 0; i < m; i++){
        scanf("%s", &c);
        c[strlen(c) - 1] = 0;
        s = c;
        do{
            scanf("%s %d", &c, &a);
            s1 = c;
            content[s].pb(mp(s1, a));
        }
        while( (c1 = getchar()) == ',' );
    }
    for(i = 0; i < q; i++){
        cin >> a >> s;
        arta[a][s]++;
        for(it = content.begin(); it != content.end(); it++){
            f = 0;
            for(j = 0; j < (int)it->second.size(); j++){
                s = it->second[j].first;
                v = it->second[j].second;
                if (arta[a][s] < v){
                    f = 1;
                    break;
                }
            }
            if (!f){
                artb[a][it->first]++;
                for(j = 0; j < (int)it->second.size(); j++){
                    s = it->second[j].first;
                    v = it->second[j].second;
                    arta[a][s] -= v;
                }
                break;
            }
        }
    }
    for(i = 1; i <= k; i++){
        ans.clear();
        for(iti = arta[i].begin(); iti != arta[i].end(); iti++){
            if (iti->second){
                ans[iti->first] = iti->second;
            }
        }
        for(iti = artb[i].begin(); iti != artb[i].end(); iti++){
            ans[iti->first] = iti->second;
        }
        cout << ans.size() << endl;
        for(iti = ans.begin(); iti != ans.end(); iti++){
            cout << iti->first << " " << iti->second << endl;
        }
    }
}