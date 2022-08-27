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

ll lllabs(ll n){
    if(n<0) return -n;
    return n;
}

int main()
{
#ifndef ONLINE_JUDGE  
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif
    int n;

    cin>>n;
    vll a(n);
    for(int i=0; i<n; i++) cin>>a[i];
    vb l(n, false);
    vb r(n, false);
    vi peak(n, 0);
    r[n-1]=true;
    l[0]=true;
    for(int i=1; i<n-1; i++){
        
        if((a[i]>=a[i-1])&&(a[i]>=a[i+1])){
            peak[i]=1;
        }
        if((a[i]<=a[i-1])&&(a[i]<=a[i+1])){
            peak[i]=-1;
        }
    }
    //cout<<l;
    long long ansp=0, ansp1=0;
    int pos=0;
    peak[n-1]=true;
    while(pos<n-1){
        int prevpos=pos;
        pos++;
        while(peak[pos]==0) pos++;
        ll prevansp1=ansp1;
        ll prevansp=ansp;
        ansp1=ansp1+lllabs(a[pos-1]-a[prevpos]);
        if(prevansp>ansp1) ansp1=prevansp;
        if((pos-prevpos>1)&&(prevansp+lllabs(a[pos-1]-a[prevpos+1])>ansp1)) ansp1=prevansp+lllabs(a[pos-1]-a[prevpos+1]);
        ansp=prevansp1+lllabs(a[pos]-a[prevpos]);
        if(ansp<prevansp+lllabs(a[pos]-a[prevpos+1])) ansp=prevansp+lllabs(a[pos]-a[prevpos+1]);
    }
    cout<<ansp;
}