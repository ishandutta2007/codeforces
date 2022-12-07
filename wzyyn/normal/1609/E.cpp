#include<bits/stdc++.h>

using namespace std;

const int N=100005;
int n,Q;
char s[N];

struct Mat{
	int a[3][3];
	Mat(){
		memset(a,1,sizeof(a));
	}
	Mat operator +(const Mat &b){
		Mat c;
		for (int i=0;i<=2;i++)
			for (int j=i;j<=2;j++)
				for (int k=j;k<=2;k++)
					c.a[i][k]=min(c.a[i][k],a[i][j]+b.a[j][k]);
		return c;
	}
}t[N*4];
void build(int k,int l,int r){
	if (l==r){
		t[k].a[0][1]=0;
		t[k].a[0][2]=0;
		t[k].a[1][2]=0;
		t[k].a[0][0]=(s[l]=='a');
		t[k].a[1][1]=(s[l]=='b');
		t[k].a[2][2]=(s[l]=='c');
		return;
	}
	int mid=(l+r)/2;
	build(k*2,l,mid);
	build(k*2+1,mid+1,r);
	t[k]=t[k*2]+t[k*2+1];
}
void change(int k,int l,int r,int p,char c){
	if (l==r){
		t[k].a[0][1]=0;
		t[k].a[0][2]=0;
		t[k].a[1][2]=0;
		t[k].a[0][0]=(c=='a');
		t[k].a[1][1]=(c=='b');
		t[k].a[2][2]=(c=='c');
		return;
	}
	int mid=(l+r)/2;
	if (p<=mid) change(k*2,l,mid,p,c);
	else change(k*2+1,mid+1,r,p,c);
	t[k]=t[k*2]+t[k*2+1];
}
int main(){
	scanf("%d%d",&n,&Q);
	scanf("%s",s+1);
	build(1,1,n);
	while (Q--){
		int x;
		scanf("%d%s",&x,s+1);
		change(1,1,n,x,s[1]);
		printf("%d\n",t[1].a[0][2]);
	}
}