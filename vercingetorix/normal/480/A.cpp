#include <iostream>
#include <math.h>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int>> vvi;
typedef std::vector<std::vector<long long>> vvll;

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
  
int n,x,y;
ll ans=0;
cin>>n;
vi a;
vi b;
std::vector<pair<int,int>> ex;
for(int i=0; i<n; i++){
    cin>>x>>y;
    ex.pb(mp(x,y));
}
sort(all(ex));
//std::reverse(all(ex));
int minnd=0;
int curd=0;
for(int i=0; i<ex.size(); i++){
    if(i>0) if(ex[i].first!=ex[i-1].first) {
        curd=minnd;
    }
    if(ex[i].second>=curd){
        curd=ex[i].second;
        minnd=max(curd,minnd);
    }
    else{
        minnd=ex[i].first;
    }
}

cout<<minnd;

 return 0;
}