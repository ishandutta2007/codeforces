#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <stdio.h>
using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()

#define pb push_back
#define mp make_pair


int a[100001][6];
int logmax[100001][5][20];

int main()
{
#ifndef ONLINE_JUDGE  
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif
    int n, m, k;
    cin>>n>>m>>k;
    ll ans = 0;
    for (int i=0; i<n; i++) {
        for (int j = 0; j < m; j++) cin >> a[i][j];
    }
    
    for (int i=0; i<n; i++) for(int j=0; j<m; j++) logmax[i][j][0] = a[i][j];
    int deg = 1;
    int p2 = 2;
    while(p2<=n) {
        for (int i=0; i<n; i++) for(int j=0; j<m; j++) if ((i+p2/2) < n) logmax[i][j][deg] = max(logmax[i][j][deg-1], logmax[i+p2/2][j][deg-1]);
        p2*=2;
        deg++;
    }
    vi curans(5, 0);
    int num = 0;
    for (int i=0; i<n; i++) {
        int curp2 = p2;
        int curdeg = deg;
        int curnum = 0;
        vi curshots(5, 0);
        vi newshots(5, 0);
        int curpos=i;
        while (curp2>0) {
            if (curpos + curp2<=n) {
                int sum = 0;
                for(int j=0; j<m; j++) sum += newshots[j] = max(curshots[j], logmax[curpos][j][curdeg]);
                if(sum<=k) {
                    curpos+=curp2;
                    for(int j=0; j<m; j++) curshots[j] = newshots[j];
                }
            }
            curp2/=2;
            curdeg--;
        }
        if ((curpos - i) > num) {
            num = curpos - i;
            for(int j=0; j<m; j++) curans[j] = curshots[j];
        }
    }
    for(int j=0; j<m; j++) cout<< curans[j]<<" ";

}