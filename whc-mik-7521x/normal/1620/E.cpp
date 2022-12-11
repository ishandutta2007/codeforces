#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,que[N][3],to[N][3];
int mp[N];
void unnion(int x,int y){mp[y]=mp[x];}
int main(){
    scanf("%d",&n);
    vector<int>u;
    for(int i=1;i<=n;i++){
        mp[i]=i;
        if(scanf("%d",&que[i][0]),que[i][0]==1)scanf("%d",&que[i][1]),u.push_back(que[i][1]);
        else scanf("%d%d",&que[i][1],&que[i][2]),u.push_back(que[i][1]),u.push_back(que[i][2]);
    }
    sort(u.begin(),u.end());
    u.erase(unique(u.begin(),u.end()),u.end());
    for(int i=1;i<=n;i++){
        if(que[i][0]==1)to[i][1]=lower_bound(u.begin(),u.end(),que[i][1])-u.begin()+1;
        else to[i][1]=lower_bound(u.begin(),u.end(),que[i][1])-u.begin()+1,to[i][2]=lower_bound(u.begin(),u.end(),que[i][2])-u.begin()+1;
    }
    vector<int>v;
    for(int i=n;i>=1;i--){
        if(que[i][0]==2){
            unnion(to[i][2],to[i][1]);
        }
        else {
            v.push_back(u[mp[to[i][1]]-1]);
        }
    }
    for(int i=(int)v.size()-1;i>=0;i--)printf("%d ",v[i]);
    return  0;
}