#include <bits/stdc++.h>

using namespace std;

int n,req[260],msk[260];

int pwd[8] = {0};
int con[260],vis[260] = {0};

int getint(){
    int a1,a2,a3;
    cin>>a1>>a2>>a3;
    return a1*4+a2*2+a3;
}

vector<int> G[260];
int main(){
    cin>>n;
    int fin = 1;
    for(int i=1;i<=n;i++){
        req[i] = getint();
        if(!req[i]){
            vis[i] = 1;
            fin+=1;
        }
    }
    for(int i=1;i<=n;i++){
        msk[i] = getint();
    }
    vis[1] = 1;
    pwd[7] = 1;
    pwd[0] = 1;
    while(1){
        //cout<<"f :"<<fin<<endl;
        int lfin = fin;
        for(int i=1;i<=n;i++){
            if(!vis[i] && pwd[req[i]]){
                int u = pwd[req[i]];
                int v = i;
                G[u].push_back(v);
                vis[i] = 1;
                fin+=1;
                if(!pwd[msk[i]&req[i]]){
                    con[i] = 1;
                    pwd[msk[i]&req[i]] = i;
                }
            }
            if(!vis[i] && !pwd[req[i]]){
                if(req[i] == 3 && pwd[1] && pwd[2]){
                    int u = pwd[1],w = pwd[2];
                    G[u].push_back(i);
                    G[w].push_back(i);
                    pwd[3] = i;
                    vis[i] = 1;
                    fin++;
                }
                if(req[i] == 5 && pwd[1] && pwd[4]){
                    int u = pwd[1],w = pwd[4];
                    G[u].push_back(i);
                    G[w].push_back(i);
                    pwd[5] = i;
                    vis[i] = 1;
                    fin++;
                }
                if(req[i] == 6 && pwd[4] && pwd[2]){
                    int u = pwd[4],w = pwd[2];
                    G[u].push_back(i);
                    G[w].push_back(i);
                    pwd[6] = i;
                    vis[i] = 1;
                    fin++;
                }
            }
        }
        if(fin == lfin)break;
    }
    if(fin == n){
        cout<<"Possible\n";
        for(int i=1;i<=n;i++){
            cout<<con[i];
            if(i!=n)cout<<' ';
        }
        cout<<endl;
        int m = 0;
        for(int i=1;i<=n;i++){
            for(auto ct:G[i])m++;
        }
        cout<<m<<endl;
        for(int i=1;i<=n;i++){
            for(auto ct:G[i])cout<<i<<' '<<ct<<endl;
        }
    }else{
        cout<<"Impossible\n";
    }
    return 0;
}