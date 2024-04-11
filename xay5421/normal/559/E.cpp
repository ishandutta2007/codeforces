#include<bits/stdc++.h>
using namespace std;
const int N=105; 
int n,f[N][N][2];
struct data{int a,len;}A[N];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d%d",&A[i].a,&A[i].len);
	sort(A+1,A+1+n,[&](data k1,data k2){return k1.a<k2.a;});
	int ans=0;A[0].a=-1e8;
	for(int i=0;i<=n;++i)for(int j=0;j<=i;++j)for(int k=0;k<=1;++k){
		ans=max(ans,f[i][j][k]);
//		printf("f[%d][%d][%d]=%d\n",i,j,k,f[i][j][k]);
		int r=A[j].a+k*A[j].len,mx=-1e8,_j,_k;
		for(int _i=i+1;_i<=n;++_i)for(int q=0;q<=1;++q){
			int _r=A[_i].a+q*A[_i].len;
			if(_r>mx)mx=_r,_j=_i,_k=q;
			f[_i][_j][_k]=max(f[_i][_j][_k],f[i][j][k]+min(_r-r,A[_i].len)+mx-_r);
		}
	}
	printf("%d\n",ans);
	return 0;
}