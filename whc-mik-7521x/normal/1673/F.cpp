#include<bits/stdc++.h>
using namespace std;
const int N=40;
int n,k;
int bk[N],a[N][N],b[N][N],sum[N][N];
int main(){
    scanf("%d%d",&n,&k);
	set<int>st;
    st.insert(0);
	for(int i=1,now=0;i<=n;i++){
		int t=1;
		while(st.count(t^now))t<<=2;
		bk[i]=t,now^=t,st.insert(now);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<n;j++)printf("%d ",a[i][j]=bk[j]);
        puts("");
	}
	for(int i=1;i<n;i++){
		for(int j=1;j<=n;j++)printf("%d ",b[i][j]=bk[i]<<1);
		puts("");
	}
    fflush(stdout);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==1)sum[i][j]=sum[i][j-1]^a[i][j-1];
			else sum[i][j]=sum[i-1][j]^b[i-1][j];
        }
    }
	int x,last;
	while(k--){
        scanf("%d",&x);
		bool pd=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if((sum[i][j]^last)==x){printf("%d %d\n",i,j),fflush(stdout),last=sum[i][j],pd=1;break;}
            }
			if(pd)break;
		}
	}
	return 0;
}