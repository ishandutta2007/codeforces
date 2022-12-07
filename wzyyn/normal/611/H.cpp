#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
using namespace std;
int cnt[10];
int e[10][10];
int at[10],in[10];
int n,m;
char s1[10],s2[10];
bool check(){
	For(i,1,(1<<m)-2){
		int SE=0,SV=0;
		For(j,0,m-1)
			if (i&(1<<j)) SV+=cnt[j+1];
		For(j,0,m-1) For(k,j,m-1)
			if ((i&(1<<j))||(i&(1<<k)))
				SE+=e[j+1][k+1];
		//printf("%d %d %d\n",i,SE,SV);
		if (SE<SV) return 0;
	}
	return 1;
}
int main(){
	scanf("%d",&n);
	For(i,1,n-1){
		scanf("%s%s",s1+1,s2+1);
		int l1=strlen(s1+1);
		int l2=strlen(s2+1);
		e[l1][l2]++;
		if (l1!=l2)
			e[l2][l1]++;
	}
	at[1]=1;
	For(i,2,6) at[i]=at[i-1]*10;
	for (int x=n;x;x/=10,++m);
	For(i,1,m-1) cnt[i]=at[i+1]-at[i];
	cnt[m]=n-at[m]+1;
	if (!check()) return puts("-1"),0;
	cnt[1]--; at[1]++; in[1]=1;
	int ans=0;
	for (;ans<n-1;){
		For(i,1,m) if (in[i])
			For(j,1,m) if (e[i][j]&&cnt[j]){
				--e[i][j]; --cnt[j];
				if (i!=j) --e[j][i];
				if (check()){
					printf("%d %d\n",at[i]-1,at[j]);
					++at[j]; in[j]=1; ++ans;
				}
				else{
					++e[i][j]; ++cnt[j];
					if (i!=j) ++e[j][i];
				}
			}
	}
}