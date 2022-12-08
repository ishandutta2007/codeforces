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
using namespace std;
#define REP(i,m,n) for(int i=(int)m ; i < (int) n ; ++i )
#define rep(i,n) REP(i,0,n)
typedef long long ll;
typedef pair<int,int> pint;
typedef pair<ll,int> pli;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

template<typename T = unsigned int, int B=32>
struct BinaryTrie{
private:
    struct Node{
        int cnt;
        T lazy;
        Node *ch[2]={};

        Node():cnt(0),lazy(0){}
    };

    Node* root;

    int size(Node *t){return t?t->cnt:0 ;}

    void eval(Node* t,int bit_index){
        if(!t->lazy)return;
        if(t->lazy>>bit_index&1)swap(t->ch[0],t->ch[1]);
        if(t->ch[0])t->ch[0]->lazy^=t->lazy;
        if(t->ch[1])t->ch[1]->lazy^=t->lazy;
        t->lazy = 0;
    }

    Node* insert(Node* t,T n,int bit_index){
        if(!t)t=new Node;
        t->cnt+=1;
        if(bit_index==-1)return t;
        eval(t,bit_index);
        bool c=(n>>bit_index)&1;
        t->ch[c]=insert(t->ch[c],n,bit_index-1);
        return t;
    }

    Node* erase(Node* t,T n,int bit_index){
        //assert(t);
        t->cnt-=1;
        if(!t->cnt)return nullptr;
        if(bit_index==-1)return t;
        eval(t,bit_index);
        bool c=(n>>bit_index)&1;
        t->ch[c]=erase(t->ch[c],n,bit_index-1);
        return t;
    }

    T get_min(Node* t,T n,int bit_index){
        //assert(t);
        if(bit_index<0)return 0;
        eval(t,bit_index);
        bool c=(n>>bit_index)&1;
        T ret=0;
        if(!t->ch[c])c^=1;
        return get_min(t->ch[c],n,bit_index-1)|((T)c<<bit_index);
    }
    
    T get(Node* t,T n,int k,int bit_index){
        //assert(t&&t->cnt<=k);
        if(bit_index<0)return 0;
        eval(t,bit_index);
        bool c=(n>>bit_index)&1;
        if(size(t->ch[c])<k)k-=size(t->ch[c]),c^=1;
        return get(t->ch[c],n,k,bit_index-1)|((T)c<<bit_index);
    }

    int count_lower(Node* t,T n,T val,int bit_index){
        if(!t||bit_index<0)return 0;
        eval(t,bit_index);
        bool c=(n>>bit_index)&1;
        int ret=0;
        if((val>>bit_index)&1)ret+=size(t->ch[c]),c^=1;
        return ret+count_lower(t->ch[c],n,val,bit_index-1);
    }

public:
    BinaryTrie():root(nullptr){}

    int size(){
        return size(root);
    }

    bool empty(){
        return !root;
    }

    void insert(T n){
        root=insert(root,n,B-1);

    }

    void erase(T n){
        root=erase(root,n,B-1);
    }

    void xor_all(T n){
        if(root) root->lazy^=n;
    }

    T max_element(T bias = 0){
        return get_min(root,~bias,B-1);
    }

    T min_element(T bias = 0){
        return get_min(root,bias,B-1);
    }

    int lower_bound(T x,T bias = 0){
        return count_lower(root,bias,x,B-1);
    }

    int upper_bound(T x,T bias = 0){
        return count_lower(root,bias,x+1,B-1);
    }

    int count(T x){
        return upper_bound(x)-lower_bound(x);
    }

    T get(int k,T bias = 0){
        //assert(0<=k&&k<size());
        return get(root,bias,k+1,B-1);
    }

    T operator[](int k){
        return get(k);
    }
};


int main(){
    int n;cin>>n;
    BinaryTrie<> bt;
    int x[n];
    rep(i,n)scanf("%d",&x[i]);
    rep(i,n){
        int y;
        scanf("%d",&y);
        bt.insert(y);
    }
    rep(i,n){
        bt.xor_all(x[i]);
        int ret=bt.min_element();
        printf("%d ",ret);
        bt.erase(ret);
        bt.xor_all(x[i]);
    }
}