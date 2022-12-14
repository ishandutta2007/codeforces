//*
#include<stdio.h>
//#pragma warning(disable:4996)
#define TN 131072

int N,Q,rev=0;
int T[2*TN];

void add(int n,int v){
	for(n+=TN;n>0;n>>=1){
		T[n]+=v;
	}
}

int sum(int l,int r){
	int v=0;
	for(l+=TN,r+=TN;l<=r;l>>=1,r>>=1){
		if(l&1){
			v+=T[l++];
		}
		if(!(r&1)){
			v+=T[r--];
		}
	}
	return v;
}

int main(){
	int i,j,cur=0,type,a,b;
//	freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
	scanf("%d%d",&N,&Q);
	for(i=0;i<N;i++)add(i,1);
	for(i=0;i<Q;i++){
		scanf("%d",&type);
		if(type==1){
			scanf("%d",&a);
			if(2*a>N-cur){
				a=N-cur-a;
				rev=1-rev;
			}
			if(!rev){
				for(j=cur;j<cur+a;j++){
					add(2*cur+2*a-1-j,T[TN+j]);
					add(j,-T[TN+j]);
				}
				cur+=a;
			}
			else{
				for(j=N-1;j>=N-a;j--){
					add(2*N-2*a-1-j,T[TN+j]);
					add(j,-T[TN+j]);
				}
				N-=a;
			}
		}
		if(type==2){
			scanf("%d%d",&a,&b);
			if(!rev){
				printf("%d\n",sum(cur+a,cur+b-1));
			}
			else{
				printf("%d\n",sum(N-b,N-a-1));
			}
		}
	}
	return 0;
}

//*/