#include<stdio.h>
#include<bitset>
using namespace std;
const int maxn=1005;
int T,n;
bitset<maxn>b[10];
string s;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=5;i++)
			b[i].reset();
		for(int i=1;i<=n;i++)
			for(int j=1,x;j<=5;j++)
				scanf("%d",&x),b[j][i]=x;
		int flg=0;
		for(int i=1;i<=5;i++)
			for(int j=i+1;j<=5;j++)
				if(b[i].count()>=n/2&&b[j].count()>=n/2&&(b[i]|b[j]).count()==n){
					flg=1;
					break;
				}
		puts(flg==1? "YES":"NO");
	}
	return 0;
}