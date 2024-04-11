#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    scanf("%i%i",&n,&k);
    int a[n];
    for(int i=0;i<n;i++)scanf("%i",&a[i]);
    int pref[n];
    for(int i=0;i<n;i++){
        pref[i]=a[i];
        if(i>0)pref[i]+=pref[i-1];
    }
    int mn=pref[k-1];
    for(int i=k;i<n;i++){
        mn=min(mn,pref[i]-pref[i-k]);
    }
    if(pref[k-1]==mn){printf("1");return 0;}
    for(int i=k;i<n;i++){
        if(pref[i]-pref[i-k]==mn){printf("%i",i-k+2);return 0;}
    }
}