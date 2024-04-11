#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
const int N=1005,M=505,mod=998244353;
int n,m,l,hs[N],ht[N],same;
char s[N][M],t[N][M];
typedef pair<int,int> pii;
set<pii> q;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%s",s[i]);l=strlen(s[i]);
		for(int j=0;j<l;j++)hs[i]=((ll)hs[i]*107+(s[i][j]-'a'+1))%mod;
		q.insert(make_pair(hs[i],l));
	}
	for(int i=1;i<=m;i++){
		scanf("%s",t[i]);l=strlen(t[i]);
		for(int j=0;j<l;j++)ht[i]=((ll)ht[i]*107+(t[i][j]-'a'+1))%mod;
		if(q.find(make_pair(ht[i],l))!=q.end())same++;
	}
	int sump=(same+1)/2+n-same;
	int sumt=same/2+m-same;
	printf("%s",sump>sumt?"YES":"NO");
	return 0;
}