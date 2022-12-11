#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string.h>
#include <math.h>
#include <deque>
#include <vector>
#include <queue>
#include <stack>

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
const int N=710;

typedef long long ll;

string s;
int n,t[N];
stack <int> st;
struct node{
    ll f[3][3];
    void init(){
        FOR(i,1,2) f[i][0]=f[0][i]=1;
    }
    node(){
        memset(f,0,sizeof(f));
    }
    void mergein(node t){
        FOR(i,0,2)
            FOR(j,0,2) if ((i==0||j==0)&&i!=j)
                FOR(i1,0,2) FOR(j1,0,2) if ((i1!=i||i1+i==0)&&(j1!=j||j1+j==0))
        f[i][j]=(f[i][j]+t.f[i1][j1])%MOD;
    }
    void mergenear(node x,node y){
        FOR(i,0,2)
            FOR(j,0,2)
                FOR(i1,0,2)
                    FOR(j1,0,2) if (i1!=j1||i1+j1==0)
            f[i][j]=(f[i][j]+(x.f[i][i1]*y.f[j1][j])%MOD)%MOD;
    }
};
node DAC(int l,int r){
    node tmp;
    if (t[l]==r){
        if (l==r-1) tmp.init();
        else tmp.mergein(DAC(l+1,r-1));
    }else tmp.mergenear(DAC(l,t[l]),DAC(t[l]+1,r));
    return tmp;
}
void prepare(){
    cin>>s;
    n=s.length();
}
void solve(){
    FOR(i,1,n) if (s[i-1]=='(') st.push(i);
    else t[i]=st.top(),st.pop(),t[t[i]]=i;
    //FOR(i,1,n) printf("%d ",t[i]);
    node ans=DAC(1,n);
    //FOR(i,0,2)
        //{FOR(j,0,2) printf("%d ",ans.f[i][j]);ENDL;}
    ll way=0;
    FOR(i,0,2) FOR(j,0,2) way=(way+ans.f[i][j])%MOD;
    cout<<way;
}
int main(){
    prepare();
    solve();
}