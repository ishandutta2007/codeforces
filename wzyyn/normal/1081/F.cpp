#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
#define y1 ysghysgsygsh
using namespace std;
int n,t,sum[305];
int Func(int l,int r){
	int v,st=t;
	bool fl=0,fr=0;
	for (;!fl||fr;){
		cout<<"? "<<l<<' '<<r<<endl;
		cin>>v;
		if ((v^t^r)&1) fr^=1;
		else fl^=1;
		swap(v,t);
	}
	return (r-(t-st))/2;
}
int Func2(int l,int r){
	int v,st=t;
	bool fl=0,fr=0;
	for (;fl||!fr;){
		cout<<"? "<<l<<' '<<r<<endl;
		cin>>v;
		if ((v^t^r)&1) fr^=1;
		else fl^=1;
		swap(v,t);
	}
	return (n-l+1-(t-st))/2;
}
int main(){
	scanf("%d%d",&n,&t);
	if (n==1){
		cout<<"! "<<t<<endl; 
		exit(0);
	}
	if (n%2==0){
		For(i,1,n){
			sum[i]=Func(i,i);
			Func(i,i);
		}
	}
	else{
		For(i,2,n){
			sum[i]=Func(i-1,i);
			Func(i-1,i);
		}
		sum[1]=sum[n]-Func2(2,3);
	}
	cout<<"! ";
	For(i,1,n) cout<<sum[i]-sum[i-1];
}