#include <iostream>

using namespace std;

int main()
{
    int a[1000],h[1000]={0},n,i,j,k,sel,tmp;
    cin>>n>>k;
    for(i=0;i<n;i++) cin>>a[i];
    for(i=0;i<n;i++) if ((a[i]>i*k)&&(h[i]!=-1))
        for(j=i+1;j<n;j++) if (a[j]==a[i]+(j-i)*k) {h[j]=-1;h[i]++;}
    sel=0;
    for(i=0;i<n;i++) if (h[sel]<h[i]) sel=i;
    cout<<n-h[sel]-1<<endl;
    for(i=0;i<n;i++)
    {
        tmp=a[sel]+(i-sel)*k;
        if (tmp>a[i]) cout<<"+"<<" "<<i+1<<" "<<tmp-a[i]<<endl;
        if (tmp<a[i]) cout<<"-"<<" "<<i+1<<" "<<a[i]-tmp<<endl;
    }
}