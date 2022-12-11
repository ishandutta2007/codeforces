#include<bits/stdc++.h>
using namespace std;
const int N=55;
int mp[N],pm[N];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m,r,c,pd=0,pdd=0,pddd=0;
        char s;
        scanf("%d%d%d%d\n",&n,&m,&r,&c);
        for(int i=1;i<=n;i++){
            for(int o=1;o<=m;o++){
                if((s=getchar())=='B')pd=1;
                if(i==r||o==c)if(s=='B')pdd=1;
                if(i==r&&o==c&&s=='B')pddd=1;
            }
            getchar();
        }
        printf("%d\n",pddd?0:pdd?1:pd?2:-1);
    }
    return  0;
}