#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=210000;
struct atom{
	int where,pd,w;
}x[N<<1];
int compare(atom k1,atom k2){
 	return k1.w<k2.w;
}
int len,l[N],r[N],n,m;
int ma[N<<2][2][2],t[N<<2][2][2],A[N<<2][2],B[N<<2][2],C[N<<2][2],y[N];
long long tot[N<<2][2][2];
void add(int k1,int k2,int k3,int k4,int k5,int k6,int k7){
	ma[k1][0][0]+=k2; ma[k1][1][0]+=k2;
	ma[k1][0][1]+=k3; ma[k1][1][1]+=k3;
	ma[k1][0][0]+=k4; ma[k1][1][1]+=k4;
	ma[k1][0][1]+=k5; ma[k1][1][0]+=k5;
	ma[k1][0][0]+=k6; ma[k1][0][1]+=k6;
	ma[k1][1][0]+=k7; ma[k1][1][1]+=k7;
	A[k1][0]+=k2; A[k1][1]+=k3;
	B[k1][0]+=k4; B[k1][1]+=k5;
	C[k1][0]+=k6; C[k1][1]+=k7;
}
void pushdown(int k1){
	int flag=0;
	if (A[k1][0]==0&&A[k1][1]==0&&B[k1][0]==0&&B[k1][1]==0&&C[k1][0]==0&&C[k1][1]==0) return;
	add(k1*2,A[k1][0],A[k1][1],B[k1][0],B[k1][1],C[k1][0],C[k1][1]);
	add(k1*2+1,A[k1][0],A[k1][1],B[k1][0],B[k1][1],C[k1][0],C[k1][1]);
	memset(A[k1],0x00,sizeof A[k1]);
	memset(B[k1],0x00,sizeof B[k1]);
	memset(C[k1],0x00,sizeof C[k1]);
}
void change(int k1){
	int l=k1*2,r=k1*2+1;
	for (int i=0;i<2;i++)
		for (int j=0;j<2;j++)
			if (ma[l][i][j]>ma[r][i][j]){
				ma[k1][i][j]=ma[l][i][j];
				t[k1][i][j]=t[l][i][j];
				tot[k1][i][j]=tot[l][i][j];
			} else if (ma[l][i][j]<ma[r][i][j]){
				ma[k1][i][j]=ma[r][i][j];
				t[k1][i][j]=t[r][i][j];
				tot[k1][i][j]=tot[r][i][j];
			} else {
				ma[k1][i][j]=ma[r][i][j];
				t[k1][i][j]=t[l][i][j]+t[r][i][j];
				tot[k1][i][j]=tot[l][i][j]+tot[r][i][j];
			}
//	cout<<"asd "<<k1<<" "<<t[k1][0][0]<<endl;
}
void add(int k1,int k2,int k3,int k4,int k5,int k6,int k7,int k8,int k9,int k10=0,int k11=0){
	//if (k2>=4&&k3<=5) cout<<"asd "<<k1<<" "<<k2<<" "<<k3<<" "<<k4<<" "<<k5<<" "<<k6<<" "<<k7<<" "<<k8<<" "<<k9<<" "<<k10<<" "<<k11<<endl;
	if (k2>k5||k3<k4) return;
	if (k2>=k4&&k3<=k5){
		add(k1,k6,k7,k8,k9,k10,k11); return;
	}
	int mid=k2+k3>>1; pushdown(k1);
	add(k1*2,k2,mid,k4,k5,k6,k7,k8,k9,k10,k11);
	add(k1*2+1,mid+1,k3,k4,k5,k6,k7,k8,k9,k10,k11);
	change(k1);
}
long long find(int k1,int k2,int k3,int k4,int k5,int k6,int k7){
	if (k2>k5||k3<k4) return 0;
	if (k2>=k4&&k3<=k5){
		long long ans=0;
		for (int i=0;i<2;i++){
			if (ma[k1][k6][i]==m){
			//	cout<<"asd "<<k1<<" "<<k2<<" "<<k3<<" "<<k6<<" "<<i<<" "<<tot[k1][k6][i]<<" "<<t[k1][k6][i]<<endl;
				ans+=tot[k1][k6][i]-1ll*(k7-1)*t[k1][k6][i];
			}
		}
		return ans; 
	}
	int mid=k2+k3>>1; pushdown(k1);
	return find(k1*2,k2,mid,k4,k5,k6,k7)+find(k1*2+1,mid+1,k3,k4,k5,k6,k7);
}
void buildtree(int k1,int k2,int k3){
	if (k2==k3){
		t[k1][0][k2&1]=1; t[k1][1][k2&1]=1; tot[k1][0][k2&1]=k2; tot[k1][1][k2&1]=k2; 
		ma[k1][0][k2&1]=0; ma[k1][1][k2&1]=0; ma[k1][0][(k2&1)^1]=ma[k1][1][(k2&1)^1]=-1e9; return;
	}
	int mid=k2+k3>>1;
	buildtree(k1*2,k2,mid);
	buildtree(k1*2+1,mid+1,k3);
	change(k1);
}
int main(){
	scanf("%d%d",&m,&n);
	for (int i=1;i<=m;i++){
		scanf("%d%d",&l[i],&r[i]);
		len++; x[len]=(atom){i,0,l[i]};
		len++; x[len]=(atom){i,1,r[i]+1};
	}
	buildtree(1,1,n);
	for (int i=1;i<=m;i++)
		if (l[i]&1){
			add(1,1,n,l[i],r[i],0,1,0,0);
			add(1,1,n,1,l[i]-1,1,1,0,0);
			if ((r[i]-l[i]+1)&1) add(1,1,n,r[i]+1,n,1,1,0,0);
		} else{
			add(1,1,n,l[i],r[i],1,0,0,0);
			add(1,1,n,1,l[i]-1,1,1,0,0);
			if ((r[i]-l[i]+1)&1) add(1,1,n,r[i]+1,n,1,1,0,0);
		}
	sort(x+1,x+len+1,compare);
	int now=1; long long ans=0;
	for (int i=1;i<=n;i++){
		while (now<=len&&x[now].w==i){
		//	cout<<"fa"<<endl;
			if (x[now].pd==0){
			//	cout<<"fa"<<endl;
				int L=l[x[now].where],R=r[x[now].where];
				if (L&1){
					add(1,1,n,L,R,0,-1,0,0);
					add(1,1,n,1,L-1,-1,-1,0,0);
					if ((R-L+1)&1) add(1,1,n,R+1,n,-1,-1,0,0);
				} else {
					add(1,1,n,L,R,-1,0,0,0);
					add(1,1,n,1,L-1,-1,-1,0,0);
					if ((R-L+1)&1) add(1,1,n,R+1,n,-1,-1,0,0);
				}
				add(1,1,n,L,R,0,0,1,0);
				if (R&1) add(1,1,n,R+1,n,0,0,0,0,0,1);
				else add(1,1,n,R+1,n,0,0,0,0,1,0);
			} else {
				int R=r[x[now].where];
				if (R&1) add(1,1,n,R+1,n,1,1,0,0,0,-1);
				else add(1,1,n,R+1,n,1,1,0,0,-1,0);
			}
			now++;
		}
		ans+=find(1,1,n,i,n,i&1,i);
	//	cout<<"fa "<<ans<<endl;
	}
	for (int i=1;i<=n;i++) y[l[i]]++,y[r[i]+1]--;
	for (int i=1;i<=n;i++) y[i]+=y[i-1];
	int pre=0;
	for (int i=1;i<=n+1;i++)
		if (i==n+1||y[i]){
			int L=i-pre-1;
			for (int j=1;j<=L;j++) ans-=1ll*j*(L-j+1);
			pre=i;
		}
	cout<<ans<<endl;
}