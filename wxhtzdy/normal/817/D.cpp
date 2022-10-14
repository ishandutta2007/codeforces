#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%i",&n);
    long long a[n];
    for(int i=0;i<n;i++)scanf("%lld",&a[i]);
    long long st[n+1],sz=0,cl[n],cr[n],ccl[n],ccr[n];
    for(int i=0;i<n;i++){
        cl[i]=0,cr[i]=0,ccl[i]=0,ccr[i]=0;
    }
    for(int i=0;i<n;i++){
        while(sz>0&&a[st[sz]]<=a[i]){
            cl[i]+=cl[st[sz]]+1;
            sz--;
        }
        sz++,st[sz]=i;
    }
    sz=0;
    for(int i=n-1;i>=0;i--){
        while(sz>0&&a[st[sz]]<a[i]){
            cr[i]+=cr[st[sz]]+1;
            sz--;
        }
        sz++,st[sz]=i;
    }
    sz=0;
    for(int i=0;i<n;i++){
        while(sz>0&&a[st[sz]]>=a[i]){
            ccl[i]+=ccl[st[sz]]+1;
            sz--;
        }
        sz++,st[sz]=i;
    }
    sz=0;
    for(int i=n-1;i>=0;i--){
        while(sz>0&&a[st[sz]]>a[i]){
            ccr[i]+=ccr[st[sz]]+1;
            sz--;
        }
        sz++,st[sz]=i;
    }
    long long ans=0;
    for(int i=0;i<n;i++){
        ans+=(long long)(a[i]*(cl[i]+1)*(cr[i]+1))-(long long)(a[i]*(ccl[i]+1)*(ccr[i]+1));
    }
    printf("%lld",ans);
}