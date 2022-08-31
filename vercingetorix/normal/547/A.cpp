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
    ll m,h1,h2,a1,a2,x1,x2,y1,y2;
    cin >> m;
    cin>>h1>>a1;
    cin>>x1>>y1;
    cin>>h2>>a2;
    cin>>x2>>y2;
    ll t=0;
    vi xan(1000002, -1);
    vi abol(1000002, -1);
    xan[h1]=0;
    abol[h2]=0;
    ll curh=h1;
    ll xenc=-1;
    ll xpers, xperl;
    ll aenc=-1;
    ll apers, aperl;
    while(1){
        t++;
        curh = (x1*curh+y1)%m;
        if(curh==a1) {
            if(xenc==-1) xenc=t;
        }
        if(xan[curh]>=0) {
            xpers = xan[curh];
            xperl=t-xan[curh];
            break;
        }
        xan[curh]=t;
    }
    curh=h2;
    t=0;
    while(1){
        t++;
        curh = (x2*curh+y2)%m;
        if(curh==a2) {
            if(aenc==-1) aenc=t;
        }
        if(abol[curh]>=0) {
            apers = abol[curh];
            aperl=t-abol[curh];
            break;
        }
        abol[curh]=t;
    }
    if((xenc<0) || (aenc<0)){
        cout<<-1;
        return 0;
    }
    if(xenc<xpers){
        curh=h2;
        for(int i=0; i<xenc; i++){
            curh = (x2*curh+y2)%m;
        }
        cout<<((curh==a2)? xenc : -1);
        return 0;
    }
    if(aenc<apers){
        curh=h1;
        for(int i=0; i<aenc; i++){
            curh = (x1*curh+y1)%m;
        }
        cout<<((curh==a1)? aenc : -1);
        return 0;
    }
    t=xenc;
    while(t<aenc) t+=xperl;
    for(int i=0; i<aperl+1; i++) {
        if(t>=aenc){
            if(((t-aenc)%aperl)==0) {
                cout<<t;
                return 0;
            }
        }
        t+=xperl;
    }
    cout<<-1;
    return 0;
}