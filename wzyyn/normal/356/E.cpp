#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
#define y1 ysghysgsygsh
using namespace std;
const int N=100005;
char s[N];
int n,l[20];
int SA[N],rk[N];
int x[N],y[N],cnt[N];
int lg[N],st[18][N];
bool cmp(int i,int j,int k){
	return y[i]!=y[j]||((i+k>n?-1:y[i+k])!=(j+k>n?-1:y[j+k]));
}
void init_SA(){
	int m=26;
	For(i,1,n) cnt[x[i]=s[i]-'a'+1]++;
	For(i,1,m) cnt[i]+=cnt[i-1];
	Rep(i,n,1) SA[cnt[x[i]]--]=i;
	for (int k=1;k<=n;k<<=1){
		int p=0;
		For(i,n-k+1,n) y[++p]=i;
		For(i,1,n) if (SA[i]>k) y[++p]=SA[i]-k;
		For(i,0,m) cnt[i]=0;
		For(i,1,n) cnt[x[y[i]]]++;
		For(i,1,m) cnt[i]+=cnt[i-1];
		Rep(i,n,1) SA[cnt[x[y[i]]]--]=y[i];
		swap(x,y); m=x[SA[1]]=1;
		For(i,2,n) x[SA[i]]=(m+=cmp(SA[i],SA[i-1],k));
	}
	//For(i,1,n) cout<<SA[i]<<endl;
	For(i,1,n) rk[SA[i]]=i;
	int p=0;
	For(i,1,n) if (rk[i]!=1){
		for (p-=(p!=0);s[i+p]==s[SA[rk[i]-1]+p];++p);
		st[0][rk[i]]=p;
	}
	For(i,2,n) lg[i]=lg[i/2]+1;
	For(i,1,16) For(j,1,n-(1<<i)+1)
		st[i][j]=min(st[i-1][j],st[i-1][j+(1<<(i-1))]);
}
int LCP(int x,int y){
	x=rk[x]; y=rk[y];
	if (x>y) swap(x,y);
	int k=lg[y-(++x)+1];
	return min(st[k][x],st[k][y-(1<<k)+1]);
}
int pr[N][26];
int fl[16][N];
ll S1[N],S2[N][26],ans;
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	init_SA();
	//printf("%d\n",LCP(2,4));
	For(i,1,n) For(j,0,25)
		pr[i][j]=(j+'a'==s[i]?i:pr[i-1][j]);
	For(i,0,15) l[i]=(1<<(i+1))-1;
	For(i,1,n) fl[0][i]=1;
	For(i,1,15) For(j,1,n-l[i]+1)
		if (fl[i-1][j]&&fl[i-1][j+(1<<i)]&&LCP(j,j+(1<<i))>=l[i-1])
			//cout<<i<<' '<<j<<endl;
			if (pr[j+l[i-1]-1][s[j+(1<<i)-1]-'a']<j)
				if (pr[j+l[i]-1][s[j+(1<<i)-1]-'a']<j+(1<<i))
					fl[i][j]=1;
	For(i,0,15) For(j,1,n-l[i]+1)
		if (fl[i][j]){
			ans+=1ll*l[i]*l[i];
			S1[j]+=1ll*l[i]*l[i];
			S1[j+l[i]]-=1ll*l[i]*l[i];
			//cout<<i<<' '<<j<<endl;
		}
	For(i,1,n) S1[i]+=S1[i-1];
	//For(i,1,n) cout<<S1[i]<<endl;
	For(i,1,15) For(j,1,n-l[i]+1)
		if (fl[i-1][j]&&fl[i-1][j+(1<<i)]&&LCP(j,j+(1<<i))>=l[i-1])
			For(k,0,25) if (pr[j+l[i-1]-1][k]<j&&pr[j+l[i]-1][k]<j+(1<<i))
				S2[j+(1<<i)-1][k]+=1ll*l[i]*l[i];
	For(i,1,15) For(j,1,n-l[i]+1)
		if (fl[i-1][j]&&pr[j+l[i-1]-1][s[j+(1<<i)-1]-'a']<j){
			//cout<<i<<' '<<j<<endl;
			int L1=LCP(j,j+(1<<i));
			if (L1>=l[i-1]) continue;
			int L2=LCP(j+L1+1,j+L1+1+(1<<i));
			if (L1+L2+1<l[i-1]) continue;
			S2[j+L1+(1<<i)][s[j+L1]-'a']+=1ll*l[i]*l[i];
		}
	For(i,1,15) For(j,1,n-l[i]+1)
		if (fl[i-1][j+(1<<i)]&&pr[j+l[i]-1][s[j+(1<<i)-1]-'a']<j+(1<<i)){
			//cout<<i<<' '<<j<<endl;
			int L1=LCP(j,j+(1<<i));
			if (L1>=l[i-1]) continue;
			int L2=LCP(j+L1+1,j+L1+1+(1<<i));
			if (L1+L2+1<l[i-1]) continue;
			S2[j+L1][s[j+L1+(1<<i)]-'a']+=1ll*l[i]*l[i];
		}
	ll dif=0;
	For(i,1,n) For(j,0,25)
		dif=max(dif,S2[i][j]+1-S1[i]);
	printf("%lld\n",dif+ans);
}
/*
cbbbc
*/