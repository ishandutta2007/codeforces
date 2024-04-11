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

template<int char_size, int margin>
struct Trie{
    struct Node{
        int cnt;
        vector<int> idx; 
        Node *ch[char_size +1]={};

        Node():cnt(0){}
    };
    Node* root;

    Trie():root(nullptr){}

    Node* insert(Node* t,string &str,int str_index,int id,int& ret){
        if(!t){
            t=new Node;
        }
        t->cnt+=1;
        if(t->cnt==1)ret=min(ret,str_index);
        if(str_index==str.size()){
            t->idx.push_back(id);
            return t;
        }
        int c=str[str_index]-margin;
        t->ch[c]=insert(t->ch[c],str,str_index+1,id,ret);
        return t;
    }

    int insert(string &str,int id){
        int ret=inf;
        root=insert(root,str,0,id,ret);
        return ret;
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
};

ll dp[3030][3030];
int main(){
    int n;
    cin>>n;
    string str;
    Trie<2,'0'> tr;
    tr.insert(str,0);
    dp[0][0]=1;
    ll ans=0;
    rep(i,n){
        char x;
        cin>>x;
        str=x+str;
        int ret=tr.insert(str,0);
        ret=i-ret+1;
        rep(j,4){
            if(j>i)continue;
            if(j==3){
                string sub=str.substr(0, 4);
                if(sub=="1111"||sub=="0111"||sub=="1010"||sub=="1100")continue;
            }

            rep(k,i+1){
                (dp[i+1][k]+=dp[i-j][k])%=mod;
            }
        }
        rep(j,ret+1){
            ans+=dp[i+1][j];
        }
        ans%=mod;
        cout<<ans<<endl;
        dp[i+1][i+1]=1;
    }
    return 0;
}