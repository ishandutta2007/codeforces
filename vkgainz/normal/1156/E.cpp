#include <bits/stdc++.h>
using namespace std;
#define ll long long
int p[200001], pos[200001];
int seg[400001];
int n;
void build(){
    for(int i=n-1;i>=1;i--)
        seg[i] = max(seg[2*i],seg[2*i+1]);
}
int query(int l,int r){
    l+=n; r+=n;
    int ret = 0;
    while(l<r){
        if(l%2) ret = max(ret,seg[l++]);
        if(r%2) ret = max(ret,seg[--r]);
        l/=2; r/=2;
    }
    return ret;
}
ll solve(int l,int r){
    if(l>r) return 0;
    int idx = pos[query(l,r+1)];
    int m = (l+r)/2;
    int num =0;
    if(idx>m){
        for(int i=r;i>idx;i--)
            if(pos[p[idx]-p[i]] < idx && pos[p[idx]-p[i]]>=l) num++;
    }
    else{
        for(int i=l;i<idx;i++)
            if(pos[p[idx]-p[i]] > idx && pos[p[idx]-p[i]]<=r) num++;
    }
    return num+solve(l,idx-1)+solve(idx+1,r);
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&p[i]);
        pos[p[i]] = i;
        seg[i+n] = p[i];
    }
    build();
    cout << solve(0,n-1) << endl;
}