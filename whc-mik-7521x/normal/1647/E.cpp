#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,p[N],a[N],f[N][35],kk[N];
int main(){
    scanf("%d",&n);
    set<int>st1,st2,st3;
    int mx=0;
    for(int i=1;i<=n;i++)scanf("%d",&p[i]),f[i][0]=p[i],st1.insert(p[i]);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]),mx=max(mx,a[i]);
    for(int i=1;i<=30;i++){
        for(int o=1;o<=n;o++){
            f[o][i]=f[f[o][i-1]][i-1];
        }
    }
    int tim=(mx-n)/(n-st1.size());
    for(int i=1;i<=n;i++){
        int now=tim,to=i;
        for(int o=30;o>=0;o--){
            if(now>=1<<o)now-=1<<o,to=f[to][o];
        }
        kk[i]=a[to];
        st3.insert(a[to]);
    }
    for(int i=1;i<=n;i++)if(st3.find(i)==st3.end())st2.insert(i);
    for(int i=1;i<=n;i++){
        if(st3.find(kk[i])!=st3.end())printf("%d ",kk[i]),st3.erase(kk[i]);
        else{
            auto it=st2.lower_bound(kk[i]);
            printf("%d ",*it);
            st2.erase(it);
        }
    }
    return  0;
}