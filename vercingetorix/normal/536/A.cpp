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

int main()
{
    #ifndef ONLINE_JUDGE  
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    #endif
    ll n,A,B;
    cin>>A>>B>>n;
    int N=2000011;
    vll h(N);
    vll sumh(N);
    ll curh=A-B;
    h[0]=0;
    sumh[0]=0;
    ll curs=0;
    for(int i=1;i<N;i++) {
        curh+=B;
        h[i]=curh;
        curs+=curh;
        sumh[i]=curs;
    }
    ll l,t,m;
    for(int i=0; i<n; i++) {
        cin>>l>>t>>m;
        ll r1 = upper_bound(all(h), t)-h.begin()-1;
        ll r2 = upper_bound(all(sumh), m*t+sumh[l-1])-sumh.begin()-1;
        ll r=min(r1,r2);
        //cout<<r1<<" "<<r2<<endl;
        if(r>=l) cout<<r<<endl;
        else cout<<-1<<endl;
    }
    
}