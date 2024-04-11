#include<bits/stdc++.h>
using namespace std;

const int maxn=200007;
int n,m;
int l[maxn],res[maxn];
long long sum[maxn];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=m;++i){
        cin>>l[i];
    }
    for (int i=m;i>0;--i){
        sum[i]=sum[i+1]+l[i];
    }
    int le=0, re=0;
    for (int i=1;i<=m;++i){
        le++;
        if (le+l[i]-1>n){
            cout<<"-1";
            return 0;
        }
        if (re+sum[i]<n){
            cout<<"-1";
            return 0;
        }
        le=max((long long)le,n-sum[i]+1);
        res[i]=le;
        re=le+l[i]-1;
    }
    for (int i=1;i<=m;++i){
        cout<<res[i]<<" ";
    }
    return 0;

}