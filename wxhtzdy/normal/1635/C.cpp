#include <bits/stdc++.h>
using namespace std;
const int N=300050;
int n;
long long a[N];
int main(){
int tt;
scanf("%i",&tt);
while(tt--){
scanf("%i",&n);
for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
if(a[n]<a[n-1]){
printf("-1\n");
continue;
}
vector<tuple<int,int,int>> ans;
for(int i=n-2;i>=1;i--){
if(a[i]>a[i+1]-a[n]){
ans.emplace_back(i,i+1,n);
a[i]=-a[n]+a[i+1];
}
}
bool ok=true;
for(int i=1;i<n;i++)if(a[i]>a[i+1])ok=false;
if(!ok)printf("-1\n");
else{
printf("%d\n",ans.size());
for(int i=0;i<ans.size();i++){
printf("%d %d %d\n",get<0>(ans[i]),get<1>(ans[i]),get<2>(ans[i]));
}
}
}
}