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
const int N=1<<18|5;
int n,c[N];
int rnd(){
	int x=0;
	For(i,1,9) x=x*10+rand()%10;
	return x%((1<<n)-1)+1;
}
int main(){
	srand(time(NULL));
	scanf("%d",&n);
	For(i,1,420){
		int x=rnd(),y=rnd(),z=rnd();
		for (;x==y||x==z||y==z;x=rnd(),y=rnd(),z=rnd()); 
		cout<<"? "<<x<<' '<<y<<' '<<z<<endl;
		scanf("%d",&x);
		++c[x];
	}
	int i1=0,i2=0;
	For(i,1,(1<<n)-1)
		if (c[i]>c[i1]) i2=i1,i1=i;
		else if (c[i]>c[i2]) i2=i;
	For(i,1,(1<<n)-1) if (i!=i1&&i!=i2){
		cout<<"? "<<i1<<' '<<i2<<' '<<i<<endl;
		int x;
		scanf("%d",&x);
		if (x==i){
			cout<<"! "<<i<<endl;
			exit(0);
		}
	}
}