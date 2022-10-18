#include<cstdio>
#include<algorithm>
#define N 200005

int T;

int n;
char s[N];

int a[N],b[N];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%s",&n,s+1);
		int c0=0,c1=0;
		for(int i=1;i<=n;i++)
			if(s[i]=='0')
				c0++;
			else
				c1++;
		if(c0%2==1||c1%2==1){
			puts("NO");
			continue;
		}
		for(int i=1,t0=0,t1=0;i<=n;i++){
			if(s[i]=='0'){
				t0++;
				if(t0%2==1){
					a[i]=1;
					b[i]=-1;
				}
				else{
					a[i]=-1;
					b[i]=1;
				}
			}
			else{
				t1++;
				if(t1<=c1/2)
					a[i]=b[i]=1;
				else
					a[i]=b[i]=-1;
			}
		}
		bool flg=1;
		for(int i=1,tmp=a[1];i<=n;i++,tmp+=a[i])
			if(tmp<0)
				flg=0;
		for(int i=1,tmp=b[1];i<=n;i++,tmp+=b[i])
			if(tmp<0)
				flg=0;
		if(!flg){
			puts("NO");
			continue;
		}
		puts("YES");
		for(int i=1;i<=n;i++)
			putchar(a[i]==1?'(':')');
		puts("");
		for(int i=1;i<=n;i++)
			putchar(b[i]==1?'(':')');
		puts("");
	}
}