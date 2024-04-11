#include <bits/stdc++.h>
using namespace std;
const int N=1050;
const int M=100050;
int a[N][N],ans[N][N];
char s[M];
int main(){
	int t;
	scanf("%i",&t);
	while(t--){
		int n,m;
		scanf("%i %i",&n,&m);
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				scanf("%i",&a[i][j]);
			}
		}
		vector<array<int,3>> v={{0,0,0},{1,0,0},{0,1,0},{0,0,1}};
		scanf("%s",s+1);
		for(int z=1;z<=m;z++){
			for(auto&pt:v){
				if(s[z]=='L'){
					pt[1]--;if(pt[1]<0)pt[1]+=n;
					break;
				}else if(s[z]=='R'){
					pt[1]++;pt[1]%=n;
					break;
				}else if(s[z]=='U'){
					pt[0]--;if(pt[0]<0)pt[0]+=n;
					break;
				}else if(s[z]=='D'){
					pt[0]++;pt[0]%=n;
					break;
				}else if(s[z]=='I'){
					swap(pt[1],pt[2]);
				}else if(s[z]=='C'){
					swap(pt[0],pt[2]);
				}
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				int k=a[i][j]-1;
				int I,J,K;
				I=v[0][0]+v[1][0]*i+v[2][0]*j+v[3][0]*k;I%=n;
				J=v[0][1]+v[1][1]*i+v[2][1]*j+v[3][1]*k;J%=n;
				K=v[0][2]+v[1][2]*i+v[2][2]*j+v[3][2]*k;K%=n;
				ans[I][J]=K+1;
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				printf("%i ",ans[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}