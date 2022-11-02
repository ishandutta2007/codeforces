#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
int main(){
    int n,p,k;
    while(cin>>n>>p>>k)
    {
        if(p-k>1)cout<<"<< ";
        int f=max(p-k,1),lim=min(p+k,n),t=0;
        while(f<=lim)
        {
            if(t)cout<<' ';else t=1;
            if(f==p)printf("(%d)",f);
            else cout<<f;
            f++;
        }
        if(p+k<n)cout<<" >>";
        cout<<endl;
    }
}