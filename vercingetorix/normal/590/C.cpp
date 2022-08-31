#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <set>
#include <map>
#include <deque>
#include <unordered_map>
#include <stdio.h>

using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;
typedef std::vector<std::vector<bool> > vvb;
typedef std::vector<std::pair<int, int> > vpi;
typedef std::pair<int, int> pi;

long long mod=1000000007;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()
#define fo(a, b, c) for(int a = b; a < c; a++)

#define pb push_back
#define mp make_pair
int n,m;
int cc;

vvi d(4, vi(4, 9999999));

void bd(vvi & q, vvi & dist, vvi & a) {
    vpi cs;
    int cd= 0;
    vvb u(n,vb(m, false));
    
   
    
    for(int i = 0; i < n; i++)
        for(int j=0; j<m; j++) {
            if(q[i][j] == 0) {
                cs.pb(mp(i,j));
                u[i][j]=true;
            }
        }
    while(cs.size()>0) {
        
        
        
        vpi newcs;
        for(auto o : cs) {
            int x = o.first;
            int y = o.second;
            //cout<<x<<" "<<y<<" af"<<endl;
            if(x>0) {
                if(!u[x-1][y]) {
                u[x-1][y]=true;
                int p = a[x-1][y];
                dist[x-1][y]=cd;
                if(p==0) {
                    newcs.pb(mp(x-1,y));
                    
                }}
            }
            if(x<n-1) {
                if(!u[x+1][y]) {
                u[x+1][y]=true;
                int p = a[x+1][y];
                dist[x+1][y]=cd;
                if(p==0) {
                    newcs.pb(mp(x+1,y));
                    
                }}
            }
            if(y>0) {
                if(!u[x][y-1]) {
                u[x][y-1]=true;
                int p = a[x][y-1];
                dist[x][y-1]=cd;
                if(p==0) {
                    newcs.pb(mp(x,y-1));
                    
                }}
            }
            if(y<m-1) {
                if(!u[x][y+1]) {
                u[x][y+1]=true;
                int p = a[x][y+1];
                dist[x][y+1]=cd;
                if(p==0) {
                    newcs.pb(mp(x,y+1));
                     }
                
            }}
        }

        cs = newcs;

        cd++;
    }
    //cout<<"AONFAF"<<endl;
}

int main()
{
    #ifndef ONLINE_JUDGE  
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    #endif
    
    //cin>>n>>m;
    scanf("%d %d\n", &n, &m);
    vvi a(n, vi(m));
    //vvi a(1000, vi(1000));
    for(int i = 0; i < n; i++){
        for(int j=0; j<m; j++) {
            char c;
            scanf("%c", &c);
            if(c=='1') a[i][j]=1;
            if(c=='2') a[i][j]=2;
            if(c=='3') a[i][j]=3;
            if(c=='.') a[i][j]=0;
            if(c=='#') a[i][j]=-1;
            
        }scanf("\n");
    }
    
    vvi a1(n, vi(m));
    vvi a2(n, vi(m));
    vvi a3(n, vi(m));
    vvi dist1(n, vi(m));
    vvi dist2(n, vi(m));
    vvi dist3(n, vi(m));
    for(int i = 0; i < n; i++)
        for(int j=0; j<m; j++) {
            if(a[i][j]==1) a1[i][j]==0;
            else a1[i][j]=9999999;
            if(a[i][j]==2) a2[i][j]==0;
            else a2[i][j]=9999999;
            if(a[i][j]==3) a3[i][j]==0;
            else a3[i][j]=9999999;
        }
        cc=1;
    dist1=a1;
    dist2=a2;
    dist3=a3;
    bd(a1, dist1,a);cc=2;
    bd(a2, dist2,a);cc=3;
    bd(a3, dist3,a);

       /* for(int i = 0; i < n; i++){
            for(int j=0; j<m; j++) {
                cout<<a[i][j]<<" ";
            }cout<<endl;
        }
        cout<<endl; */
    int dist12=9999999, dist23=9999999, dist13=9999999;
    int dist123 = 9999999;
    for(int i = 0; i < n; i++)
        for(int j=0; j<m; j++) {
            if((a[i][j]==1)&&(dist2[i][j]<dist12)) dist12=dist2[i][j];
            if((a[i][j]==1)&&(dist3[i][j]<dist13)) dist13=dist3[i][j];
            if((a[i][j]==3)&&(dist2[i][j]<dist23)) dist23=dist2[i][j];
            int d1=dist1[i][j];
            int d2=dist2[i][j];
            int d3=dist3[i][j];
            if(a[i][j]!=0) continue;
            if(d1+d2+d3+1<dist123) dist123=d1+d2+d3+1;
        }
    int ans = 9999999;
    ans = min(ans, dist12+dist23);
    ans = min(ans, dist13+dist23);
    ans = min(ans, dist12+dist13);
    ans = min(ans, dist123);
    if(ans>=9999999) ans =-1;
    cout<<ans;
    //for(int i=0; i<n; i++) 
    
}