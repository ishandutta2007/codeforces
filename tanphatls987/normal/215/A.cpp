#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string.h>
#include <math.h>
#include <deque>
#include <vector>
#include <queue>

using namespace std;

#define X first
#define Y second
#define INPUT freopen(".inp","r",stdin)
#define OUTPUT freopen(".out","w",stdout)
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define REP(i,l,r) for(int i=l;i<r;i++)
#define FORD(i,l,r) for(int i=l;i>=r;i--)
#define REPD(i,l,r) for(int i=l;i>r;i--)
#define ENDL printf("\n")
#define inf 1000000

const int MOD=1000000007;
const int N=100;

typedef long long ll;

int a[N],b[N],n,m;
void prepare(){
    cin>>n;
    FOR(i,1,n) cin>>a[i];
    cin>>m;
    FOR(i,1,m) cin>>b[i];
}
int main(){
    prepare();
    int ans=0,ct=0;
    FOR(i,1,m){
        int s=0,c1=0;
        FOR(j,1,n) if (b[i]%a[j]==0){
            int v=b[i]/a[j];
            if (v>s) s=v,c1=1;else if (v==s) c1++;
        }
        if (s>ans) ct=1,ans=s;else if (s==ans) ct++;
    }
    cout<<ct;
}