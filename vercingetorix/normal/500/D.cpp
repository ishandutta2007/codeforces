#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <stdio.h>
using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()

#define pb push_back
#define mp make_pair


int main()
{
#ifndef ONLINE_JUDGE  
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif
    int n;
    double ME;
    double ans=0;
    cin>>n;
    std::vector<pair<int, int> > edges(n);
    vector<double> edge_l(n);
    
    std::vector<std::vector<int> > ch(n+1);
    std::vector<int> par(n+1);
    std::vector<std::vector<int> > nb(n+1);
    std::vector<std::vector<int> > lvl(n+1);
    std::vector<int> v_lvl(n+1,0);

    lvl[1].push_back(1);
    v_lvl[1]=1;
    for(int i=1;i<n;i++){
        int u,v,len;
        cin >>u>>v>>len;
        edge_l[i]=(double) len;
        nb[u].push_back(v);
        nb[v].push_back(u);
        edges[i]=mp(u,v);
        //xp;
    }
    int l=2;
    int m=1;    
    
    while(m<n){
        for(int k=0; k<lvl[l-1].size(); k++){
            int v=lvl[l-1][k];
            for(int h=0; h<nb[v].size();h++){
                if(v_lvl[nb[v][h]]==0){
                    v_lvl[nb[v][h]]=l;
                    lvl[l].push_back(nb[v][h]);
                    m++;
                    ch[v].push_back(nb[v][h]);
                    par[nb[v][h]]=v;
                }
            }
        }
        l++;
    }
    l--;
    
    vi tsz(n+1, 1);
    for(int i=l-1; i>=1; i--){
        for(int j=0; j<lvl[i].size(); j++){
            int v=lvl[i][j];
            for(int k=0; k<ch[v].size(); k++) {
                tsz[v]+=tsz[ch[v][k]];
            }
        }
    }
    
    //for(int i=1; i<=n; i++) cout<<tsz[i]<<endl;
    vector<double> cn3(n+1);
    for(int i=1; i<=n; i++){
        cn3[i]=1.0*(double)(i)*(double)(i-1)*(double)(i-2) / 6.0;
    }
    for(int i=1; i<n; i++){
        int u=edges[i].first;
        int v=edges[i].second;
        int T=0;
        if(par[u]==v) T=tsz[u];
        else T=tsz[v];
        int S=n-T;
        ans+=edge_l[i]*2.0*(1-(cn3[S]+cn3[T])/cn3[n]);
    }
    
    int q,r,w;
    cin>>q;
    for(int i=0; i<q; i++){
        cin>>r>>w;
        int u=edges[r].first;
        int v=edges[r].second;
        int T=0;
        if(par[u]==v) T=tsz[u];
        else T=tsz[v];
        int S=n-T;
        double diff = edge_l[r] - w;
        ans-=diff*2.0*(1-(cn3[S]+cn3[T])/cn3[n]);
        edge_l[r]=w;
        printf("%.7f\n", ans);
    }
    //cout<<l;

}