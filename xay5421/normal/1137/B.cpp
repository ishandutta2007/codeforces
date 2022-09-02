#include<cstdio>
#include<cstring>
#include<algorithm>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
const int N=500005;
char sa[N],sb[N],ans[N];int cnt[256],nxt[N];
int main(){
    scanf("%s%s",sa,sb);
    for(int i=0;sa[i];++i)++cnt[sa[i]];
    int j=0;
    for(int i=1;sb[i];++i){
        while(j&&sb[j]!=sb[i])j=nxt[j];
        if(sb[j]==sb[i])nxt[i+1]=++j;
    }
    j=0;
    for(int i=0;sa[i];++i){
    	if(cnt[sb[j]]){
    		--cnt[sb[j]];
    		ans[i]=sb[j];
    		++j;
    	}else{
    		--cnt[sb[j]^1];
    		ans[i]=(sb[j]^1);
    		j=0;
    	}
    	if(!sb[j])j=nxt[j];
    }
    printf("%s\n",ans);
	return 0;
}