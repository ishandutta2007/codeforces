#include<cstdio>
#define N 100005

int n;

struct node{
	int x,y;
}a[N],v[N];
node operator - (node x,node y){
	return (node){x.x-y.x,x.y-y.y};
}
bool operator == (node x,node y){
	return x.x==-y.x&&x.y==-y.y;
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&a[i].x,&a[i].y);
		if(i>1)
			v[i-1]=a[i]-a[i-1];
	}
	v[n]=a[1]-a[n];
	if(n&1)
		printf("No");
	else{
		bool flg=1;
		for(int i=1;i<=(n>>1);i++)
			flg&=v[i]==v[i+(n>>1)];
		if(flg)
			printf("Yes");
		else
			printf("No");
	}
}