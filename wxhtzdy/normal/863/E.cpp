#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int N=200050;
int l[N],r[N];
struct Compress{
    vector<int> all;
    Compress(){}
    void Add(int x){all.pb(x);}
    void Build(){sort(all.begin(),all.end());all.erase(unique(all.begin(),all.end()),all.end());}
    int Get(int x){return lower_bound(all.begin(),all.end(),x)-all.begin();}
}CPR;
const int M=6*N;
int pref[M][2];
void Add(int x,int y){++pref[x][0],--pref[y][0];}
int main(){
    int n;scanf("%i",&n);
    for(int i=1;i<=n;i++)scanf("%i%i",&l[i],&r[i]),--l[i],CPR.Add(l[i]),CPR.Add(r[i]);
    CPR.Build();
    for(int i=1;i<=n;i++)l[i]=CPR.Get(l[i]),r[i]=CPR.Get(r[i]);
    for(int i=1;i<=n;i++)Add(l[i],r[i]);
    for(int i=0;i<M-1;i++)pref[i+1][0]+=pref[i][0];
    for(int i=0;i<M-1;i++)pref[i+1][1]=pref[i][1]+(pref[i][0]>1?1:0);
    //for(int i=0;i<(int)CPR.all.size();i++)printf("%i %i\n",pref[i][0],pref[i][1]);
    for(int i=1;i<=n;i++){
        if(pref[r[i]][1]-pref[l[i]][1]==r[i]-l[i])return 0*printf("%i",i);
    }
    printf("-1");
    return 0;
}