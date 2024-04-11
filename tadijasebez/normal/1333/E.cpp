#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int N=505;
int n,a[N][N];
int was[N][N];
int R(){
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)was[i][j]=0;
	pair<int,int> st;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(a[i][j]==i)
				st={i,j};
	was[st.first][st.second]=1;
	int ans=0,work=n*n-1;
	while(work--){
		int mn=1e9;
		pair<int,int> nxt;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(!was[i][j] && (i==st.first || j==st.second)){
					if(mn>a[i][j])mn=a[i][j],nxt={i,j};
				}
		if(mn==1e9){
			ans++;
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
					if(!was[i][j]){
						if(mn>a[i][j])mn=a[i][j],nxt={i,j};
					}
		}
		st=nxt;
		was[nxt.first][nxt.second]=1;
	}
	return ans;
}
int Q(){
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)was[i][j]=0;
	pair<int,int> st;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(a[i][j]==i)
				st={i,j};
	was[st.first][st.second]=1;
	int ans=0,work=n*n-1;
	while(work--){
		int mn=1e9;
		pair<int,int> nxt;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(!was[i][j] && (i==st.first || j==st.second || i+j==st.first+st.second || i-j==st.first-st.second)){
					if(mn>a[i][j])mn=a[i][j],nxt={i,j};
				}
		if(mn==1e9){
			ans++;
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
					if(!was[i][j]){
						if(mn>a[i][j])mn=a[i][j],nxt={i,j};
					}
		}
		st=nxt;
		was[nxt.first][nxt.second]=1;
	}
	return ans;
}
void Try(){
	vector<int> p;
	for(int i=1;i<=n*n;i++)p.pb(i);
	do{
		for(int i=1,k=0;i<=n;i++)
			for(int j=1;j<=n;j++)
				a[i][j]=p[k++];
		if(R()<Q()){
			printf("R:%i Q:%i\n",R(),Q());
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					printf("%i ",a[i][j]);
				}
				printf("\n");
			}
			return;
		}
	}while(next_permutation(p.begin(),p.end()));
}
int res[3][3]={{1,2,4},{5,3,8},{9,6,7}};
int main(){
	scanf("%i",&n);
	if(n<=2)return 0*printf("-1\n");
	int m=n,cnt=0;
	while(m>3){
		if(m>4){
			for(int i=1;i<=m;i++)a[i][m]=++cnt;
			for(int j=m-1;j>=1;j--)a[m][j]=++cnt;
			for(int j=1;j<m;j++)a[m-1][j]=++cnt;
			for(int i=m-2;i>=1;i--)a[i][m-1]=++cnt;
			m-=2;
		}else{
			for(int i=1;i<=m;i++)a[i][m]=++cnt;
			for(int j=m-1;j>=1;j--)a[m][j]=++cnt;
			m--;
		}
	}
	for(int i=1;i<=3;i++)
		for(int j=1;j<=3;j++)
			a[i][j]=cnt+res[i-1][j-1];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			printf("%i%c",a[i][j],j==n?'\n':' ');
	return 0;
}