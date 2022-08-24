#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int k1,k2,k3,k4;
int dfs(int k1,int k2,int k3,int k4,int k5){
    if (k1==0&&k2==0) return 1;
    if (k3==0&&k4==0) return 0;
    if (k1>=k3&&k2>=k4) return 0;
    if (k5==0){
        if (k1<=k3&&k2<=k4) return 1;
        if (k1>k3&&(k3!=k1-1||k2!=k4)) return dfs(k1-1,k2,k3,k4,k5^1); else 
        if (k2>k4&&(k4!=k2-1||k1!=k3)) return dfs(k1,k2-1,k3,k4,k5^1); else 
        return dfs(k1,k2,k3,k4,k5^1);
    } else {
        if ((k1!=k3-1||k2!=k4-1)&&k3&&k4) return dfs(k1,k2,k3-1,k4-1,k5^1);
        if (k3&&(k1!=k3-1||k2!=k4)) return dfs(k1,k2,k3-1,k4,k5^1); 
        else if (k4&&(k2!=k4-1||k1!=k3)) return dfs(k1,k2,k3,k4-1,k5^1);
        else  return dfs(k1,k2,k3,k4,k5^1);
    }
}
int main(){
    scanf("%d%d%d%d",&k1,&k2,&k3,&k4);
    if (dfs(k1,k2,k3,k4,0)) cout<<"Polycarp"<<endl; else cout<<"Vasiliy"<<endl;
    return 0;
}