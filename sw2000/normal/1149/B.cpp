#include<bits/stdc++.h>
using namespace std;
#define K(x...){cerr<<"BEGIN     "<<#x<<"->";Err(x);cerr<<"   END"<<endl;}
void Err(){}
template<class T,class... A>void Err(T a,A... x){cerr<<a<<',';Err(x...);}
template<class X,class Y,class...A>void Err(pair<X,Y> a,A... x){cerr<<'('<<a.first<<','<<a.second<<')';Err(x...);}
template<template<class...> class T,class t,class...A>void Err(T<t>a,A...x){cerr<<a.size()<<":{";for(auto v:a)Err(v);cerr<<"}";Err(x...);}
typedef long long ll;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll rnd(ll l,ll r){return uniform_int_distribution<ll>(l,r)(rng);}
template<class T>void Min(T &a,const T b){if(a>b)a=b;}
template<class T>void Max(T &a,const T b){if(a<b)a=b;}
#define fi first
#define se second
#define lo (o<<1)
#define ro (o<<1|1)
#define mid (l+r>>1)
#define endl '\n'
#ifdef ONLINE_JUDGE
#define freopen(a,b,c)
#define K(a...)
#endif
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
typedef vector<int>vi;
typedef vector<ll>vl;
const ll linf=0x3f3f3f3f3f3f3f3f;
const int inf=0x3f3f3f3f;
const int N=250+10;
const ll mod=998244353;

int f[N][N][N];
char s[100010];
char t[3][N];
int l[3];
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("A.in","r",stdin);
    int n,q;cin>>n>>q;
    cin>>s+1;
    vi pos[26];
    for(int i=1;i<=n;i++){
        pos[s[i]-'a'].push_back(i);
    }
    while(q--){
        char op;cin>>op;
        int id;cin>>id;id--;
        if(op=='+'){
            char c;cin>>c;
            t[id][++l[id]]=c;
            c-='a';
            if(id==0){
                for(int i=0;i<=l[1];i++){
                    for(int j=0;j<=l[2];j++){
                        auto it=upper_bound(pos[c].begin(),pos[c].end(),f[l[id]-1][i][j]);
                        if(it==pos[c].end())f[l[id]][i][j]=inf;
                        else f[l[id]][i][j]=*it;
                        if(i){
                            int cc=t[1][i]-'a';
                            it=upper_bound(pos[cc].begin(),pos[cc].end(),f[l[id]][i-1][j]);
                            Min(f[l[id]][i][j],it==pos[cc].end()?inf:*it);
                        }
                        if(j){
                            int cc=t[2][j]-'a';
                            it=upper_bound(pos[cc].begin(),pos[cc].end(),f[l[id]][i][j-1]);
                            Min(f[l[id]][i][j],it==pos[cc].end()?inf:*it);
                        }
                    }
                }
            }
            if(id==1){
                for(int i=0;i<=l[0];i++){
                    for(int j=0;j<=l[2];j++){
                        auto it=upper_bound(pos[c].begin(),pos[c].end(),f[i][l[id]-1][j]);
                        if(it==pos[c].end())f[i][l[id]][j]=inf;
                        else f[i][l[id]][j]=*it;
                        if(i){
                            int cc=t[0][i]-'a';
                            it=upper_bound(pos[cc].begin(),pos[cc].end(),f[i-1][l[id]][j]);
                            Min(f[i][l[id]][j],it==pos[cc].end()?inf:*it);
                        }
                        if(j){
                            int cc=t[2][j]-'a';
                            it=upper_bound(pos[cc].begin(),pos[cc].end(),f[i][l[id]][j-1]);
                            Min(f[i][l[id]][j],it==pos[cc].end()?inf:*it);
                        }
                    }
                }
            }
            if(id==2){
                for(int i=0;i<=l[0];i++){
                    for(int j=0;j<=l[1];j++){
                        auto it=upper_bound(pos[c].begin(),pos[c].end(),f[i][j][l[id]-1]);
                        if(it==pos[c].end())f[i][j][l[id]]=inf;
                        else f[i][j][l[id]]=*it;
                        if(i){
                            int cc=t[0][i]-'a';
                            it=upper_bound(pos[cc].begin(),pos[cc].end(),f[i-1][j][l[id]]);
                            Min(f[i][j][l[id]],it==pos[cc].end()?inf:*it);
                        }
                        if(j){
                            int cc=t[1][j]-'a';
                            it=upper_bound(pos[cc].begin(),pos[cc].end(),f[i][j-1][l[id]]);
                            Min(f[i][j][l[id]],it==pos[cc].end()?inf:*it);
                        }
                    }
                }
            }
        }
        else{
            l[id]--;
        }
        cout<<(f[l[0]][l[1]][l[2]]==inf?"NO":"YES")<<endl;
    }
    for(int i=0;i<=l[0];i++){
        for(int j=0;j<=l[1];j++){
            for(int k=0;k<=l[2];k++){
                K(i,j,k,f[i][j][k])
            }
        }
    }
}