#include<bits/stdc++.h>

using namespace std;

const int mo1=998244353;
const int mo2=1000000007;
const int mo3=1000000017;
const int N=700005;
char a[N],b[N];
int n,m,p1[N],p2[N],p3[N];
int z[N];


void init(){
	p1[0]=p2[0]=p3[0]=1;
	for (int i=1;i<N;i++){
		p1[i]=10ll*p1[i-1]%mo1;
		p2[i]=10ll*p2[i-1]%mo2;
		p3[i]=10ll*p3[i-1]%mo3;
	}
}
struct node{
	int v1,v2,v3;
	node operator +(const node &a)const{
		return (node){(v1+a.v1)%mo1,(v2+a.v2)%mo2,(v3+a.v3)%mo3};	
	}
	bool operator ==(const node &a)const{
		return v1==a.v1&&v2==a.v2&&v3==a.v3;
	}
};
struct Hasher{
	int s1[N],s2[N],s3[N];
	void init(char* a,int l){
		for (int i=1;i<=l;i++){
			s1[i]=(10ll*s1[i-1]+a[i]-'0')%mo1;
			s2[i]=(10ll*s2[i-1]+a[i]-'0')%mo2;
			s3[i]=(10ll*s3[i-1]+a[i]-'0')%mo3;
		}
	}
	node qry(int l,int r){
		int v1=(s1[r]+mo1-1ll*s1[l-1]*p1[r-l+1]%mo1)%mo1;
		int v2=(s2[r]+mo2-1ll*s2[l-1]*p2[r-l+1]%mo2)%mo2;
		int v3=(s3[r]+mo3-1ll*s3[l-1]*p3[r-l+1]%mo3)%mo3;
		return (node){v1,v2,v3};
	}
}T1,T2;
void check(int p,int d1,int d2){
	if (d1<=0||d2<=0||p+d1+d2-1>n||p<=0) return;
	//cout<<p<<' '<<d1<<' '<<d2<<endl;
	node v1=T1.qry(p,p+d1-1);
	node v2=T1.qry(p+d1,p+d1+d2-1);
	node v3=T2.qry(1,m);
	if ((v1+v2)==v3){
		printf("%d %d\n%d %d\n",p,p+d1-1,p+d1,p+d1+d2-1);
		exit(0);
	}
}

int main(){
	init();
	scanf("%s",a+1);
	scanf("%s",b+1);
	n=strlen(a+1);
	m=strlen(b+1);
	T1.init(a,n);
	T2.init(b,m);
	for (int i=1;i<=n;i++) check(i,m-1,m-1);
	b[m+1]='#';
	for (int i=1;i<=n;i++) b[m+1+i]=a[i];
	int l=1,r=1;
	for (int i=2;i<=n+m+1;i++){
		if (i<=r) z[i]=min(z[i-l+1],r-i+1);
		for (;i+z[i]<=n+m+1&&b[1+z[i]]==b[i+z[i]];++z[i]);
		if (i+z[i]-1>r) l=i,r=i+z[i]-1;
	}
	for (int i=1;i<=n;i++){
		int L=m-z[i+m+1];
		//cout<<i<<' '<<L<<endl;
		check(i,m,L);
		check(i,m,L-1);
		check(i-L,L,m);
		check(i-L+1,L-1,m);
	}
	assert(0);
}