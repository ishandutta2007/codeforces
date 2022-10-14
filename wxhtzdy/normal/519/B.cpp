#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%i",&n);
    int a[n],b[n],c[n];
    map<int,int> ma,mb,mc;
    for(int i=0;i<n;i++)scanf("%i",&a[i]),ma[a[i]]++;
    for(int i=0;i<n-1;i++)scanf("%i",&b[i]),mb[b[i]]++;
    for(int i=0;i<n-2;i++)scanf("%i",&c[i]),mc[c[i]]++;
    for(int i=0;i<n;i++){
        if(mb[a[i]]+1==ma[a[i]]){printf("%i\n",a[i]);break;}
    }
    for(int i=0;i<n-1;i++){
        if(mb[b[i]]==mc[b[i]]+1){printf("%i",b[i]);break;}
    }
    return 0;
}