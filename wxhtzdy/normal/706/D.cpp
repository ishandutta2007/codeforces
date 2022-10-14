#include <bits/stdc++.h>
using namespace std;
const int N=500050*30;
struct Node{
    int nxt[2];
    int cnt=0;
}trie[N];
int tsz;
map<int,int> was;
string GetBin(int x){
    string s="";
    while(x>0)s+=(char)(x%2+'0'),x/=2;
    //reverse(s.begin(),s.end());
    while((int)s.size()<30)s+='0';
    return s;
}
void Add(string s){
    int id=0;
    for(int i=29;i>=0;i--){
        int x=s[i]-'0';
        if(!trie[id].nxt[x])trie[id].nxt[x]=++tsz;
        id=trie[id].nxt[x];
        trie[id].cnt++;
    }
}
void Rem(string s){
    int id=0;
    for(int i=29;i>=0;i--){
        int x=s[i]-'0';
        id=trie[id].nxt[x];
        trie[id].cnt--;
    }
}
int Get(string s){
    int res=0,id=0;
    for(int i=29;i>=0;i--){
        int x=s[i]-'0';
        if(trie[trie[id].nxt[x^1]].cnt)res+=(1<<i),id=trie[id].nxt[x^1];
        else id=trie[id].nxt[x];
    }
    return res;
}
int main(){
    int q;scanf("%i",&q);
    while(q--){
        char type;cin>>type;
        if(type=='+'){
            int x;scanf("%i",&x);
            //if(was[x])continue;
            was[x]=1;
            Add(GetBin(x));
        }else{
            if(type=='-'){
                int x;scanf("%i",&x);
                //if(!was[x])continue;
                was[x]=0;
                Rem(GetBin(x));
            }else{
                int x;scanf("%i",&x);
                printf("%i\n",max(x,Get(GetBin(x))));
            }
        }
    }
    return 0;
}