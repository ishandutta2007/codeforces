#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    if(n==1&&m==0){
        printf("0 0");
        return 0;
    }
    int aaam=m;
    if(m>n*9||m==0){printf("-1 -1");return 0;}
    string s="";
    for(int i=0;i<n;i++)s+='0';
    s[0]='1';
    aaam-=1;
    for(int i=n-1;i>=0;i--){
        s[i]+=min(9,max(0,aaam));
        aaam-=9;
    }
    cout<<s<<" ";
    s="";
    for(int i=0;i<n;i++)s+='0';
    for(int i=0;i<n;i++){
        s[i]+=min(9,max(0,m));
        m-=9;
    }
    cout<<s;
}