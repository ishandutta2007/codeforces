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
using namespace std;
#define REP(i,m,n) for(int i=(int)m ; i < (int) n ; ++i )
#define rep(i,n) REP(i,0,n)
typedef long long ll;
typedef pair<int,int> pint;
typedef pair<ll,int> pli;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

template<int char_size, int margin>
struct Trie{
    struct Node{
        int cnt;
        vector<int> idx; 
        Node *ch[char_size +1]={};

        Node():cnt(0){}
    };
    Node* root;
    int sz;
    Trie():sz(1){root = new Node;root->cnt=1;}
    int size(){return sz;}
    Node* insert(Node* t, Node* u){
        if(!u)return t;
        if(!t)++sz,t=new Node;
        t->cnt+=1;
        rep(c,char_size){
            t->ch[c]=insert(t->ch[c],u->ch[c]);
        }
        return t;
    }

    Node* erase(Node* t, Node* u){
        if(!u)return t;
        rep(c,char_size){
            t->ch[c]=erase(t->ch[c],u->ch[c]);
        }
        if(--t->cnt==0){
            --sz;
            delete t;
            return nullptr;
        }
        return t;
    }
    int insert(Trie trie){
        root = insert(root,trie.root);
        return sz;
    }
    void erase(Trie trie){
        root = erase(root,trie.root);
    }
    void add(char c,Trie trie){
        if(!root)++sz,root = new Node;
        root->cnt+=1;
        int x=c-margin;
        assert(!root->ch[x]);
        root->ch[x]=trie.root;
        sz += trie.size();
    }
    void query(Node* t,const function< void(int) > &f,string &str,int string_index){
        if(!t)return;
        for(auto &id:t->idx) f(id);
        if(string_index==str.size())return ;
        int c=str[string_index]-margin;
        query(t->ch[c],f,str,string_index+1);
    }

    void query(const function< void(int) > &f,string &str,int str_index=0){
        query(root,f,str,str_index);
    }
    void output(Node* t){
        if(!t)return;
        rep(i,26){
            if(t->ch[i]){
                cout<<(char)('a'+i);
                cout<<"(";
                output(t->ch[i]);
                cout<<") ";
            }
        }
    }
    void output(){
        output(root);
        cout<<endl;
    }
};
vector<vector<pair<int,char>>> v(505050);

using T = Trie<26,'a'>;
vector<T> trie(505050);
vector<int> ans(505050);
vector<int> cnt(303030);
int szdfs(int x){
    cnt[x]=1;
    for(auto to : v[x]){
        cnt[x]+=szdfs(to.first);
    }
    sort(v[x].begin(),v[x].end(),[&](auto  s, auto t){
        return cnt[s.first]>cnt[t.first];
    });
    return cnt[x];
}
void dfs(int x, int p,int d){
    T ret;
    T marge;
    if(v[x].empty())return;
    for(auto to:v[x]){
        dfs(to.first,x,d+1);
    }
    for(auto to:v[x]){
        if(to==v[x][0])marge=trie[to.first];
        else marge.insert(trie[to.first]);
    }
    int m = marge.size();
    for(auto to:v[x]){
        if(to==v[x][0])continue;
        else marge.erase(trie[to.first]);
    }
    for(auto to:v[x]){
        ret.add(to.second,trie[to.first]);
    }
    ans[d]+=ret.size()-m;
    trie[x]=ret;
    //ret.output();
}

int main(){
    int n;
    cin>>n;
    rep(i,n-1){
        int x,y;char z;
        scanf("%d %d %c",&x,&y,&z);
        --x;--y;
        v[x].emplace_back(y,z);
    }
    szdfs(0);
    dfs(0,-1,1);
    int mi=0,ret=-1;
    rep(i,n+1){
        if(ret<ans[i+1]){
            ret=ans[i+1];
            mi=i+1;
        }
    }
    cout<<n-ret<<endl;
    cout<<mi<<endl;
    return 0;
}