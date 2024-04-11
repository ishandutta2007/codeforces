#include<stdio.h>
int main(){
	int n,m,l,r,i,j,t=0,ans=0;
	scanf("%d%d",&n,&m);
	int a[n];
	for (i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	//printf("%d\n",ans );
	for(i=0;i<m;i++){
		t=0;
		scanf("%d%d",&l,&r);
		for (j =l ; j <= r; j++)
		{
			t = t +  a[j-1];
		}
		if (t>0) ans = ans + t;
		//printf("%d %d %d\n",l,r,t );
	}
    printf("%d\n",ans );
	return 0;
}