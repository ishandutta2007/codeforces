#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
inline int add(int a,int b){return a+b>=mod?a+b-mod:a+b;}
inline void Add(int &a,int b){a+=b;if(a>=mod)a-=mod;}
inline int mul(int a,int b){return 1ll*a*b%mod;}
int n,tot,q;
char s[1005];
int cnt[1<<17];
int f[1<<17][18];
int pw[18][1005];
void init(int l,int r){
	int c1=0,c2=0;
	for(int i=l;i<=r;i++)if(s[i]=='?')c1++;
	int now=0;
	for(int p=l,q=r;p<q;p++,q--){
		if(s[p]=='?'&&s[q]=='?'){
			c2++;
			continue;
		}
		if(s[p]!='?'&&s[q]!='?'&&s[p]!=s[q])return;
		if(s[p]=='?')now|=1<<s[q]-'a';
		if(s[q]=='?')now|=1<<s[p]-'a';
	}
	if(r-l+1&1&&s[l+r>>1]=='?')c2++;
	for(int i=cnt[now];i<=17;i++)Add(f[now][i],pw[i][tot-c1+c2]);
}
int main(){
	scanf("%d",&n);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)if(s[i]=='?')tot++;
	for(int i=0;i<=17;i++){
		pw[i][0]=1;
		for(int j=1;j<=n;j++)pw[i][j]=mul(pw[i][j-1],i);
	}
	for(int i=0;i<1<<17;i++)cnt[i]=cnt[i>>1]+(i&1);
	for(int l=1;l<=n;l++)
		for(int r=l;r<=n;r++)
			init(l,r);
	for(int i=1;i<1<<17;i<<=1){
		for(int j=0;j<1<<17;j+=i<<1)
			for(int k=0;k<i;k++){
				for(int l=0;l<=17;l++)
					Add(f[i+j+k][l],f[j+k][l]);
			}
	}
	scanf("%d",&q);
	while(q--){
		scanf("%s",s+1);
		int m=strlen(s+1);
		int now=0;
		for(int i=1;i<=m;i++)now|=1<<s[i]-'a';
		printf("%d\n",f[now][cnt[now]]);
	}
	return 0;
}