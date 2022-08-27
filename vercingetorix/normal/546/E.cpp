#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <set>
#include <map>
#include <unordered_map>
#include <stdio.h>

using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;
typedef std::vector<std::pair<int, int> > vpi;
typedef std::pair<int, int> pi;

long long mod=1000000007;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()

#define pb push_back
#define mp make_pair
const int inf = 1000*1000*1000;


typedef vector<int> graf_line;
typedef vector<graf_line> graf;

typedef vector<int> vint;
typedef vector<vint> vvint;


void push (int u, int v, vvint & f, vint & e, const vvint & c)
{
    int d = min (e[u], c[u][v] - f[u][v]);
    f[u][v] += d;
    f[v][u] = - f[u][v];
    e[u] -= d;
    e[v] += d;
}

void lift (int u, vint & h, const vvint & f, const vvint & c)
{
    int d = inf;
    for (int i = 0; i < (int)f.size(); i++)
        if (c[u][i]-f[u][i] > 0)
            d = min (d, h[i]);
        if (d == inf)
            return;
        h[u] = d + 1;
}




int main()
{
    #ifndef ONLINE_JUDGE  
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    #endif
    
    int l,m;
    cin >> l>>m;
    int n=2*l+2;
    vvint c (n, vint(n,0));
    int x,y;
    int sumin=0, sumout=0;
    for (int i=1; i<=l; i++) {
        cin>>c[0][i];
        sumout+=c[0][i];
        c[i][l+i]=inf;
    }
    for (int i=1; i<=l; i++) {
        cin>>c[i+l][n-1];
        sumin+=c[i+l][n-1];
    }
    for(int i=0; i<m; i++) {
        cin>>x>>y;
        c[x][y+l]=inf;
        c[y][x+l]=inf;
    }
    if(sumin!=sumout) {
        cout<<"NO";
        return 0;
    }
    
        //  -  0,  -  n-1
    
        vvint f (n, vint(n));
        for (int i=1; i<n; i++)
        {
            f[0][i] = c[0][i];
            f[i][0] = -c[0][i];
        }
        
        vint h (n);
        h[0] = n;
        
        vint e (n);
        for (int i=1; i<n; i++)
            e[i] = f[0][i];
        
        for ( ; ; )
        {
            int i;
            for (i=1; i<n-1; i++)
                if (e[i] > 0)
                    break;
                if (i == n-1)
                    break;
                
                int j;
            for (j=0; j<n; j++)
                if (c[i][j]-f[i][j] > 0 && h[i]==h[j]+1)
                    break;
                if (j < n)
                    push (i, j, f, e, c);
                else
                    lift (i, h, f, c);
        }
        
        int flow = 0;
        for (int i=0; i<n; i++)
            if (c[0][i])
                flow += f[0][i];
    
    if(flow!=sumout) {
        cout<<"NO";
        return 0;
    }
    else {
        cout<<"YES\n";
        for(int i=1; i<=l; i++) {
            for(int j=1;j<=l;j++) {
                cout<<f[i][j+l]<<" ";
            }
            cout<<endl;
        }
    }
}