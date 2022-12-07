#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;

int n,k,a[10005];
int Q(int x,int y,int mode){
	if (mode==0) cout<<"or "<<x<<' '<<y<<endl;
	else cout<<"and "<<x<<' '<<y<<endl;
	cin>>x;
	return x;
}
int main(){
	scanf("%d%d",&n,&k);
	int a12=Q(1,2,0)+Q(1,2,1);
	int a13=Q(1,3,0)+Q(1,3,1);
	int a23=Q(2,3,0)+Q(2,3,1);
	a[1]=(1ll*a12+a13+a23)/2-a23;
	a[2]=a12-a[1]; a[3]=a13-a[1];
	for (int i=4;i<=n;i++)
		a[i]=Q(1,i,0)+Q(1,i,1)-a[1];
	sort(a+1,a+n+1);
	printf("finish %d\n",a[k]);
}