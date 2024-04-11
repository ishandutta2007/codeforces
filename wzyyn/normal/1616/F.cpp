#include<bits/stdc++.h>

using namespace std;

const int M=520;
const int N=70;
bitset<M> M1,M2;
int id[N][N],n,m,v[M];
void init(){
	for (int i=2;i<M;i+=2) M1[i]=1;
	for (int i=3;i<M;i+=2) M2[i]=1;
}
bitset<M> b[M];
bool insert(int i1,int i2,int i3){
	//cout<<"INS"<<i1<<' '<<i2<<' '<<i3<<endl;
	b[0].reset();
	bitset<M> m0,m1,m2;
	bitset<M> n0,n1,n2;
	b[0][2*i1]=b[0][2*i2]=b[0][2*i3]=1;
	for (int i=1;i<=m;i++)
		if (b[0][2*i]||b[0][2*i+1]){
			if (b[0][2*i+1]){
				m1=b[0]&M1,m2=b[0]&M2;
				b[0]=(m1<<1)|(m2>>1);
			}
			if (b[i][2*i]){
				m1=b[0]&M1,m2=(b[0]&M2)>>1;
				
				n1=b[i]&M1;
				m0=M1^m1^m2;
				m1=m1^((m1^m2)&n1);
				m2=m2^((m2^m0)&n1);
				
				n1=(b[i]&M2)>>1;
				m0=M1^m1^m2;
				m2=m2^((m1^m2)&n1);
				m1=m1^((m1^m0)&n1);
				b[0]=m1|(m2<<1);
			}
			else{
				b[i]=b[0];
				return 1;
			}
		}
	if (b[0][2*(m+1)+0]||b[0][2*(m+1)+1])
		return 0;
	return 1;
}
void solve(){
	memset(id,0,sizeof(id));
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m+1;i++)
		b[i].reset();
	for (int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d%d",&x,&y,&v[i]);
		id[x][y]=id[y][x]=i;
		if (v[i]!=-1){
			b[i][2*i]=1;
			if (v[i]==1) b[i][2*(m+1)+0]=1;
			if (v[i]==2) b[i][2*(m+1)+1]=1;
		}
	}
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++)
			for (int k=j+1;k<=n;k++){
				int a=id[i][j],b=id[i][k],c=id[j][k];
				if (!a||!b||!c) continue;
				if (!insert(a,b,c)) return puts("-1"),void(0); 
			}
	for (int i=m;i>=1;i--){
		if (b[i][2*i]){
			v[i]=0;
			if (b[i][2*(m+1)+0]) v[i]=1;
			if (b[i][2*(m+1)+1]) v[i]=2;
			for (int j=i+1;j<=m;j++){
				if (b[i][2*j+0]) v[i]=(v[i]+3-v[j])%3;
				if (b[i][2*j+1]) v[i]=(v[i]+6-2*v[j])%3;
			}
		}
		else
			v[i]=0;
	}
	for (int i=1;i<=m;i++)
		printf("%d%c",v[i]?v[i]:3,i==m?'\n':' ');
}
int main(){
	init();
	int T;
	scanf("%d",&T);
	while (T--) solve();
}
/*

*/