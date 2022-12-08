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
        //return x*y;
        return x+y;
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
    int find0(int k=0,int l=0, int r=-1){
        if(r<0)r=n;
        if(l+1==r)return k-n+1;
        if(node[2*k+1]==0)return find0(2*k+2,(l+r)/2,r);
        else return find0(2*k+1,l,(l+r)/2);
    }
    int find1(int k=0,int l=0, int r=-1){
        if(r<0)r=n;
        if(l+1==r)return k-n+1;
        if(node[2*k+1]==(r-l)/2)return find1(2*k+2,(l+r)/2,r);
        else return find1(2*k+1,l,(l+r)/2);
    }
};
int main(){
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    vector<int> v(n);
    rep(i,n)v[i]=(s[i]==1);
    SegmentTree<ll> sg(n,0);
    rep(i,n)sg.update(i, s[i]=='1');
    rep(i,n-m+1){
        if(sg.get(0,i)+sg.get(i+m,n)==0){
            cout<<"tokitsukaze"<<endl;
            return 0;
        }
        else if(sg.get(0,i)+sg.get(i+m,n)+m==n){
            cout<<"tokitsukaze"<<endl;
            return 0;
        }
    }
    bool ok=false;
    rep(i,m)sg.update(i,0);
    rep(i,n-m+1){
        sg.update(m-1+i,0);
        int idx = sg.find0();
        if(sg.get(min(idx+m,n),n)!=0)ok=true;
        sg.update(i,s[i]=='1');
    }
    rep(i,n)sg.update(i,s[i]=='1');
    rep(i,m)sg.update(i,1);
    rep(i,n-m+1){
        sg.update(m-1+i,1);
        int idx = sg.find1();
        if(idx+sg.get(min(idx+m,n),n)+m<n)ok=true;
        sg.update(i,s[i]=='1');
    }
    if(!ok){
        cout<<"quailty"<<endl;
    }
    else cout<<"once again"<<endl;
    return 0;
}