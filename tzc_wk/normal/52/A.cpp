#include<bits/stdc++.h>
using namespace std;
int n,s[4];
int main(){
    scanf("%d",&n);
    for(int x,i=1;i<=n;i++)
        scanf("%d",&x),s[x]++;
    cout<<n-max(s[1],max(s[2],s[3]));
}