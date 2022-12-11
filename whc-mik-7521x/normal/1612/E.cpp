#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,res[50];
vector<int>a[N];
struct node{
    int x;
    double sum;
}lty[N];
bool cmp(node aa,node bb){
    return aa.sum>bb.sum;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        a[x].push_back(y);
    }
    double ans=0;
    int le=0;
    for(int i=1;i<=20;i++){
        for(int o=1;o<N;o++){
            lty[o].sum=0;
            lty[o].x=o;
            for(int j=0;j<(int)a[o].size();j++){
                lty[o].sum+=i<=a[o][j]?1:1.0*a[o][j]/i;
            }
        }
        sort(lty+1,lty+N,cmp);
        double now=0;
        for(int o=1;o<=i;o++){
            now+=lty[o].sum;
        }
        if(now>ans){
            ans=now;
            le=i;
            for(int o=1;o<=i;o++)res[o]=lty[o].x;
        }
    }
    printf("%d\n",le);
    for(int i=1;i<=le;i++)printf("%d ",res[i]);
    return  0;
}