#include<bits/stdc++.h>
using namespace std;
int main(){
ios::sync_with_stdio(false);
cin.tie(0);
int t;cin>>t;
while(t--){
string s;
cin>>s;
int p;
cin>>p;
int n=s.size();
vector<bool> was(n);
int sum=0;
for(int i=0;i<n;i++){
sum+=(s[i]-'a')+1;
}
vector<int> o(n);
iota(o.begin(),o.end(),0);
sort(o.begin(),o.end(),[&](int i,int j){
return s[i]>s[j];
});
int i=0;
while(i<n&&sum>p){
sum-=(s[o[i]]-'a');
sum--;
was[o[i]]=true;
i++;
}
for(int i=0;i<n;i++)if(!was[i])cout<<s[i];
cout<<"\n";
}
}