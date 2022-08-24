#include <bits/stdc++.h>
using namespace std;
struct bian{
	int next,point;
}b[410000];
int p[210000],len,pd[210000],size[210000],n,now,where,w[210000];
long long tot[210000],ans[210000];
char ch[210000];

void ade(int k1,int k2){
	b[++len]=(bian){p[k1],k2}; p[k1]=len;
}
void add(int k1,int k2){
	ade(k1,k2); ade(k2,k1);
}
int dfs1(int k1,int k2){
	size[k1]=1; ans[k1]=0;
	for (int i=p[k1];i;i=b[i].next){
		int j=b[i].point;
		if (j!=k2&&pd[j]==0) size[k1]+=dfs1(j,k1);
	}
	return size[k1];
}
void dfs2(int k1,int k2){
	int num=n-size[k1];
	for (int i=p[k1];i;i=b[i].next){
		int j=b[i].point;
		if (j!=k2&&pd[j]==0){
			dfs2(j,k1); num=max(num,size[j]);
		}
	}
	if (num<now){
		now=num; where=k1;
	}
} 
int M[1<<20],bo[1<<20],sign;
int find(int k){
	if (bo[k]!=sign){
		M[k]=0; bo[k]=sign;
	}
	return M[k];
}
void add1(int k1,int k2){
	if (bo[k1]!=sign){
		bo[k1]=sign; M[k1]=0;
	}
	M[k1]+=k2;
}
int query(int w){
	int ans=find(w);
	for (int i=0;i<20;i++) ans+=find(w^(1<<i));
	return ans;
}
void add(int k1,int k2,int k3){
	add1(k3,1);
	for (int i=p[k1];i;i=b[i].next){
		int j=b[i].point;
		if (j!=k2&&pd[j]==0) add(j,k1,k3^w[j]);
	}
}
void getans(int k1,int k2,int k3,int k4){
	ans[k1]+=query(k3)*k4;
	for (int i=p[k1];i;i=b[i].next){
		int j=b[i].point;
		if (j!=k2&&pd[j]==0) getans(j,k1,k3^w[j],k4);
	}
}
void getpre(int k1,int k2){
	for (int i=p[k1];i;i=b[i].next){
		int j=b[i].point;
		if (pd[j]==0&&j!=k2){
			getpre(j,k1); ans[k1]+=ans[j];
		}
	}
	if (k2==0) ans[k1]=(ans[k1]+1)/2;
	tot[k1]+=ans[k1];
}
void solve(int k1){
	n=dfs1(k1,0); now=n; dfs2(k1,0); int k=where; pd[k]=1;
	//cout<<"solve in "<<k<<" "<<k1<<endl;
	sign++; add1(0,1);
	for (int i=p[k];i;i=b[i].next){
		int j=b[i].point;
		if (pd[j]==0) add(j,k,w[j]);
	}
	ans[k]+=query(w[k]);
	for (int i=p[k];i;i=b[i].next){
		int j=b[i].point;
		if (pd[j]==0) getans(j,k,w[k]^w[j],1);
	}
	//for (int i=1;i<=5;i++) cout<<ans[i]<<" "; cout<<endl;
	for (int i=p[k];i;i=b[i].next){
		int j=b[i].point;
		if (pd[j]==0){
			sign++; add(j,k,w[j]);
			getans(j,k,w[k]^w[j],-1);
		}
	}
	//for (int i=1;i<=5;i++) cout<<ans[i]<<" "; cout<<endl;
	getpre(k,0);
	//for (int i=1;i<=5;i++) cout<<tot[i]<<" "; cout<<endl;
	for (int i=p[k];i;i=b[i].next){
		int j=b[i].point;
		if (pd[j]==0) solve(j);
	}
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<n;i++){
		int k1,k2; scanf("%d%d",&k1,&k2); add(k1,k2);
	}
	scanf("%s",ch+1);
	for (int i=1;i<=n;i++) w[i]=(1<<ch[i]-'a');
	int pren=n;
	solve(1);
	for (int i=1;i<=pren;i++) printf("%I64d ",tot[i]);
	return 0;
}