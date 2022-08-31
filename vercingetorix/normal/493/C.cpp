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

int main()
{
    #ifndef ONLINE_JUDGE  
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    #endif
    int n,m;
    cin>>n;
    vi aa(n);
    vpi al;
    int mod1=0, mod2=0;
    int nn=n;
    fo(i,0,nn){
        cin>>aa[i];
       /* if(aa[i]==1) {
            mod1+=2;
            n--;
            continue;
        }*/
        al.pb(mp(aa[i],-1));
    }
    
    cin>>m;
    int mm=m;
    vi b(m);
    fo(i,0,mm){
        cin>>b[i];
       /* if(b[i]==1) {
            mod2+=2;
            m--;
            continue;
        }*/
        al.pb(mp(b[i],1));
    }
    int ans=3*(n-m);
    int cura=3*n;
    int cpans=cura;
    int cc=ans;
    //for(int i=0; i<n; i++) 
    sort(all(al));
    auto a=al.begin();
    while(a!=al.end()){
        int cur=(*a).first;
        int cpa =0;
        if((*a).second<0) cpa=-1;
        int cp = (*a).second;
        a++;
        while((a!=al.end())&&(cur==(*a).first)) {
            cp+=(*a).second;
            if((*a).second<0) cpa--;
            a++;
        }
        cc+=cp;
        cura+=cpa;
        if(cc>ans) {
            ans=cc;
            cpans=cura;
        }
        
    }
    cout<<cpans<<":"<<cpans-ans;
    
}