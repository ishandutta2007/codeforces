#include<bits/stdc++.h>
using namespace std;
long long x,y;
string ans;
map<string,bool>vis;
void dfs(string u){
    if((int)u.size()>64)return;
    if(vis[u])return;
    vis[u]=1;
    if(u==ans){
        puts("YES");
        exit(0);
    }
    string s1=u+'0',s2=u+'1';
    while(*s1.rbegin()=='0')s1.pop_back();
    while(*s2.rbegin()=='0')s2.pop_back();
    reverse(s1.begin(),s1.end());
    reverse(s2.begin(),s2.end());
    dfs(s1);
    dfs(s2);
}
int main(){
    scanf("%lld%lld",&x,&y);
    string s1,s2;
    while(x)s1.push_back('0'+(x&1)),x>>=1;
    while(y)s2.push_back('0'+(y&1)),y>>=1;
    reverse(s1.begin(),s1.end());
    reverse(s2.begin(),s2.end());
    ans=s2;
    dfs(s1);
    puts("NO");
    return  0;
}