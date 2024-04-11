#include<bits/stdc++.h>

using namespace std;

int n,k,a[505],id[505];

bool cmp(int x,int y){
	return a[x]>a[y];
}
void con(int s,int mx){
	int rnd=s/k;
	for (int i=1;i<=n;i++){
		a[i]=mx-2;
		s-=(mx-2);
		id[i]=i;
	}
	for (int i=1;i<=n;i++)
		if (s){
			a[i]+=2;
			s-=2;
		}
	int ans=0,x;
	for (int i=1;i<=rnd;i++){
		sort(id+1,id+n+1,cmp);
		printf("?");
		for (int j=1;j<=k;j++){
			printf(" %d",id[j]);
			a[id[j]]--;
		}
		puts("");
		fflush(stdout);
		scanf("%d",&x);
		ans^=x;
	}
	cout<<"! "<<ans<<endl;
	exit(0);
}
int main(){
	scanf("%d%d",&n,&k);
	if (n%2==1&&k%2==0){
		puts("-1");
		return 0;
	}
	int mx=1,s=n;
	for (int i=1;i<=500000;i++){
		if (s%k==0&&mx<=s/k){
			con(s,mx);
		}
		s+=2;
		if (mx*n<s) mx+=2;
	}
	puts("-1");
}