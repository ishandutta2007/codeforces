#include<bits/stdc++.h>
using namespace std;

char s[200005][65];
int n,m,p,ansv;
long long ans;

int a[50005];
void update(){
	memset(a,0,sizeof(a));
	int p=(32768ll*rand()+rand())%n+1;
	for (int i=1;i<=n;i++){
		int S=0,x=0;
		for (int j=1;j<=m;j++)
			if (s[p][j]=='1'){
				if (s[i][j]=='1') S|=1<<x;
				++x;
			}
		++a[S];
	}
	for (int i=0;i<15;i++)
		for (int j=0;j<1<<15;j++)
			if (j&(1<<i))
				a[j^(1<<i)]+=a[j];
	for (int i=0;i<1<<15;i++)
		if (a[i]*2>=n){
			long long s1=0;
			int s2=0,x=0;
			for (int j=1;j<=m;j++)
				if (s[p][j]=='1'){
					s1|=(((1ll*i)>>x)&1)<<(j-1);
					s2+=((i>>x)&1);
					++x;
				}
			if (s2>=ansv){
				ansv=s2;
				ans=s1;
			}
		}
}
int main(){
	srand(time(NULL));
	scanf("%d%d%d",&n,&m,&p);
	for (int i=1;i<=n;i++)
		scanf("%s",s[i]+1);
	for (int T=1;T<=20;T++)
		update();
	for (int i=0;i<m;i++)
		putchar((ans>>i)&1?'1':'0');
}