#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int t,n,last[30];
int main(){
    scanf("%d",&t);
    while(t--){
        memset(last,0,sizeof last);
        char s[N];
        scanf("%s",s+1);
        n=strlen(s+1);
        set<char>st,st1;
        for(int i=1;i<=n;i++)st.insert(s[i]);
        int pd=0;
        for(int i=1;i<=n;i++){
            if(last[s[i]-'a']){
                st1.clear();
                for(int o=last[s[i]-'a'];o<i;o++)st1.insert(s[o]);
                if(st1.size()!=st.size())pd=1;
            }
            last[s[i]-'a']=i;
        }
        puts(pd?"NO":"YES");
    }
    return  0;
}