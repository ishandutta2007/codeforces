#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
char s[N];
int a,b,c,d;
int t;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d%d%s",&a,&b,&c,&d,s+1);
        int cta=0,n=a+b+2*c+2*d;
        for(int i=1;i<=n;i++)cta+=s[i]=='A';
        if(cta!=a+c+d){puts("NO");continue;}
        vector<string>vec;
        string now;
        for(int i=1;i<=n;i++){
            if(now.size()&&now.back()==s[i])vec.push_back(now),now.clear();
            now.push_back(s[i]);
        }
        vec.push_back(now);
        vector<int>at,bt;
        int tot=0,ct1=0,ct2=0;
        for(auto it:vec){
            if(it.size()&1)tot+=it.size()>>1;
            else if(it[0]=='A'){
                at.push_back(it.size()>>1);
            }
            else{
                bt.push_back(it.size()>>1);
            }
        }
        stable_sort(at.begin(),at.end());
        stable_sort(bt.begin(),bt.end());
        for(int i:at){
            int kk=i;
            if(c>=kk)c-=kk,kk=0;
            else kk-=c,c=0;
            kk--;
            if(kk>0)ct2+=kk;
        }
        for(int i:bt){
            int kk=i;
            if(d>=kk)d-=kk,kk=0;
            else kk-=d,d=0;
            kk--;
            if(kk>0)ct1+=kk;
        }
        puts(max(0,c-ct1)+max(0,d-ct2)<=tot?"YES":"NO");
    }
    return  0;
}