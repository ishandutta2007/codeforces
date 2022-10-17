#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define b(x) (1<<((x)-1))
int i,j,k,n,m,t,p[15]={1},a[15],b[15],c[15];
ll res,sb1,sb2,tmp;
int main(){
	for(i=1;i<=9;i++){
		p[i]=p[i-1]*10;
	}
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		res=0;
		for(i=10;i>=1;i--){
			a[i]=n/p[i-1];
			n%=p[i-1];
		}
		
		for(i=0;i<=1023;i++){
			memset(b,0,sizeof(b));
			memset(c,0,sizeof(c));
			for(j=1;j<=10;j++){
				if(i&b(j)){
					if(j-2<=0){goto aaa;}
					c[j]=1;
					b[j-2]=1;
				}
			}
			sb1=1;sb2=1;tmp=1;
			for(j=10;j>=1;j--){
				if(b[j]){
					k=a[j]+10-c[j];
					if(k&1){
						sb1=0;
					}
					if(k<=9){
						tmp*=(k+1);
					}
					else{
						sb1=0;sb2=0;tmp*=(19-k);
					}
				}
				else{
					k=a[j]-c[j];
					if(k<0){goto aaa;}
					tmp*=(k+1);
					if(k&1){
						sb1=0;
					}
				}
			}
			//printf("a%d %d %d %d\n",i,tmp,sb1,sb2);
			res+=tmp-sb2*2;
			aaa:;
		}
		printf("%lld\n",res);
	}
}