#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;scanf("%i",&n);
    int a[n];
    for(int i=0;i<n;i++)scanf("%i",&a[i]);
    int mn=a[0];
    for(int i=0;i<n;i++)mn=min(mn,a[i]);
    int k=mn/n;
    for(int i=0;i<n;i++)a[i]-=k*n;
    int id=0,i=0;
    while(1){
        if(a[id]<=i){
            printf("%i",id+1);
            return 0;
        }
        id=(id+1)%n,i++;
    }
    return 0;
}