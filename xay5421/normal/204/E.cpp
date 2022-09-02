#include<cstdio>
#include<string>
#include<cstring>
#include<iostream>
typedef long long ll;const int N=200005;
int n,k,now,cnt=1,lst=1,fa[N],ch[N][26],len[N],cur[N],sum[N];std::string s[N];
void extend(int c){
	int p=lst,np=lst=++cnt;len[np]=len[p]+1;
	for(;p&&!ch[p][c];p=fa[p])ch[p][c]=np;
	if(!p)fa[np]=1;
	else{
		int q=ch[p][c];
		if(len[p]+1==len[q])fa[np]=q;
		else{
			int nq=++cnt;len[nq]=len[p]+1;
			memcpy(ch[nq],ch[q],sizeof(ch[nq])),fa[nq]=fa[q],cur[nq]=cur[q],sum[nq]=sum[q];
			fa[q]=fa[np]=nq;
			for(;ch[p][c]==q;p=fa[p])ch[p][c]=nq;
		}
	}
	while(np){
		if(sum[np]>=k||cur[np]==now)break;
		++sum[np],cur[np]=now,np=fa[np];
	}
}
void solve(int u){
	int p=1;ll ans=0;
	for(int i=0;i<(int)s[u].size();++i){
		int c=s[u][i]-'a';p=ch[p][c];int u=p;
		while(u){
			if(sum[u]>=k){ans+=len[u];break;}
			u=fa[u];
		}
	}
	printf("%I64d ",ans);
}
int main(){
	scanf("%d%d",&n,&k);
	if(k>n){for(int i=1;i<=n;++i)printf("0 ");return 0;}
	for(int i=1;i<=n;++i){
		std::cin>>s[i];lst=1,now=i;
		for(int j=0;j<(int)s[i].size();++j)extend(s[i][j]-'a');
	}
	for(int i=1;i<=n;++i)solve(i);
	return 0;
}