#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int>> vvi;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()

#define pb push_back

int main()
{
#ifndef ONLINE_JUDGE  
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif

int ans=0;
int n,m;
cin >> n >> m;
if((m%2)==1){
    cout<<"No solution";
    return 0;
}
std::vector<std::vector<int>> ch(n+1);
std::vector<int> par(n+1);
std::vector<std::vector<int>> nb(n+1);
std::vector<std::vector<int>> lvl(n+1);
std::vector<int> v_lvl(n+1,0);
std::vector<int> v_lvlpos(n+1,0);
std::vector<std::pair<int,int>> dope;
int n1=0;
lvl[1].push_back(1);
v_lvl[1]=1;
v_lvlpos[1]=0;
for(int i=0;i<m;i++){
    int u,v;
    cin >>u>>v;
    nb[u].push_back(v);
    nb[v].push_back(u);
    //xp;
}
int l=2;

while(n1<m){
    for(int k=0; k<lvl[l-1].size(); k++){
        int v=lvl[l-1][k];
        for(int h=0; h<nb[v].size();h++){
            if(v_lvl[nb[v][h]]==0){
                v_lvl[nb[v][h]]=l;
                v_lvlpos[nb[v][h]]=lvl[l].size();
                lvl[l].push_back(nb[v][h]);
                n1++;
                ch[v].push_back(nb[v][h]);
                par[nb[v][h]]=v;
            }
            else if(nb[v][h]!=par[v]){
                if(v<nb[v][h]) {
                    dope.pb(make_pair<int,int>(v,nb[v][h]));
                    n1++;
                }
                
            }
        }
    }
    l++;
}
l--;
std::vector<long long> lsize(l+1);
for(int i=1; i<=l;i++) lsize[i]=lvl[i].size();

vvi newnb(n+1);

for(int i=0;i<dope.size();i++){
    int f=dope[i].first;
    int s=dope[i].second;
    if(v_lvl[f]>v_lvl[s]) newnb[f].pb(s);
    if(v_lvl[f]<v_lvl[s]) newnb[s].pb(f);
    if(v_lvl[f]==v_lvl[s]){
        if(v_lvlpos[f]>v_lvlpos[s]) newnb[s].pb(f);
        else newnb[f].pb(s);
    }
}
vb used(n+1,false);
vb touched(n+1,false);
vvi nb1;
for(int i=l; i>0; i--){
    for(int j=0;j<lsize[i];j++){
        int v=lvl[i][j];
        if(used[v]) continue;
        int dv=newnb[v].size();
        for(int k=0; k<dv/2;k++){
            cout<<newnb[v][2*k]<<" "<<v<<" "<<newnb[v][2*k+1]<<endl;
        }
        if(dv%2==1){
            cout<<newnb[v][dv-1]<<" "<<v<<" "<<par[v]<<endl;
            continue;
        }
        else{
            int v1=par[v];
            newnb[v1].pb(v);
        }
    }

}

//cout<<ans;
return 0;


}