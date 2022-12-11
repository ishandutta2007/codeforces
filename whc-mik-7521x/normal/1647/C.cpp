#include<bits/stdc++.h>
using namespace std;
const int N=1e2+10;
int mp[N][N];
struct node{
    int sx,sy,ex,ey;
    void print(){
        printf("%d %d %d %d\n",sx,sy,ex,ey);
    }
};
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++){
            for(int o=1;o<=m;o++){
                scanf("%1d",&mp[i][o]);
            }
        }
        if(mp[1][1]){
            puts("-1");
            continue;
        }
        vector<node>v;
        for(int i=n;i>1;i--){
            for(int o=1;o<=m;o++){
                if(mp[i][o])v.push_back({i-1,o,i,o});
                else v.push_back({i,o,i,o});
            }
        }
        for(int i=m;i>=1;i--)if(mp[1][i])v.push_back({1,i-1,1,i});else v.push_back({1,i,1,i});
        printf("%d\n",(int)v.size());
        for(auto it:v)it.print();
    }
    return  0;
}