#include<iostream>
using namespace std;
int main(){
    int n,i,j,ans,d[11],p=0,t;
    for(i=0;i<11;i++)
    d[i]=0;
    cin>>n;
    while(n!=0){
        d[p]=n%10;
        n/=10;
        p++;
    }
    ans=1;
    for(i=0;i<p-1;i++)
    ans*=9;
    t=1;
    for(i=0;i<p;i++)
    t*=d[i];
    if(ans<t)
    ans=t;
    for(i=0;i<p;i++){
        t=1;
        for(j=0;j<p;j++){
            if(j<i)
            t*=9;
            else if(j==i)
            t*=(d[j]-1);
            else
            t*=d[j];
        }
        if(t>ans)
        ans=t;
    }
    cout<<ans<<endl;
}