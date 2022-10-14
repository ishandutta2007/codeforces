#include <bits/stdc++.h>
using namespace std;
int Dist(char*a,char*b,int m){
    int cnt=0;
    for(int i=0;i<m;i++)cnt+=a[i]!=b[i];
    return cnt;
}
int main(){
    int t;scanf("%i",&t);
    while(t--){
        int n,m;scanf("%i %i",&n,&m);
        char s[n][m];
        for(int i=0;i<n;i++)scanf("%s",&s[i]);
        bool was=0;
        for(int i=0;i<m;i++){
            char tmp[m];
            for(int j=0;j<m;j++)tmp[j]=s[0][j];
            for(int l=0;l<26;l++){
                tmp[i]=(char)('a'+l);
                bool ok=1;
                for(int j=0;j<n;j++)if(Dist(tmp,s[j],m)>1)ok=0;
                if(ok){
                    for(int j=0;j<m;j++)printf("%c",tmp[j]);
                    printf("\n");
                    was=1;
                    break;
                }
            }
            if(was)break;
        }
        if(!was)printf("-1\n");
    }
    return 0;
}