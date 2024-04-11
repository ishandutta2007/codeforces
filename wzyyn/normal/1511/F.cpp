#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define pii pair<int,int>
#define fi first
#define se second
#define PB push_back
#define ll long long
#define ull unsigned long long
#define pll pair<ll,ll> 
#define y1 orzkcz
using namespace std;

const int mo=998244353;
int n,m,nd=1,md,ed[50],mi[50];
int ch[50][26],idx[50][50];

struct Mat{
	int a[563][563];
	Mat(){
		memset(a,0,sizeof(a));
	}
	Mat operator *(const Mat &b)const{
		Mat c;
		for (int i=1;i<=md;i++)
			for (int j=1;j<=md;j++)
				if (a[i][j])
					for (int k=1;k<=md;k++)
						c.a[i][k]=(c.a[i][k]+1ll*a[i][j]*b.a[j][k])%mo;
		return c;
	}
}tr,S;
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		char s[16];
		scanf("%s",s+1);
		int x=1;
		for (int j=1;s[j];++j){
			if (!ch[x][s[j]-'a'])
				ch[x][s[j]-'a']=++nd;
			mi[x]=1;
			x=ch[x][s[j]-'a'];
		}
		ed[x]=1;
	}
	for (int i=1;i<=nd;i++)
		for (int j=i;j<=nd;j++)
			if (mi[i]&&mi[j]) idx[i][j]=++md;
	for (int i=1;i<=nd;i++)
		for (int j=i;j<=nd;j++)
			for (int c=0;c<=25;c++){
				if (!ch[i][c]||!ch[j][c]) continue;
				int ni=ch[i][c],nj=ch[j][c];
				++tr.a[idx[i][j]][idx[min(ni,nj)][max(ni,nj)]];
				if (ed[ni]) ++tr.a[idx[i][j]][idx[1][nj]];
				if (ed[nj]) ++tr.a[idx[i][j]][idx[1][ni]];
				if (ed[ni]&&ed[nj]) ++tr.a[idx[i][j]][idx[1][1]];
			}
	S=tr; --m;
	for (;m;m/=2,tr=tr*tr)
		if (m&1) S=S*tr;
	printf("%d\n",S.a[1][1]);
}