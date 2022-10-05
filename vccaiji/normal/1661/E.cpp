#include<bits/stdc++.h>
using namespace std;
int n,q;
char s[3][510000];
int fa[1510000];
int k;
int find(int u){
	if(fa[u]==u)return u;
	return find(fa[u]);
}
void merge(int u,int v){
	u=find(u);
	v=find(v);
	if(u==v)return;
	k++;
	fa[u]=v;
}
int p[510000];
int o[510000];
int ll[510000],rr[510000];
int rrr[510000],lll[510000];
int main(){
	cin>>n;
	scanf("%s%s%s",s[0]+1,s[1]+1,s[2]+1);
	int num=0;
	for(int i=1;i<=3*n;i++)fa[i]=i;
	o[0]=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=2;j++)if(s[j][i]=='1')num++;
		if(s[0][i]=='1'&&s[1][i]=='1')merge(i,i+n);
		if(s[2][i]=='1'&&s[1][i]=='1')merge(i+2*n,i+n);
		if(i>1){
			for(int j=0;j<=2;j++)if(s[j][i]=='1'&&s[j][i-1]=='1')merge(i+j*n,i-1+j*n);
		}
		o[i]=num-k;
	}
	for(int i=1;i<=n;i++)if(s[0][i]=='1'&&s[1][i]=='1'&&s[2][i]=='1')p[i]=1;
	int now=n+1;
	for(int j=n;j>=1;j--){
		if(p[j])now=j;
		rr[j]=now;
	} 
	now=0;
	for(int j=1;j<=n;j++){
		if(p[j])now=j;
		ll[j]=now;
	}
	now=n+1;
	for(int j=n;j>=1;j--){
		if(s[0][j]=='0'||s[2][j]=='0')now=j;
		rrr[j]=now;
	} 
	now=0;
	for(int j=1;j<=n;j++){
		if(s[0][j]=='0'||s[2][j]=='0')now=j;
		lll[j]=now;
	}
	cin>>q;
	for(int i=1;i<=q;i++){
		int l,r;
		cin>>l>>r;
		if(l==1){
			cout<<o[r]<<endl;
			continue;
		}
		int u=0;
		for(int j=0;j<=2;j++)if(s[j][l-1]=='1'&&s[j][l]=='1')u^=(1<<j);
		if(u==0){
			cout<<o[r]-o[l-1]<<endl;
			continue;
		}
		if(u==5){
			if(rr[l]<=rrr[l]&&rr[l]<=r&&ll[l-1]&&ll[l-1]>=lll[l-1])cout<<o[r]-o[l-1]+1<<endl;
			else cout<<o[r]-o[l-1]+2<<endl;
			continue;
		}
		cout<<o[r]-o[l-1]+1<<endl;
	}
	return 0;
}