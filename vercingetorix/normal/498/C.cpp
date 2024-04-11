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

typedef vector<int> vint;
typedef vector<vint> vvint;

const int inf = 1000*1000*1000;

long long mod=1000000007;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()

#define pb push_back
#define mp make_pair

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
    
    
    std::vector<int> p;
    for(int i=2; i<=32000; i++){
        bool f=false;
        for(int j=0; j<upper_bound(all(p), (int)sqrt((double) i))-p.begin();j++) if(i%p[j]==0){
            f=true;
            break;
        }
        if(f) continue;
        p.push_back(i);
    }
    
    int n,m;
    cin >> n >> m;
    vi a(n+1);
    ll ans=0;
    for(int i=1; i<=n; i++) cin>>a[i];
    n+=2;
    vvint c (n, vint(n,0));
    for(int i=0; i<m; i++) {
        int x,y;
        cin>>x>>y;
        if(x%2==0) swap(x,y);
        c[x][y] = inf;
    }
        
    /* for (int i=0; i<n; i++)
            for (int j=0; j<n; j++)
                cin >> c[i][j];*/
            //  -  0,  -  n-1
     for(int jj=0; jj<p.size(); jj++) {
         int pp=p[jj];
         bool ff=false;
         for(int i=1; i<=n-2; i+=2) {
            c[0][i]=0;
            while(a[i]%pp==0) {
                ff=true;
                c[0][i]++;
                a[i]/=pp;
            }
         }
         if(!ff) continue;
         ff=false;
         for(int i=2; i<=n-2; i+=2) {
             c[i][n-1]=0;
             while(a[i]%pp==0) {
                 ff=true;
                 c[i][n-1]++;
                 a[i]/=pp;
             }
         }
         if(!ff) continue;
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

        ans+= max(flow,0);
    }
    
    for(int jj=1; jj<=n-2; jj++) {
        int pp=a[jj];
        if(pp==1) continue;
        bool ff=false;
        for(int i=1; i<=n-2; i+=2) {
            c[0][i]=0;
            while(a[i]%pp==0) {
                ff=true;
                c[0][i]++;
                a[i]/=pp;
            }
        }
        if(!ff) continue;
        ff=false;
        for(int i=2; i<=n-2; i+=2) {
            c[i][n-1]=0;
            while(a[i]%pp==0) {
                ff=true;
                c[i][n-1]++;
                a[i]/=pp;
            }
        }
        if(!ff) continue;
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
            
            ans+= max(flow,0);
    }
    cout<<ans;
}