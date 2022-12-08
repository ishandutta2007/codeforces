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
typedef long long ll;
typedef pair<int,int> pint;
typedef pair<ll,int> pli;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

template<typename T>
struct SegmentTree{
private:
    int n;
    T E;
    vector<T> node;
    inline void updatef(T& x,T& y){
        //x = y;
        //x += y;
        //x = max(x,y);
        //x = min(x,y);
    }
    inline T queryf(T& x,T& y){
        //return x*y;
        //return x+y;
        //return max(x,y);
        return min(x,y);
    }

public:
    SegmentTree(int sz,T& E_):E(E_){
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

int nxt[20][202020];
int main(){
    int n,m,q;
    cin>>n>>m>>q;
    int a[n];
    int idx[n];
    rep(i,n){
        cin>>a[i];
        --a[i];
        idx[a[i]]=i;
    }
    int b[m];
    rep(i,m){
        cin>>b[i];
        --b[i];
    }
    vector<int> tmp(n,-1);
    for(int i=m-1;i>=0;i--){
        int id=idx[b[i]];
        int nx=a[(id+1)%n];
        nxt[0][i]=tmp[nx];
        tmp[b[i]]=i;
    }
    rep(i,19){
        rep(j,m){
            if(nxt[i][j]<0)nxt[i+1][j]=-1;
            else nxt[i+1][j]=nxt[i][nxt[i][j]];
        }
    }
    vector<int> ret(m);
    --n;
    rep(i,m){
        int cur=i;
        rep(j,19){
            if((n&(1<<j))&&cur!=-1)cur=nxt[j][cur];
        }
        ret[i]=(cur==-1?inf : cur);
    }
    SegmentTree<int> sg(ret,inf);
    string ans="";
    while(q--){
        int l,r;
        scanf("%d%d",&l,&r);
        --l;
        int res=sg.get(l,r);
        if(res<r)ans+='1';
        else ans+='0';
    }
    cout<<ans<<endl;
    return 0;
}