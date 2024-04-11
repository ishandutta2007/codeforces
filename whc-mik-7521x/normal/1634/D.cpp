#include<bits/stdc++.h>
using namespace std;
int t,n,a[2005];
vector<int>v;
int last;
void solve(){
    int k1,k2,k3,k4;
    printf("? %d %d %d\n",v[1],v[2],v[3]);
    fflush(stdout);
    scanf("%d",&k1);
    printf("? %d %d %d\n",v[0],v[2],v[3]);
    fflush(stdout);
    scanf("%d",&k2);
    printf("? %d %d %d\n",v[1],v[0],v[3]);
    fflush(stdout);
    scanf("%d",&k3);
    printf("? %d %d %d\n",v[1],v[2],v[0]);
    fflush(stdout);
    scanf("%d",&k4);
    int kp=max(k1,max(k2,max(k3,k4)));
    vector<int>vv;
    if(k1==kp)last=v[0];
    else vv.push_back(v[0]);
    if(k2==kp)last=v[1];
    else vv.push_back(v[1]);
    if(k3==kp)last=v[2];
    else vv.push_back(v[2]);
    if(k4==kp)last=v[3];
    else vv.push_back(v[3]);
    if(vv.size()==0){
        vv.insert(vv.end(),v.begin(),v.begin()+2);
    }
    if(vv.size()==1){
        if(k1==kp)vv.push_back(v[0]);
        else if(k2==kp)vv.push_back(v[1]);
        else if(k3==kp)vv.push_back(v[2]);
        else if(k4==kp)vv.push_back(v[3]);
    }
    v.clear();
    v=vv;
}
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        v.clear();
        v.push_back(1);
        v.push_back(2);
        int i;
        for(i=3;i<=n;i+=2){
            v.push_back(i);
            if(i+1<=n)v.push_back(i+1);
            else v.push_back(last);
            solve();
        }
        printf("! %d %d\n",v[0],v[1]);
        fflush(stdout);
    }
    return  0;
}