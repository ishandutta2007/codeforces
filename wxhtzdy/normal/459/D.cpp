#include <bits/stdc++.h>
using namespace std;
const int N=1000050;
int BIT[N];
void Add(int x,int val){
    for(;x<N;x+=x&(-x))BIT[x]+=val;
}
int Get(int x){
    int res=0;
    for(;x>0;x-=x&(-x))res+=BIT[x];
    return res;
}
int main(){
    int n;scanf("%i",&n);
    int a[n];
    for(int i=0;i<n;i++)scanf("%i",&a[i]);
    int pref[n];
    map<int,int> cnt;
    for(int i=n-1;i>=0;i--){
        cnt[a[i]]++;
        pref[i]=cnt[a[i]];
        Add(pref[i],1);
    }
    long long ans=0;
    map<int,int> cnt2;
    for(int i=0;i<n;i++){
        Add(pref[i],-1);
        cnt2[a[i]]++;
        ans+=Get(cnt2[a[i]]-1);
    }
    printf("%lld",ans);
    return 0;
}