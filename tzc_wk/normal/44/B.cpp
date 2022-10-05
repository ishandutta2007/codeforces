#include <bits/stdc++.h>
using namespace std;
long long ans=0,n,b,c,i,j,x,y;
int main(){
    cin>>n>>x>>y>>c;
    b=x/2+y;
    for(i=0;i<=b;i++)
        for(j=0;j<=c;j++)
            if(i+j*2==n){
                if(j*2==n){
                    ans++;
                    continue;
                }
                if(max(x/2,y)>=i) ans+=min(i+1,min(x/2,y)+1);   
                else ans+=min(x/2,y)-(i-max(x/2,y))+1;  
            }
    cout<<ans;
    return 0;
}