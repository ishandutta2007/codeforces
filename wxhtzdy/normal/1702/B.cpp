#include <bits/stdc++.h>
using namespace std;
int main(){
ios::sync_with_stdio(false);
cin.tie(0);
int t;
cin>>t;
while(t--){
string s;cin>>s;
int beg=0;
int n=s.size();
int ans=0;
while(beg<n){
vector<bool> was(26);
int ptr=beg;
int cnt=0;
while(ptr<n){
int c=(int)(s[ptr]-'a');
if(!was[c])cnt++;
if(cnt==4)break;
was[c]=true;
ptr++;
}
beg=ptr;
ans++;
}
cout<<ans<<'\n';
}
}