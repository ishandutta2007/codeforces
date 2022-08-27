#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
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

int main()
{
    #ifndef ONLINE_JUDGE  
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    #endif
    int n;
    cin>>n;
    vi p(n);
    char x;
    vi color(n, -1);
    int colors=0;
    int A[301][301];
    for(int i=0; i<n;i++) cin>>p[i];
    for(int i=0; i<n; i++) color[i]=i;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) {
            cin>>x;
            if(x=='1') {
                if(color[i]!=color[j]){
                    int old=color[j];
                    for(int k=0; k<n; k++) if(color[k]==old) color[k]=color[i];
                }
            }
                
        }
    }
    vb csort(n, false);
    for(int i=0; i<n; i++) {
        if(csort[color[i]]==false){
            int c = color[i];
            csort[c]=true;
            vi w;
            vi v;
            for(int j=0; j<n; j++) if(color[j]==c) {
                w.pb(j);
                v.pb(p[j]);
            }
            sort(all(v));
            for(int j=0; j<w.size(); j++) p[w[j]] = v[j];
            
        }
    }
    for(int i=0; i<n; i++) cout<<p[i]<<" ";
    
}