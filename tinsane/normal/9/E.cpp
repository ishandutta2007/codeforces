#include <stdio.h>
#include <fstream>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <deque>
#include <math.h>
#include <iomanip>
#include<map>
#include <string>
#include<list>
#include<stack>
#include<algorithm>
#include <queue>
#include <time.h>
#include<functional>
#include<set>
using namespace std;

#define PI 3.14159265358979323846
#define MIN(a,b) ((a>b)? b : a)
#define MAX(a,b) ((a<b)? b : a)
#define MOD(a) ((a>0)? a : -a)
#define ll long long
#define ld long double
#define STR string
#define MAXINT 1000000010
#define MAXLL 1000000000000000000
#define PII pair<int,int> 
#define VI vector<int> 
#define VVI vector<vector<int>> 
#define _10POW9PLUS7 1000000007 
//  8739
#pragma comment(linker, "/STACK:167772160")
VI edges[51];
vector<PII> ans;
int anc[51],n,m,x,y, wsi(1), wave[50], cou(0), fro,to, sran[51];

int finds(int v){
    return (v==anc[v]? v : (anc[v]=finds(anc[v])));
}

void unite(int x, int y){
    x=finds(x);
    y=finds(y);
    if(x==y)
        return;
    if(sran[y]>sran[x])
        swap(x,y);
    sran[x]+=sran[y];
    anc[y]=x;
}

int main(){
    cin>>n>>m;
    if(m>n){
        cout<<"NO";
        return 0;
    }
    if(n==1){
        if(m==0)
            cout<<"YES\n1\n1 1";
        else
            cout<<"YES\n0";
        return 0;
    }
    else if(n==2){
        if(m==0)
            cout<<"YES\n2\n1 2\n1 2";
        else if(m==1){
            cin>>x>>y;
            if(x==y)
                cout<<"NO";
            else
                cout<<"YES\n1\n1 2";
        }
        else{
            cin>>x>>y;
            if(x==y)
                cout<<"NO";
            else{
                cin>>x>>y;
                if(x==y)
                    cout<<"NO";
                else
                    cout<<"YES\n0";
            }
        }
        return 0;

    }
    for(;m;--m){
        cin>>x>>y;
        if(x==y){
            cout<<"NO";
            return 0;
        }
        for(int i(0);i<edges[x].size();++i)
            if(edges[x][i]==y){
                cout<<"NO";
                return 0;
            };
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    for(int i(1);i<=n;++i){
        anc[i]=0;
        cou+=edges[i].size();
        if(edges[i].size()>2){
            cout<<"NO";
            return 0;
        };
    }
    cou>>=1;
    cou=n-cou;
    for(int r(1);r<=n;++r)
    if(!anc[r]){
        bool ye(0);
        anc[r]=-1;
        wsi=1;
        wave[0]=r;
        for(int i(0);i<wsi;++i)
        for(int j(0);j<edges[wave[i]].size();++j)
        if(!anc[edges[wave[i]][j]]){
            wave[wsi]=edges[wave[i]][j];
            anc[wave[wsi]]=wave[i];
            ++wsi;
        }
        else if(anc[wave[i]]!=edges[wave[i]][j])
            ye=1;
        if(ye)
        if(wsi==n){
            cout<<"YES\n0";
            return 0;
        }
        else{
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES\n"<<cou<<"\n";
    for(int i(1);i<=n;++i){
        anc[i]=i;
        sran[i]=1;
    }
    for(int i(1);i<=n;++i)
        for(int j(0);j<edges[i].size();++j)
            unite(i, edges[i][j]);
    for(int i(1);i<=n;++i)
    if(edges[i].size()<2){
        bool ye(0);
        fro=i;
        ++i;
        if(edges[fro].size()==1){
            for(;i<=n;++i)
                if(edges[i].size()<2 && finds(fro)!=finds(i)){
                    edges[i].push_back(1);
                    unite(i, fro);
                    cout<<fro<<' '<<i<<'\n';
                    ye=1;
                    break;
                }
        }
        else{
            bool f(0);
            for(;i<=n;++i)
                if(edges[i].size()<2 && finds(fro)!=finds(i)){
                    edges[i].push_back(1);
                    unite(i, fro);
                    cout<<fro<<' '<<i<<'\n';
                    if(f){
                        ye=1;
                        break;
                    }
                    else
                        f=1;
                }
        }
        if(!ye){
            i=fro+1;
            for(;i<=n;++i)
                if(edges[i].size()<2){
                    edges[i].push_back(1);
                    unite(i, fro);
                    cout<<fro<<' '<<i<<'\n';
                    ye=1;
                    break;
                }
            break;
        }
        i=fro;
    };
    return 0;
}