#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#include<numeric>
using namespace std;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
using ll = long long;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

using V = vector<int> ;
int m;
V f(V& x,V& y){
    V ret(m);
    rep(i,m){
        if(0<=x[i]&&x[i]<m)ret[i]=y[x[i]];
        else ret[i]=x[i];
    }
    return ret;
}

template<typename T>
struct SegmentTree{
private:
    int n;
    T E;
    vector<T> node;
    inline void updatef(T& x,T& y){
        x = y;
        //x += y;
        //x = max(x,y);
        //x = min(x,y);
    }
    inline T queryf(T& x,T& y){
        return f(x,y);
        //return x+y;
        //return max(x,y);
        //return min(x,y);
    }

public:
    SegmentTree(int sz,T E_):E(E_){
        n=1;
        while(n<sz)n<<=1;
        node.resize(2*n-1,E);
    }

    SegmentTree(vector<T>& A,T E_):E(E_){
        int sz=A.size();
        n=1;
        while(n<sz)n<<=1;
        node.resize(2*n-1,E);
        rep(i,sz)node[i+n-1]=A[i];
        for(int i=n-2;i>=0;--i){
            node[i]=queryf(node[2*i+1], node[2*i+2]);
        }
    }
    void update(int k,T x){
        k+=n-1;
        updatef(node[k],x);
        while(k>0){
            k=(k-1)/2;
            node[k]=queryf(node[2*k+1], node[2*k+2]);
        }
    }
       //[a,b)
    T get(int a,int b,int k=0,int l=0,int r=-1){
        if(r<0)r=n;
        if(r<=a||b<=l)return E;
        if(a<=l&&r<=b)return node[k];
        T xl=get(a,b,2*k+1,l,(l+r)/2);
        T xr=get(a,b,2*k+2,(l+r)/2,r);
        return queryf(xl, xr);
    }
};

int dfs(int x,string& s,vector<int>& ans, vector<int> used){
    if(x<0||x>=m)return x;
    if(used[x]==1)return ans[x];
    if(used[x]==2) {
        used[x]=1;return ans[x]=inf;
    }
    used[x]=2;
    int ret=-1;
    if(s[x]=='<')ret=dfs(x-1,s,ans,used);
    if(s[x]=='>')ret=dfs(x+1,s,ans,used);
    if(s[x]=='^')ret=x;
    used[x]=1;
    return ans[x]=ret;
}
int main(){
    int n, q;
    cin>>n>>m>>q;
    string s[n];
    rep(i,n)cin>>s[i];
    reverse(s,s+n);
    vector<vector<int>> data(n,vector<int>(m));
    rep(i,n){
        vector<int> used(m);
        rep(j,m)dfs(j,s[i],data[i],used);
        rep(j,m){
            if(data[i][j]<0)data[i][j]-=i;
            else if(data[i][j]==m)data[i][j]+=i;
        }
    }
    V E(m);
    iota(E.begin(),E.end(),0);
    SegmentTree<V> sg(data,E);
    while(q--){
        char t;
        cin>>t;
        if(t=='A'){
            int x,y;
            cin>>x>>y;
            x=n-x;
            --y;
            int res = sg.get(x,n)[y];
            if(res==inf){
                cout<<"-1 -1"<<"\n";
            }
            else if(res>=m){
                cout<<(n-res+m)<<" "<<m+1<<"\n";
            }
            else if(res<0){
                cout<<(n+1+res)<<" "<<0<<"\n";
            }
            else {
                cout<<0<<" "<<res+1<<"\n";
            }
        }
        else {
            int x,y;
            cin>>x>>y;
            x=n-x;
            --y;
            char c;
            cin>>c;
            s[x][y]=c;
            vector<int> nv(m);
            vector<int> used(m);
            rep(i,m)dfs(i,s[x],nv,used);
            rep(j,m){
                if(nv[j]<0)nv[j]-=x;
                else if(nv[j]==m)nv[j]+=x;
            }
            sg.update(x,nv);
        }
    }
    return 0;
}