#include <bits/stdc++.h>

using namespace std;

int h[20],a[20];
string s;
int cv(char x){
if (x=='5') return 2;
if (x=='9') return 6;
return x-'0';
}
int main(){
cin>>s;
for(auto i:s) h[cv(i)]++;
cin>>s;
for(auto i:s) a[cv(i)]++;
int ans=1000000;
for(int i=0;i<=9;i++) if (h[i]) ans=min(ans,a[i]/h[i]);
cout<<ans;
}