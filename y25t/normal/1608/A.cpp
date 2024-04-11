#include<cstdio>
#define N 10000005

int p[N],_p;
bool ntp[N];
inline void getp(){
	ntp[1]=1;
	for(int i=2;i<=1e7;i++){
		if(!ntp[i])
			p[++_p]=i;
		for(int j=1;j<=_p&&i*p[j]<=1e7;j++){
			ntp[i*p[j]]=1;
			if(!(i%p[j]))
				break;
		}
	}
}

int T,n;

int main(){
	getp();
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			printf("%d ",p[i]);
		puts("");
	}
}