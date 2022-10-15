#include<bits/stdc++.h>
 
using namespace std;
 
const int maxn=2007;
int deg[maxn],tmp[maxn],n;
char s[maxn][maxn];
bool scc(){
    for (int i=0;i<n;++i) tmp[i]=deg[i];
    sort(tmp,tmp+n);
    int sum=0;
    for (int i=0;i<n-1;++i){
        sum+=tmp[i]-i;
        if (sum) continue;
        return 0;
    }
    return 1;
}
 
void inv(int u){
    for (int i=0;i<n;++i){
        if (i==u) continue;
        if (s[u][i]=='0') s[u][i]='1', deg[u]++,deg[i]--;
        else s[u][i]='0', deg[u]--, deg[i]++;
    }
}
int main(){
    cin>>n;
    for (int i=0;i<n;++i) cin>>s[i];
    for (int i=0;i<n;++i){
        for (int j=0;j<n;++j)
            if (s[i][j]=='1') deg[i]++;
    }
    if (scc()){
        puts("0 1");
        return 0;
    }
    int ret=0;
    for (int i=0;i<n;++i){
        inv(i);
        if (scc()) ret++;
        inv(i);
    }
    if (ret>0){
        printf("1 %d",ret);
        return 0;
    }
    if (n==4){
        printf("-1");
        return 0;
    }
    printf("2 18");
}