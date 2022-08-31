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


vll la(26,0);
vll lb(26,0);
vll lc(26,0);

ll getans(ll i) {
    ll m=1000000;
    bool f=true;
    for(int j=0; j<26; j++) {
        if(la[j]<lb[j]*i) f=false;
    }
    if(!f) return 0;
    for(int j=0; j<26; j++) {
        if(lc[j]>0) m=min(m,(la[j]-lb[j]*i)/lc[j]);
    }
    return i+m;
}

int main()
{
    #ifndef ONLINE_JUDGE  
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    #endif
    int n,k;
    //cin>>n>>k;
    //for(int i=0; i<n; i++) 
    string a,b,c;
   
    cin>>a>>b>>c;
    for(int i=0; i<a.length(); i++) la[a[i]-'a']++;
    for(int i=0; i<b.length(); i++) lb[b[i]-'a']++;
    for(int i=0; i<c.length(); i++) lc[c[i]-'a']++;
    int ans=0;
    int aans=0;
    int l=0;
    int r=100000;
    int vl=getans(l);
    int vr=getans(r);
    while((r-l)>2){
        int l1=l+(r-l)/3;
        int r1=r-(r-l)/3;
        int vl1=getans(l1);
        int vl2=getans(r1);
        if(vl1>=vl2) {
            r=r1;
        }
        else {
            l=l1;
        }
    }
    for(int i=l; i<=r; i++) {
        int v=getans(i);
        if(v>ans){
            ans=v;
            aans=i;
        }
    }
    string answer;
    for(int i=0;i<aans; i++) for(int j=0; j<b.size(); j++) answer.pb(b[j]);
    for(int i=0;i<ans-aans; i++) for(int j=0; j<c.size(); j++) answer.pb(c[j]);
    for(int j=0; j<26; j++) {
        la[j]-=aans*lb[j]+(ans-aans)*lc[j];
    }
    for(int j=0; j<26; j++) {
        for(int k=0; k<la[j]; k++) answer.pb('a'+j);
    }
    cout<<answer;
}