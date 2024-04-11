#include<bits/stdc++.h>
using namespace std;
const int N=105;
int e[N][N];
int q[N],n;
int Q1(int x,int y){
	cout<<1<<' '<<x<<' '<<y<<endl;
	cin>>x;
	return x;
}
int Q2(int x,int y){
	cout<<2<<' '<<x<<' '<<y+1;
	for (int i=0;i<=y;i++)
		cout<<' '<<q[i];
	cout<<endl;
	cin>>x;
	return x;
}
void solve(){
	scanf("%d",&n);
	q[0]=0;
	for (int i=1;i<n;i++){
		int p=-1;
		if (Q1(i,q[0])) p=0;
		else if (Q1(q[i-1],i)) p=i;
		else{
			int l=0,r=i-1;
			while (l<=r){
				int mid=(l+r)/2;
				if (Q1(q[mid],i))
					p=mid+1,l=mid+1;
				else
					r=mid-1;
			}
		}
		for (int j=i;j>p;j--)
			q[j]=q[j-1];
		q[p]=i;
	}
	
	memset(e,0,sizeof(e));
	for (int i=0;i<n;i++)
		for (int j=i;j<n;j++)
			e[q[i]][q[j]]=1;
	int l=n-2;
	for (int i=n-1;i>=1;i--){
		if (l==i) --l;
		for (;l>=0&&Q2(q[i],l);--l);
		for (int j=l+1;j<i;j++) e[q[i]][q[j]]=1;
	}
	for (int k=0;k<n;k++)
		for (int i=0;i<n;i++)
			for (int j=0;j<n;j++)
				e[i][j]|=e[i][k]&e[k][j];
	printf("3\n");
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++)
			printf("%d",e[i][j]);
		puts("");
	}
	fflush(stdout);
	int OK;
	scanf("%d",&OK);
	assert(OK==1);
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}