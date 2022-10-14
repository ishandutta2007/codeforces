#include<bits/stdc++.h>
using namespace std;
int n,k,q,t[150150],type,id;
set<pair<int,int>> s;
int main(){
    scanf("%i%i%i",&n,&k,&q);
    for(int i=0;i<n;i++)scanf("%i",&t[i]);
    for(int i=0;i<q;i++){
        scanf("%i%i",&type,&id);
        if(type==1){
            s.insert({t[id-1],id-1});
            if((int)s.size()>k)s.erase(*s.begin());
        }else{
            if(s.find({t[id-1],id-1})!=s.end())printf("YES\n");
            else printf("NO\n");

        }
    }
}