#include<bits/stdc++.h>
using namespace std;
int n,a[150],sz[150],b[150];
int main(){
    scanf("%i",&n);
    for(int i=0;i<n;i++)scanf("%i",&a[i]);
    for(int i=0;i<150;i++)sz[i]=0,b[i]=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<a[i];j++)sz[j]++;
    }
    for(int i=0;i<150;i++){
        for(int j=0;j<sz[i];j++)b[n-j-1]++;
    }
    for(int i=0;i<n;i++)printf("%i ",b[i]);
}