#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define maxn 55
#define INF 2000000005
using namespace std;
char save[maxn][maxn];
char s[maxn*maxn];
int n,w[maxn*maxn][maxn*maxn],len,siz[maxn],dp[maxn*maxn];
void preprocess(){
    /*for(int i=0;i<n;i++){
        for(int j=0;j<siz[i];j++){
            int k=j,now=0;
            while(now<len&&k<siz[i]&&s[now]==save[i][k]){
                now++;
                k++;
            }
            if(k!=siz[i])continue;
            w[0][now]=1;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=siz[i]-1;j>=0;j--){
            int k=j,now=len-1;
            while(now>=0&&k>=0&&s[now]==save[i][k]){
                now--;
                k--;
            }
            if(k!=-1)continue;
            w[now+1][len]=1;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<=len-siz[i];j++){
            int k=j,now=0;
            while(now<siz[i]&&s[k]==save[i][now]){
                k++;
                now++;
            }
            if(now!=siz[i])continue;
            w[j][k]=1;
        }
    }*/
    for(int i=0;i<n;i++){
        for(int j=0;j<len;j++){
            int now=j;
            for(int k=0;k<siz[i];k++){
                if(s[now]==save[i][k]){
                    now++;
                    w[j][now]=1;
                }
            }
        }
    }
}
int DP(int pos){
    if(pos==0)return 0;
    if(dp[pos])return dp[pos];
    int k=INF;
    for(int i=0;i<pos;i++){
        if(w[i][pos]) k=min(k,DP(i));
    }
    return dp[pos]=k+1;
}
int main(){
    /*freopen("COS.in","r",stdin);
    freopen("COS.out","w",stdout);*/
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%s",save[i]);
        siz[i]=strlen(save[i]);
    }
    scanf("%s",s);
    len=strlen(s);
    preprocess();
    int ans=DP(len);
    if(ans>=INF)printf("-1");
    else printf("%d",ans);
    return 0;
}