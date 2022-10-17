#include <map>
#include <set>
#include <stack>
#include <queue>
#include <cmath>
#include <cstdio>
#include <string>
#include <vector>
#include <climits>
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <complex>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define rep(it,st,en) for(int it=(st);it<(int)(en);++it)
#define trav(it,c) for(auto it=(c).begin();it!=(c).end();++it)
#define allof(c) (c).begin(), (c).end()
#define pb push_back
#define mp make_pair
#define X first
#define Y second
typedef long long int ll; 
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> pii;
const int INF=(int)1e9; 
const double EPS=(ld)1e-7;

int p[100009];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    rep(i,0,n)cin>>p[i], --p[i];
    int par=-1;
    vi vis(n,0);
    rep(i,0,n) if(p[i]==i){
        cout<<"YES"<<endl;
        rep(j,0,n)if(j!=i){
            cout<<i+1<<" "<<j+1<<endl;
        }
        return 0;
    }
    rep(i,0,n){
        if(vis[i])continue;
        int l=1,j=p[i]; vis[i]=1;
        while(j!=i)l++,vis[j]=1,j=p[j];
        if(l==2)par=i;
        if(l&1){
            cout<<"NO"<<endl;
            return 0;
        }
    }
    if(par==-1){cout<<"NO"<<endl;return 0;}
    vis[par]=vis[p[par]]=0;
    cout<<"YES"<<endl;
    cout<<par+1<<" "<<p[par]+1<<endl;
    rep(i,0,n){
        if(!vis[i])continue;
        int j=i,l=0;
        do{
            vis[j]=0;
            cout<<j+1<<" "<<((l%2==0)?par:p[par])+1<<endl;
            j=p[j]; l++;
        } while(i!=j);
    }
    return 0;
}