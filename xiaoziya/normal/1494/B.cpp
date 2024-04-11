#include<bits/stdc++.h>
using namespace std;
const int maxn=500005;
int n,T,A,B,C,D,a,b,c,d,w,x,y,z;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d%d%d",&n,&A,&B,&C,&D);
		a=A==n? 2:(A==n-1? 1:0),w=A<=1? A:2;
		b=B==n? 2:(B==n-1? 1:0),x=B<=1? B:2;
		c=C==n? 2:(C==n-1? 1:0),y=C<=1? C:2;
		d=D==n? 2:(D==n-1? 1:0),z=D<=1? D:2;
		int flg=0;
		for(int i=0;i<=1;i++)
			for(int j=0;j<=1;j++)
				for(int k=0;k<=1;k++)
					for(int p=0;p<=1;p++)
						if(i+j>=a&&j+k>=b&&k+p>=c&&p+i>=d&&i+j<=w&&j+k<=x&&k+p<=y&&p+i<=z)
							flg=1;
		puts(flg==0? "NO":"YES");
	}
	return 0;
}