#include<bits/stdc++.h>
using namespace std;
stack<int> S;
main()
{string s;
cin>>s;
for(int i=0; i<s.size(); i++)
{if(s[i]=='+'){
if(S.size() && S.top()) S.pop();
else S.push(1);}
else{
if(!S.size() || S.top()) S.push(0);
else S.pop();}}
if(S.size()) cout<<"No"<<endl;
else cout<<"Yes"<<endl;

}