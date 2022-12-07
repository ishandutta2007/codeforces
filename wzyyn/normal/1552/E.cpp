#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
using namespace std;

const int N=105;
int n,k,a[N*N]; 
int vl[N],vr[N],la[N];
int main(){
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n*k;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++) vl[i]=vr[i]=0;
	int p=1;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++) la[j]=0;
		for (;p<=n*k;p++)	if (!vl[a[p]])
			if (la[a[p]]) break;
			else la[a[p]]=p;
		if (p>n*k){
			--i; p=1; continue;
		}
		//cout<<p<<' '<<a[p]<<endl;
		vl[a[p]]=la[a[p]];
		vr[a[p]]=p;
		++p;
	}
	for (int i=1;i<=n;i++)
		printf("%d %d\n",vl[i],vr[i]);
}