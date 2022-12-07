#include<bits/stdc++.h>
using namespace std;

const int N=500005;
char s[N];
int n,cnt[N],x[N],y[N],k;
int SA[N],rk[N],lg[N];
int st[N][21];

bool cmp(int i,int j,int k){
	return y[i]!=y[j]||(i+k>n?-1:y[i+k])!=(j+k>n?-1:y[j+k]);
}
void build_SA(){
	int m=26;
	for (int i=1;i<=n;i++)
		++cnt[x[i]=s[i]-'a'+1];
	for (int i=1;i<=m;i++)
		cnt[i]+=cnt[i-1];
	for (int i=n;i>=1;i--)
		SA[cnt[x[i]]--]=i;
	for (int k=1;k<n;k<<=1){
		int p=0;
		for (int i=n-k+1;i<=n;i++) y[++p]=i;
		for (int i=1;i<=n;i++)
			if (SA[i]>k) y[++p]=SA[i]-k;
		for (int i=0;i<=m;i++) cnt[i]=0;
		for (int i=1;i<=n;i++) cnt[x[y[i]]]++;
		for (int i=1;i<=m;i++) cnt[i]+=cnt[i-1];
		for (int i=n;i>=1;i--) SA[cnt[x[y[i]]]--]=y[i];
		swap(x,y); m=x[SA[1]]=1;
		for (int i=2;i<=n;i++)
			x[SA[i]]=(m+=cmp(SA[i-1],SA[i],k));
		if (m==n) break;
	}
	for (int i=1;i<=n;i++) rk[SA[i]]=i;//cout<<SA[i]<<endl;
	for (int i=2;i<=n;i++) lg[i]=lg[i/2]+1;
	for (int p=0,i=1;i<=n;i++)
		if (rk[i]!=1){
			p-=(p!=0);
			for (;s[i+p]==s[SA[rk[i]-1]+p];++p);
			st[rk[i]][0]=p;
		}
	for (int i=1;i<=18;i++)
		for (int j=1;j+(1<<i)-1<=n;j++)
			st[j][i]=min(st[j][i-1],st[j+(1<<(i-1))][i-1]); 
}

int LCP(int x,int y){
	x=rk[x]; y=rk[y];
	if (x>y) swap(x,y);
	int k=lg[y-(++x)+1];
	return min(st[x][k],st[y-(1<<k)+1][k]);
}
int id[N];
bool cmp2(int x,int y){
	bool fl=0;
	if (x>y) swap(x,y),fl^=1;
	int l1=LCP(1,x+1);
	//cout<<l1<<endl;
	if (x+1+l1<=y) return (s[1+l1]<s[x+1+l1])^fl;
	int l2=LCP(1,y-x+1);
	//cout<<l2<<endl;
	if ((y-x+1)+l2<=y) return (s[(y-x+1)+l2]<s[1+l2])^fl; 
	return fl;
}
int main(){
	scanf("%d%d",&n,&k);
	scanf("%s",s+1);
	build_SA();
	
	for (int i=1;i<=n;i++) id[i]=i;
	//puts(cmp2(1,2)?"1":"2");
	sort(id+1,id+n+1,cmp2);
	
	int p=id[1];
	for (int i=1;i<=k;i++)
		putchar(s[(i-1)%p+1]);
}