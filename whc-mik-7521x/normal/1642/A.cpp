#include<bits/stdc++.h>
using namespace std;
int t;
struct node{
    int x,y;
    bool operator<(const node b)const{
        return y>b.y;
    }
};
int main(){
    scanf("%d",&t);
    while(t--){
        vector<node>v;
        for(int i=1;i<=3;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            v.push_back({x,y});
        }
        stable_sort(v.begin(),v.end());
        if(v[0].y==v[1].y){
            printf("%lf\n",(double)abs(v[0].x-v[1].x));
        }
        else{
            puts("0");
        }
    }
    return  0;
}