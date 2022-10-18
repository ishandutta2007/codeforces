#include<cstdio>
#include<algorithm>
#define N 100005

int T;

int n,m,k;

#define num(x,y) (((x)-1)*m+(y))
int a[N];

int main(){
	scanf("%d",&T);
	while(T--){
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				a[num(i,j)]=0;
		scanf("%d%d%d",&n,&m,&k);
		if(k==4*(n-1)*(m-1)-8){
			if(n>3&&m>3)
				puts("-1");
			else if(n==3)
				for(int i=1;i<=n;i++){
					putchar('.');
					for(int j=2;j<=m;j++)
						putchar('*');
					puts("");
				}
			else if(m==3){
				for(int i=1;i<n;i++){
					for(int j=1;j<=m;j++)
						putchar('*');
					puts("");
				}
				for(int i=1;i<=m;i++)
					putchar('.');
				puts("");
			}
			continue;
		}
		int x,y;
		for(x=1;x<=n;x++){
			for(y=1;y<=m;y++){
				a[num(x,y)]=1;
				if(x>1){
					if(y==1)
						k-=1;
					else if(y==m)
						k-=3;
					else
						k-=4;
				}
				if(k<=0){
					a[num(x,y)]=0;
					break;
				}
			}
			if(k<=0)
				break;
		}
//		printf("&%d %d %d\n",x,y,k);
		bool flg=1;
		if(k>0)
			flg=0;
		else if(k==0)
			a[num(x,y)]=1;
		else if(y==m){
			if(x==n)
				flg=0;
			else{
				if(k==-1)
					a[num(x+1,y)]=a[num(x+1,y-1)]=1;
				else
					a[num(x+1,y-1)]=1;
			}
		}
		else{
			if(k==-1){
				if(y<=m-3)
					a[num(x,m-2)]=a[num(x,m)]=1;
				else if(x<n){
					if(y==2){
						a[num(x,m)]=1;
						for(int i=m;i>=y-1;i--)
							a[num(x+1,i)]=1;
					}
					else
						a[num(x,m)]=a[num(x+1,y-1)]=a[num(x+1,y)]=1;
				}
				else{
//					puts("A");
					flg=0;
				}
			}
			else if(k==-2){
				if(y<=m-2)
					a[num(x,m-1)]=1;
				else if(x<n)
					a[num(x,m)]=a[num(x+1,m)]=a[num(x+1,m-1)]=1;
				else{
//					puts("B");
					flg=0;
				}
			}
			else if(k==-3){
				a[num(x,m)]=1;
			}
		}
		if(flg)
			for(int i=1;i<=n;i++){
				for(int j=1;j<=m;j++)
					putchar(a[num(i,j)]?'*':'.');
				puts("");
			}
		else
			puts("-1");
	}
}