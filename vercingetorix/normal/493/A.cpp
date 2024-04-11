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
    //int n,k;
    vector<string> s(2);
    cin>>s[0]>>s[1];
    int n;
    cin>>n;
    vi player(200,0);
    vvi event(100);
    fo(i,0,n){
        int t;
        char c;
        int m;
        char card;
        cin>>t>>c>>m>>card;
        int team;
        if(c=='h') team=0;
        else team=1;
        //event[t].pb(team);
        event[t].pb(100*team+m);
        int cardtype;
        if(card=='y') cardtype = 1;
        else cardtype=2;
        event[t].pb(cardtype);
    }
    for(int i=1; i<91; i++) {
        if(event[i].size()==0) continue;
        if (player[event[i][0]]>=2) continue;
        else player[event[i][0]]+=event[i][1];
        if (player[event[i][0]]>=2) cout<<s[event[i][0]/100]<<" "<<event[i][0]%100<<" "<<i<<endl;
    }
    
}