#include<bits/stdc++.h>
using namespace std;
const int N=1111111;
long long pre[N],n,m,a[N];
int main() {
    cin>>n>>m;
    for(int i=1;i<=m;++i)cin>>a[i];
    for(int i=1;i<m;++i){
        int x,y;
        x=a[i];
        y=a[i+1];
        if(x==y)continue;
        if(x>y)swap(x,y);
        pre[1]+=y-x;
        pre[x]+=-(y-x);
        pre[x]+=y-1;
        pre[x+1]+=-(y-1);
        pre[x+1]+=y-x-1;
        pre[y]+=-(y-x-1);
        pre[y]+=x;
        pre[y+1]+=-x;
        pre[y+1]+=y-x;
    }
    for(int i=1;i<=n;++i){
        pre[i]+=pre[i-1];
        cout<<pre[i]<< " ";
    }
    return 0;
}