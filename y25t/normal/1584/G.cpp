#include<bits/stdc++.h>
#define lf long double
#define eps 1e-9
#define N 3005

const lf pi=acos(-1);

int n;
lf R,x[N],y[N];

lf p[N],l[N],r[N];

bool b[N][N];

int main(){
	scanf("%d%Lf",&n,&R);
	for(int i=1;i<=n;i++)
		scanf("%Lf%Lf",&x[i],&y[i]);
	for(int i=1;i<=n;i++){
		lf s=-pi,t=pi;
		int flg=-1;
		for(int j=1;j<=n&&flg!=-2;j++){
			lf u=x[j]-x[i],v=y[j]-y[i];
			lf d=sqrtl(u*u+v*v);
			p[j]=atan2l(v,u);
			if(d<=R+eps)
				continue;
			else{
				lf z=asinl(R/d);
				l[j]=p[j]-z,r[j]=p[j]+z;
				if(l[j]<-pi)
					l[j]+=2*pi;
				if(r[j]>pi)
					r[j]-=2*pi;
			}
			if(l[j]<=r[j]){
				if(flg==1){
					if(r[j]>=s-eps)
						t=r[j],flg=0;
					else if(l[j]<=t+eps)
						s=l[j],flg=0;
					else
						flg=-2;
				}
				else
					flg=0;
			}
			else{
				if(flg==0){
					if(r[j]>=s-eps)
						l[j]=s;
					else if(l[j]<=t+eps)
						r[j]=t;
					else
						flg=-2;
				}
				else
					flg=1;
			}
			s=std::max(s,l[j]),t=std::min(t,r[j]);
		}
		if(flg==-2)
			continue;
		for(int j=1;j<=n;j++)
			if(flg==0)
				b[i][j]=s-eps<=p[j]&&p[j]<=t+eps;
			else
				b[i][j]=s-eps<=p[j]||p[j]<=t+eps;
	}
	int res=0;
	for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++)
		res+=b[i][j]&&b[j][i];
	printf("%d\n",res);
}