#include<bits/stdc++.h>
using namespace std;

int d[1005],s[1005],sufmax[1005],mxpos[1005],pred[1005];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k; cin>>n>>k; ++n;
    // int n,k; n=1001,k=1000;
    // for(int i=1;i<n;++i)d[i]=1000;
    for(int i=1;i<n;++i)cin>>d[i];
    // for(int i=1;i<n;++i)s[i]=1;
    for(int i=1;i<n;++i)cin>>s[i];
    for(int i=n-1;i>=1;--i){
        if(s[i]>sufmax[i+1]){
            mxpos[i]=i;
            sufmax[i]=s[i];
        }
        else{
            mxpos[i]=mxpos[i+1];
            sufmax[i]=sufmax[i+1];
        }
    }
    for(int i=1;i<n;++i)pred[i]=pred[i-1]+d[i];
    int tott=0,oil=s[1];
    for(int i=1;i<n;){
        int j=i; do{
            oil-=d[j];
            ++j;
            while(oil<0)tott+=k,oil+=s[i];
            oil+=s[j];
        }while(s[j]<s[i] && j<n);
        i=j;
    }
    cout<<tott+pred[n-1]<<endl;
}