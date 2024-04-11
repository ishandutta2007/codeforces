#include<bits/stdc++.h>
using namespace std;
int n,m,maxa,mina,maxb,minb;
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        if(i==0){
            maxa=a;
            mina=b;
        }else{
            maxa=max(maxa,a);
            mina=min(mina,b);
        }
    }
    cin>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        if(i==0){
            maxb=a;
            minb=b;
        }else{
            maxb=max(maxb,a);
            minb=min(minb,b);
        }
    }
    printf("%i",max(0,max(maxb-mina,maxa-minb)));
}