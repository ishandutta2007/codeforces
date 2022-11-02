#include <stdio.h>

int n,x,y,z,sx,sy,sz;

int main(){
	scanf("%d",&n);
	for (int i=0;i<n;i++){
		scanf("%d%d%d",&x,&y,&z);
		sx+=x;sy+=y;sz+=z;
	}
	if (!sx&&!sy&&!sz)
		puts("YES");
	else puts("NO");
}