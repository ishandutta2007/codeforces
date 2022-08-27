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
typedef std::vector<std::pair<int, int> > vpi;
typedef std::pair<int, int> pi;

long long mod=1000000007;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()
#define fo(a, b, c) for(int a = b; a < c; a++)

#define pb push_back
#define mp make_pair
int b[501][501];
int main()
{
    #ifndef ONLINE_JUDGE  
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    #endif
    int n,m,q,k;
    cin>>n>>m>>q;
    int ans;
    vi maxline(n,0);
    for(int i=0; i<n; i++) {
        ans=0;
        int pret=0;
        fo(j,0,m) {
            cin>>b[i][j];
            if(b[i][j]==1) pret++;
            else {
                if(pret>ans) ans=pret;
                pret=0;
            }
        }
        if(pret>ans) ans=pret;
        maxline[i]=ans;
    }
    int x,y;
    fo(i,0,q){
        cin>>x>>y;
        x--; y--;
        b[x][y]=1-b[x][y];
        int pret=0;
        ans=0;
        fo(j,0,m) {
            if(b[x][j]==1) pret++;
            else {
                if(pret>ans) ans=pret;
                pret=0;
            }
        }
        if(pret>ans) ans=pret;
        maxline[x]=ans;
        ans=0;
        fo(j,0,n) {
            if(maxline[j]>ans) ans=maxline[j];
        }
        cout<<ans<<endl;
    }
}