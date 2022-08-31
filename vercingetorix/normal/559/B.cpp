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
    string s1, s2;
    //for(int i=0; i<n; i++)
    cin>>s1>>s2;
    if(s1.length()!=s2.length()) {
        cout<<"NO";
        return 0;
    }
    int l=s1.length();
    int lp=l;
    int deg=0;
    int p2=1;
    while(lp%2==0){
        lp/=2;
        deg++;
        p2*=2;
    }
    vector<pair<string, int>> ss1, ss2;
    for(int i=0; i<p2; i++) {
        ss1.pb(mp(s1.substr(i*lp, lp), i));
        ss2.pb(mp(s2.substr(i*lp, lp), i));
    }
    sort(all(ss1));
    sort(all(ss2));
    vi si1(p2), si2(p2);
    int curind=1;
    for(int i=0; i<p2; i++) {
        if(ss1[i].first!=ss2[i].first) {
            cout<<"NO";
            return 0;
        }
        if((i>0)&&(ss1[i].first!=ss1[i-1].first)) curind++;
        si1[ss1[i].second]=curind;
        si2[ss2[i].second]=curind;
    }
    int allp2=p2;
    //for(int i=0; i<p2; i++) if(si1[i]=si2[i]) cureq[i]=true;
    for(int j=0; j<deg; j++) {
        p2/=2;
        curind=0;
        vi newsi1(p2), newsi2(p2);
        map<pi, int> newind;
        //vb neweq(p2, false);
        for(int i=0; i<p2; i++) {
            int a=si1[2*i];
            int b=si1[2*i+1];
            if(a>b) swap(a,b);
            if(newind[mp(a,b)]==0) {
                curind++;
                newind[mp(a,b)] = curind;
            }
            newsi1[i]=newind[mp(a,b)];
            a=si2[2*i];
            b=si2[2*i+1];
            if(a>b) swap(a,b);
            if(newind[mp(a,b)]==0) {
                curind++;
                newind[mp(a,b)] = curind;
            }
            newsi2[i]=newind[mp(a,b)];
        }
        si1=newsi1;
        si2=newsi2;
    }
    if(si1[0]==si2[0]) cout<<"YES";
    else cout<<"NO";
    return 0;
}