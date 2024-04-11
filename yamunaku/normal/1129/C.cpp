#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define repe(i,n) rep(i,(n)+1)
#define per(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define pere(i,n) rep(i,(n)+1)
#define all(x) (x).begin(),(x).end()
#define SP <<" "<<
#define MOD 1000000007
#define IINF 1000000000
#define LINF 1000000000000000000

typedef long long LL;
typedef long double LD;

class Trie{
private:
  struct node{
    node* l=NULL;
    node* r=NULL;
    LL dp=0;
  };
  node* root;
  LL ans=0;

public:
  Trie(){
    root=new node;
    root->dp=1;
  }
  void add(string &s){
    node* now=root;
    vector<int> tmp(4,0);
    tmp[3]=1;
    string tmps="****";
    char c;
    for(int i=s.length()-1;i>=0;i--){
      // cout << tmps << endl;
      bool upd=false;
      if(s[i]=='0'){
        if(now->l==NULL){
          now->l=new node;
          upd=true;
        }
        now=now->l;
        c='0';
      }else{
        if(now->r==NULL){
          now->r=new node;
          upd=true;
        }
        now=now->r;
        c='1';
      }
      for(int j=0;j<3;j++){
        tmps[j]=tmps[j+1];
      }
      tmps[3]=c;
      if(upd){
        for(int j=1;j<4;j++){
          now->dp=(now->dp+tmp[j])%MOD;
        }
        if(tmps!="1100"&&tmps!="1010"&&tmps!="0111"&&tmps!="1111"){
          now->dp=(now->dp+tmp[0])%MOD;
        }
        ans=(ans+now->dp)%MOD;
      }
      for(int j=0;j<3;j++){
        tmp[j]=tmp[j+1];
      }
      tmp[3]=now->dp;
    }
  }
  LL query(){
    return ans;
  }
};

int main(){
  int n;
  cin >> n;
  char c;
  string s;
  Trie solve;
  for(int i=0;i<n;i++){
    cin >> c;
    s.push_back(c);
    solve.add(s);
    cout << solve.query() << endl;
  }
  return 0;
}