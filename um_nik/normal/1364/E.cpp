/*

  _|_|                              _|  _|    _|
_|    _|  _|  _|_|  _|_|_|_|        _|  _|  _|
_|    _|  _|_|          _|          _|  _|_|
_|    _|  _|          _|      _|    _|  _|  _|
  _|_|    _|        _|_|_|_|    _|_|    _|    _|

*/
#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<vector>
#include<queue>
#include<set>
#include<random>
//#define ls (rt<<1)
//#define rs (rt<<1|1)
#define vi vector<int>
#define pb push_back//
#define mk make_pair
#define pii pair<int,int>
#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;i++)
#define fi first
#define se second
typedef long long ll;
using namespace std;
mt19937 Rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
int n;
vi idx,re;//0
const int maxn=5000;
int tmp[maxn];
int ans[maxn];
int mem[maxn][maxn];
int query(int x,int y){
    if(mem[x][y]!=-1)return mem[x][y];int val;
    cout<<"? "<<x<<' '<<y<<endl;cout.flush();cin>>val;
    mem[x][y]=mem[y][x]=val;
    return val;
}
int get_0(){
    rep(i,1,n)idx.pb(i);
    while(1){
        int id_q=Rnd()%idx.size();
        int x=idx[id_q],mi=maxn;
        for(int i=0;i<idx.size();i++){
            if(i==id_q)continue;
            tmp[i]=query(idx[i],idx[id_q]);
            mi=min(mi,tmp[i]);
            if(tmp[i]==-1){while(1);return 0;}
        }
        re.clear();//xor
        for(int i=0;i<idx.size();i++){
            if(i==id_q)continue;
            if(tmp[i]==mi)re.pb(idx[i]);
        }
        if(re.size()>=2){idx=re;continue;}
        else{
            int st1=re[0],st2=x;
            while(1){
                int tmp_id=st1;while(tmp_id==st1||tmp_id==st2)tmp_id=Rnd()%n+1;
                int val1,val2;
                val1=query(st1,tmp_id),val2=query(st2,tmp_id);
                if(val1==-1){while(1);return 0;}
                if(val2==-1){while(1);return 0;}
                if(val1==val2)continue;
                if(val1<val2)return st1;
                else return st2;
            }
        }
    }
}
int main(){
    memset(mem,-1,sizeof(mem));
    ios::sync_with_stdio(0);
    cin>>n;int id_0=get_0();
    rep(i,1,n){
        if(i==id_0)continue;
        else {
            int val=query(id_0,i);
            if(val==-1){while(1);return 0;}
            ans[i]=val;
        }
    }
    cout<<"! ";
    rep(i,1,n)cout<<ans[i]<<' '; // www
    return 0;
}