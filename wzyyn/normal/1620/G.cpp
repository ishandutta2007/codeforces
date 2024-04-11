#include<bits/stdc++.h>

using namespace std;

const int N=20005;
const int M=(1<<23)|5;
const int mo=998244353;
int n;
char s[N];
int a[30][30],id[30];
int bic[M],way[M];
int main(){
	scanf("%d",&n);
	for (int i=0;i<n;i++){
		scanf("%s",s+1);
		int l=strlen(s+1);
		for (int j=1;j<=l;j++)
			++a[i][s[j]-'a'];
	}
	for (int i=1;i<1<<n;i++)
		bic[i]=bic[i/2]+(i&1);
	for (int i=0;i<1<<n;i++)
		way[i]=1;
	for (int k=0;k<26;k++){
		for (int i=0;i<n;i++) id[i]=i;
		for (int i=0;i<n;i++)
			for (int j=i+1;j<n;j++)
				if (a[id[i]][k]>a[id[j]][k])
					swap(id[i],id[j]);
		int msk=(1<<n)-1;
		for (int i=0;i<n;i++){
			int x=id[i],v=a[x][k]; msk-=1<<x;
			for (int j=msk;;j=(j-1)&msk){
				way[j|(1<<x)]=1ll*way[j|(1<<x)]*(v+1)%mo;
				if (!j) break;
			}
		}
	}
	way[0]=0;
	for (int i=1;i<1<<n;i++)
		if (bic[i]%2==0) way[i]=(mo-way[i])%mo;
	for (int d=1;d<1<<n;d<<=1)
		for (int i=0;i<1<<n;i+=(d<<1))
			for (int j=0;j<d;j++)
				way[i+j+d]=(way[i+j+d]+way[i+j])%mo;
	long long ans=0;
	for (int i=1;i<1<<n;i++){
		//cout<<i<<' '<<way[i]<<endl;
		int s1=0,s2=0;
		for (int j=0;j<n;j++) if (i&(1<<j)) s1++,s2+=j+1;
		ans^=1ll*s1*s2*way[i];
	}
	cout<<ans<<endl;
}