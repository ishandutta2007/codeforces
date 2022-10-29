#include<bits/stdc++.h>
int n,x,m,t;
int s[200010];
int main(){
for(scanf("%d",&n);n--;m=x>m?x:m,!t||x<s[t]?s[++t]=x:x==s[t]?--t:s[++t]=0)scanf("%d",&x);
printf(!t||s[t]-t==m-1?"YES":"NO");
}