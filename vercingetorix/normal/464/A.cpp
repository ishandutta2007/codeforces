#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <deque>
#include <queue>
#include <cstring>
#include <set>
#include <list>
#include <map>
#include <unordered_map>
#include <stdio.h>

using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<string> vs;
typedef std::vector<double> vd;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;
typedef std::vector<std::vector<bool> > vvb;
typedef std::vector<std::pair<int, int> > vpi;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pll;
typedef std::vector<pll> vpll;

long long mod=1000000007;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()
#define forn(i, a, b) for(int i = a; i < b; i++)

#define pb push_back
#define mp make_pair

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,p,a,b;
    //ll ans=0;
    scanf("%d %d\n",&n,&p);
    string s;
    cin>>s;
    if(p==1) {
        cout<<"NO";
        return 0;
    }
    if(p==2) {
        if(s=="ab") cout<<"ba"<<endl;
        else if(s=="a") cout<<"b"<<endl;
        else cout<<"NO"<<endl;
        return 0;
        
    }
    vi ans(n);
    forn(i,0,n) ans[i] = s[i]-'a';
    int cur = n-1;
    ans[cur]++;
    while(cur>0) {
        if(ans[cur]>=p) {
            cur--;
            ans[cur]++;
            continue;
        }
        else if(ans[cur-1]==ans[cur]) {
            ans[cur]++;
            continue;
        }
        else if(cur>1) if(ans[cur-2]==ans[cur]) {
            ans[cur]++;
            continue;
        }
        break;
        
    }
    if(cur==0) if(ans[cur]>=p) {
        cout<<"NO"<<endl;
        return 0;
    }
    forn(i, cur+1, n) {
        vb let(26,true);
        if(i>0) let[ans[i-1]] = false;
        if(i>1) let[ans[i-2]] = false;
        if(let[0]) ans[i]=0;
        else if(let[1]) ans[i]=1;
        else ans[i]=2;
    }
    forn(i,0,n) cout<<(char)('a'+ans[i]);
    
    
    // cout<<ans;
}