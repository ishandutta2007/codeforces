#include <bits/stdc++.h>
using namespace std;
int type[1010];
int main(){
    int n,s=0,x,m=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        type[x]++;
    }
    for(int i=0;i<=1000;i++){
        if(type[i])	m++;
        if(type[i]>s)	s=type[i];
    }
    cout<<s<<" "<<m<<endl;
}