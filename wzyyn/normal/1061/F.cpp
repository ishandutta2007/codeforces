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
int n,k;
int query(int x,int y,int z){
	cout<<"? "<<x<<' '<<y<<' '<<z<<endl;
	string s;
	cin>>s;
	return s[0]=='Y'; 
}
int find_leaf(){
	for (;;){
		int x=rand()%n+1;
		int y=rand()%n+1;
		for (;x==y;){
			x=rand()%n+1;
			y=rand()%n+1;
		}
		bool flag=0;
		For(i,1,n)
			if (i!=x&&i!=y)
				if (query(i,x,y))
					flag=1;
		if (!flag) return x;
	}
}
int q[505];
int main(){
	srand(time(NULL));
	scanf("%d%d",&n,&k);
	int x=find_leaf();
	int d=1,p=1;
	for (;p<=n;p*=k,d++);
	d--;
	for (;;){
		int y=find_leaf();
		for (;x==y;y=find_leaf());
		*q=0; q[++*q]=x; q[++*q]=y;
		For(i,1,n)
			if (i!=x&&i!=y)
				if (query(x,i,y))
					q[++*q]=i;
		//cout<<*q<<' '<<x<<' '<<y<<' '<<2*d-1<<endl;
		if ((*q)!=2*d-1)
			continue;
		For(i,2,*q) For(j,i+1,*q)
			if (query(q[1],q[j],q[i]))
				swap(q[i],q[j]);
		cout<<"! "<<q[d]<<endl;
		exit(0);
	}
}
//1-2-3