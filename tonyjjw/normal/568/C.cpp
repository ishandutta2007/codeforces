//*
#include<stdio.h>
#include<string.h>
#define MN 210
#pragma warning(disable:4996)
using namespace std;

char inp[MN+1];
char ans[MN+1];
int type[26];
int A[2*MN][2*MN];
int conf[MN];

int sz;
int N,M;

int r(int n){
	if(n<N)return n+N;
	return n-N;
}


int main(){
	scanf("%s",inp);
	sz=strlen(inp);
	for(int i=0;i<sz;i++)type[i]=(inp[i]=='C');
	scanf("%d%d",&N,&M);
	for(int i=0;i<M;i++){
		int a,b;
		char s1[5],s2[5];
		scanf("%d%s%d%s",&a,s1,&b,s2),--a,--b;
		if(*s1=='C')a+=N;
		if(*s2=='C')b+=N;
		A[a][b]=1;
		A[r(b)][r(a)]=1;
	}
	scanf("%s",inp);
	for(int k=0;k<2*N;k++){
		for(int i=0;i<2*N;i++){
			for(int j=0;j<2*N;j++){
				A[i][j]|=(A[i][k]&A[k][j]);
			}
		}
	}
	for(int i=0;i<N;i++){
		if(A[i][r(i)] && A[r(i)][i]){
			puts("-1");
			return 0;
		}
	}
	for(int i=N;i>=0;i--){
		for(int j=0;j<N;j++)conf[j]=-1;
		bool flag=true;
		for(int j=0;j<i;j++){
			ans[j]=inp[j];
			if(conf[j]!=-1 && type[ans[j]-'a']!=conf[j]){
				flag=false;
				break;
			}
			conf[j]=type[ans[j]-'a'];
			if(A[j+conf[j]*N][r(j+conf[j]*N)]){
				flag=false;
				break;
			}
			for(int k=j+1;k<N;k++){
				if(A[j+conf[j]*N][k]){
					conf[k]=0;
				}
				else if(A[j+conf[j]*N][k+N]){
					conf[k]=1;
				}
			}
		}
		if(i<N && inp[i]=='a'+sz-1)continue;
		if(!flag)continue;
		for(int j=i;j<N;j++){
			bool bf=true;
			for(int k=(j==i)?(inp[i]-'a'+1):0;k<sz;k++){
				if(conf[j]!=-1 && type[k]!=conf[j])continue;
				if(A[j+type[k]*N][r(j+type[k]*N)]){
					continue;
				}
				conf[j]=type[k];
				ans[j]=k+'a';
				bf=false;
				break;
			}
			if(bf){
				flag=false;
				break;
			}
			for(int k=j+1;k<N;k++){
				if(A[j+conf[j]*N][k]){
					conf[k]=0;
				}
				else if(A[j+conf[j]*N][k+N]){
					conf[k]=1;
				}
			}
		}
		if(!flag)continue;
		printf("%s",ans);
		return 0;
	}
	puts("-1");
	return 0;
}
//*/