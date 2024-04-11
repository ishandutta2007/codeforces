#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
int t;
scanf("%i",&t);
while(t--){
int n;
scanf("%i",&n);
map<int,int> cnt;
ll ans=0;
for(int i=0;i<n;i++){
int x;
scanf("%i",&x);
ans+=cnt[x-i];
cnt[x-i]++;
}
printf("%lld\n",ans);
}
return 0;
}