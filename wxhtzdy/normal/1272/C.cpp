#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    scanf("%i %i",&n,&k);
    char s[n];
    scanf("%s",&s);
    map<char,int> mp;
    for(int i=0;i<26;i++)mp[(char)('a'+i)]=0;
    char t[k+1];
    for(int i=0;i<k;i++){cin>>t[i];mp[t[i]]=1;}
    int L[n];
    for(int i=n-1;i>=0;i--){
        if(mp[s[i]]==0){L[i]=-1;continue;}
        if(i==n-1||L[i+1]==-1)L[i]=i;
        else L[i]=L[i+1];
    }
    long long ans=0;
    for(int i=0;i<n;i++){
        if(L[i]==-1)continue;
        ans+=L[i]-i+1;
    }
    printf("%lld",ans);
}