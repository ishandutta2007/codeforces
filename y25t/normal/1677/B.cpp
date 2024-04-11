#include<bits/stdc++.h>
#define N 1000005

int T;

int n,m;
char s[N];

bool b[N];
int c[N];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%s",&n,&m,s);
		for(int i=0;i<m;i++)
			b[i]=0,c[i]=0;
		int res=0;
		for(int i=0,l=0,t=-1;i<n*m;i++){
			if(s[i]=='1'){
				if(!b[i%m])
					res++;
				b[i%m]=1;
				l=0;
				if(t==-1)
					t=i;
			}
			else{
				l++;
				if(l>=m)
					c[i%m]++;
			}
			printf("%d ",t==-1?0:res+(i+1)/m+(i%m==m-1?0:t<=i%m)-c[i%m]);
		}
		puts("");
	}
}