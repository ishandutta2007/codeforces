#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long gcd(long long x,long long y){
    return y==0?x:gcd(y,x%y);
}
struct node{
    int l,r;
    bool operator<(const node b)const{
        return l<b.l;
    }
};
int st[N][20],a[N],n;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]),st[i][0]=a[i];
    for(int i=1;i<20;i++){
        for(int o=1;o+(1<<i)-1<=n;o++){
            st[o][i]=gcd(st[o][i-1],st[o+(1<<(i-1))][i-1]);
        }
    }
    vector<node>v;
    int l=1,r=1;
    while(r<=n){
        if(r<l){r++;continue;}
        int len=log2(r-l+1);
        int dd=gcd(st[l][len],st[r-(1<<len)+1][len]);
        if(dd>r-l+1)r++;
        else if(dd==r-l+1){v.push_back({l,r}),l++;}
        else if(dd<r-l+1){l++;}
    }
    stable_sort(v.begin(),v.end());
    int last=0;
    vector<int>u;
    for(int i=0;i<(int)v.size();i++){
        if(v[i].l<=last)continue;
        u.push_back(v[i].r);
        last=v[i].r;
    }
    u.push_back(n+2);
    stable_sort(u.begin(),u.end());
    for(int i=1;i<=n;i++){
        printf("%lld ",(long long)(upper_bound(u.begin(),u.end(),i)-u.begin()));
    }
    return  0;
}