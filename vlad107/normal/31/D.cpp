#include <stdio.h>
#include <algorithm>

#define MAXN 1000

int w,h,n,x1[MAXN],y1[MAXN],x2[MAXN],y2[MAXN],sx[MAXN],sy[MAXN],ex[MAXN],ey[MAXN],ks=0,a[MAXN];
bool was[MAXN];

int main(){
	scanf("%d%d%d",&w,&h,&n);
	sx[0]=0;sy[0]=0;ex[0]=w;ey[0]=h;ks=1;
	for (int i=0;i<n;i++)scanf("%d%d%d%d",&x1[i],&y1[i],&x2[i],&y2[i]);
	for (int ttt=0;ttt<n;ttt++)
		for (int i=0;i<n;i++)if(!was[i]){
			if (x1[i]==x2[i]){
				for (int j=0;j<ks;j++)
					if (y1[i]==sy[j]&&y2[i]==ey[j]&&x1[i]>=sx[j]&&x1[i]<=ex[j]){
						sx[ks]=sx[j];sy[ks]=sy[j];ex[ks]=x1[i];ey[ks]=ey[j];
						std::swap(sx[ks],sx[j]);std::swap(sy[ks],sy[j]);
						std::swap(ex[ks],ex[j]);std::swap(ey[ks],ey[j]);
						sx[ks]=x1[i];ks++;
						was[i]=true;
						break;
					}
			}else{
				for (int j=0;j<ks;j++)
					if (x1[i]==sx[j]&&x2[i]==ex[j]&&y1[i]>=sy[j]&&y1[i]<=ey[j]){
						sx[ks]=sx[j];sy[ks]=sy[j];ex[ks]=ex[j];ey[ks]=y1[i];
						std::swap(sx[ks],sx[j]);std::swap(sy[ks],sy[j]);
						std::swap(ex[ks],ex[j]);std::swap(ey[ks],ey[j]);
						sy[ks]=y1[i];ks++;
						was[i]=true;
						break;
					}
			}
		}
	for (int i=0;i<ks;i++)
		a[i]=(ex[i]-sx[i])*(ey[i]-sy[i]);
	std::sort(a,a+ks);
	for (int i=0;i<ks;i++)printf("%d ",a[i]);
	printf("\n");
}