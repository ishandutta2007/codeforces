#include<bits/stdc++.h>
using namespace std;
const int N=3e5+10;
struct AC{
    string str[N];
    int tot,son[N][26],cnt[N],n;
    int stk[N],fr[N],siz[N],lent;
    void insert(int r,char *s) {
        int d=s[1]-'a',len=strlen(s+1),rt=r;
        for(int i=1;i<=len;d=s[++i]-'a') {
            if(son[r][d]==rt) {
                son[r][d]=++tot;
                for(int j=0;j<26;j++)son[tot][j]=rt;
            }
            r=son[r][d];
        } ++cnt[r];
    }
    int fail[N];
    void build(int r) {
        fail[r]=r;
        queue<int>q;
        for(int i=0;i<26;i++)
            if(son[r][i]>r) q.push(son[r][i]),fail[son[r][i]]=r;
        while(!q.empty()) {
            int u=q.front(); q.pop();
            for(int i=0;i<26;i++) {
                int v=son[u][i];
                if(v==r) son[u][i]=son[fail[u]][i];
                else {
                    fail[v]=son[fail[u]][i];
                    cnt[v]+=cnt[son[fail[u]][i]];
                    q.push(v);
                }
            }
        }
    }
    int solve(int r,char *s) {
        int d=s[1]-'a',len=strlen(s+1),res=0;
        for(int i=1;i<=len;d=s[++i]-'a')
            r=son[r][d],res+=cnt[r];
        return res;
    }
    void merge(){
        --lent,siz[lent]<<=1;
        for(int i=stk[lent];i<=tot;i++){
            cnt[i]=fail[i]=0;
            for(int j=0;j<26;j++) son[i][j]=0;
        }
        tot=stk[lent];
        for(int i=0;i<26;i++)son[tot][i]=tot;
        for(int L=fr[lent];L<=n;L++)insert(stk[lent],&str[L][0]);
        build(stk[lent]);
    }
    void ins(char *s) {
        stk[++lent]=++tot;
        for(int i=0;i<26;i++) son[tot][i]=tot;
        siz[lent]=1;
        insert(tot,s),build(stk[lent]);
        int len=strlen(s+1);
        str[fr[lent]=++n]=" ";
        for(int i=1;i<=len;i++) str[n]+=s[i];
        while(siz[lent]==siz[lent-1]) merge();
    }
    int query(char *s) {
        int ans=0;
        for(int i=1;i<=lent;i++)
            ans+=solve(stk[i],s);
        return ans;
    }
}k1,k2;
int n;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int x;
        char s[N];
        scanf("%d%s",&x,s+1);
        if(x==1)k1.ins(s);
        if(x==2)k2.ins(s);
        if(x==3){
            printf("%d\n",k1.query(s)-k2.query(s));
            fflush(stdout);
        }
    }
    return  0;
}