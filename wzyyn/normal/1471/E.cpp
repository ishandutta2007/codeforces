#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define pii pair<int,int>
#define fi first
#define se second
#define PB push_back
#define ll long long
#define ull unsigned long long
using namespace std;
int n,k,x,sgn;
int query(int x){
	cout<<"? "<<x<<endl;
	cin>>x;
	return x;
}
int rnd(){
	int x=0;
	For(i,1,9) x=x*10+rand()%10;
	return x;
}
int main(){
	srand(time(NULL));
	scanf("%d%d",&n,&k);
	for (;;){
		x=rnd()%n+1;
		int v=query(x);
		if (v!=k){
			sgn=(v<k?1:-1);
			break;
		}
	}
	for (;;){
		x+=sgn;
		if (x<1) x+=n;
		if (x>n) x-=n;
		if (query(x)==k){
			cout<<"! "<<x<<endl;
			exit(0);
		}
	}
}