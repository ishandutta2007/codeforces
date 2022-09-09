//savrseni zlocin kad u noci tako brzo nestanes
//ne mogu da sanjam tvoje oci, zelim to da prestane
//djavoli me zovu nude lovu i noci besane
//zovem turu novu za ekipu moju u separe
#include <bits/stdc++.h>
using namespace std;
int ri(){int x;scanf("%i",&x);return x;}
const int N=205;
int ans[N],n,pos[N];
vector<int> v[N];
bool chk(int fir){
    for(int i=1;i<=n;i++)pos[i]=0;
    ans[1]=fir;pos[fir]=1;
    for(int i=2;i<=n;i++){
        ans[i]=0;
        for(int j=1;j<n;j++){
            int sz=v[j].size();
            int lo=0,z=0;
            for(int k:v[j]){
                if(!pos[k])z=k;
                else if(pos[k]>i-sz)lo++;
            }
            if(lo==sz-1 && z){
                ans[i]=z;
                pos[z]=i;
                break;
            }
        }
        if(!ans[i])return 0;
    }
    return 1;
}
void solve(){
    n=ri();
    for(int i=1;i<n;i++){
        int sz=ri();
        v[i].clear();
        while(sz--)v[i].push_back(ri());
    }
    for(int i=1;i<=n;i++){
        if(chk(i)){
            for(int j=1;j<=n;j++)printf("%i ",ans[j]);
            printf("\n");
            return;
        }
    }
}
int main(){
    int t=ri();
    while(t--)solve();
    return 0;
}