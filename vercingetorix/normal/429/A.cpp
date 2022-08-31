#include <iostream>
#include <math.h>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE  
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif

  long long n,m;
  cin>>n;

//std::vector<int> a;
std::string s;
long long ans=0;
long long a;
std::vector<std::vector<int>> ch(n+1);
std::vector<int> par(n+1);
std::vector<std::vector<int>> grpar(n+1);
std::vector<std::vector<int>> nb(n+1);
std::vector<std::vector<int>> lvl(n+1);
std::vector<int> v_lvl(n+1,0);
m=1;
lvl[1].push_back(1);
v_lvl[1]=1;
for(int i=1;i<n;i++){
    int u,v;
    cin >>u>>v;
    nb[u].push_back(v);
    nb[v].push_back(u);
    //xp;
}
int l=2;

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

std::vector<int> goal(n+1);
std::vector<int> was(n+1,0);
for(int i=0; i<n; i++){
    cin>>goal[i+1];
}

goal[0]=0;
par[1]=0;
for(int i=0; i<n; i++){
    int x;
    cin>>x;
    goal[i+1]=(x+goal[i+1])%2;
}
/*
for(int i=2; i<l; i++){
    for(int k=0; k<lvl[i].size();k++){
        int v=lvl[i][k];
        int kol=grpar[par[par[v]]].size();
        for(int j=0; j<kol; j++){
            grpar[v].push_back(grpar[par[par[v]]][j]);
        }
        grpar[v].push_back(par[par[v]]);

    }
}*/
for(int i=1; i<l; i++){
    for(int k=0; k<lvl[i].size();k++){
        int v=lvl[i][k];
        int sum=goal[v];
        if(i>1) sum+=was[par[par[v]]];
        /*for(int j=0; j<grpar[v].size(); j++){
            sum+=goal[grpar[v][j]];
        }*/
        if(sum%2) {
            ans++;
            if(i>1) was[v]=1-was[par[par[v]]];
            else was[v]=1;
        }
        else was[v]=was[par[par[v]]];
        goal[v]=sum%2;
    }
}
cout<< ans<<endl;

for(int i=1; i<l; i++){
    for(int k=0; k<lvl[i].size();k++){
        if(goal[lvl[i][k]]){
            cout<<lvl[i][k]<<endl;
        }
    }
}
  /*int a;
  cin >> a;
  vector<int> b;
  b.push_back(a);
  cout << b[0];
  */

  return 0;
}