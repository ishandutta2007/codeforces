#include<bits/stdc++.h>

using namespace std;

const int mo1=998244353;
const int mo2=1000000007;
long long n;
int a[15],b[15],ans;

long long dig(int *b,int l){
	long long re=0;
	for (int i=1;i<=l;i++)
		re=re*10+b[i];
	return re;
}
long long Rank(int *b,int l){
	long long ans=0;
	for (int di=1;di<=*a;di++){
		for (int i=1;i<=min(l,di);i++){
			for (int j=(i==1?1:0);j<b[i];j++){
				long long numl=0,numr=0;
				for (int p=1;p<i;p++)
					numl=numr=numl*10+b[p];
				numl=numr=numl*10+j;
				for (int p=i+1;p<=di;p++)
					numl=numl*10,numr=numr*10+9;
				numr=min(numr,n);
				if (numl<=numr)
					ans+=numr-numl+1;
			}
		}
		if (di<=l) ++ans;
	}
	return ans;
}
int F(int *a,int di){
	return ((-dig(a,di)+Rank(a,di))%mo1+mo1)%mo1;
}

int dif[15];
int q1[1000010];
int q2[1000010];
long long sq2[1000010];
void dfs(int t,int ed,int *q,int v){
	if (t==ed){
		for (int i=0;i<=9;i++)
			q[++*q]=(v+1ll*i*dif[t])%mo1;
		return;
	}
	for (int i=0;i<=9;i++)
		dfs(t+1,ed,q,(v+1ll*i*dif[t])%mo1);
}
void update(int di,int i,int j){
	memcpy(b,a,sizeof(b));
	b[i]=j;
	for (int p=i+1;p<=di;p++) b[p]=0;
	int bas=F(b,di);
	for (int p=i+1;p<=di;p++){
		b[p]=1;
		dif[p]=(F(b,di)+mo1-bas)%mo1;
		b[p]=0;
	}
	if (di-i==0){
		ans=(ans+bas)%mo2;
		//cout<<"UPD1 "<<di<<' '<<i<<' '<<j<<' '<<ans<<' '<<bas<<endl;
		return;
	}
	if (di-i==1){
		for (int p=0;p<=9;p++)
			ans=(ans+(bas+1ll*p*dif[di])%mo1)%mo2;
		//cout<<"UPD2 "<<di<<' '<<i<<' '<<j<<' '<<ans<<' '<<bas<<' '<<dif[di]<<endl;
		return;
	}
	int mid=(di+i)/2;
	*q1=*q2=0;
	dfs(i+1,mid,q1,bas);
	dfs(mid+1,di,q2,0);
	sort(q2+1,q2+*q2+1);
	int sq2=0;
	for (int i=1;i<=*q2;i++)
		sq2=(sq2+q2[i])%mo2;
	for (int i=1;i<=*q1;i++){
		int p=lower_bound(q2+1,q2+*q2+1,mo1-q1[i])-q2;
		ans=(ans+sq2+1ll*(*q2)*q1[i])%mo2;
		ans=(ans+1ll*((*q2)-p+1)*(mo2-mo1))%mo2;
	}
	//cout<<"UPD "<<di<<' '<<i<<' '<<j<<' '<<ans<<endl;
}
int main(){
	scanf("%lld",&n);
	for (long long m=n;m;a[++*a]=m%10,m/=10);
	reverse(a+1,a+*a+1);
	for (int di=1;di<=*a;di++){
		for (int i=1;i<=di;i++){
			int l=(i==1?1:0);
			int r=(di==*a?a[i]-1:9);
			for (int j=l;j<=r;j++)
				if (j!=a[i]) update(di,i,j);
		}
		ans=(ans+F(a,di))%mo2;
		//cout<<"spe "<<di<<' '<<ans<<endl;
	}
	cout<<ans<<endl;
}