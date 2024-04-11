#include <bits/stdc++.h>
using namespace std;
#define fi			first
#define se			second
#define fz(i,a,b)	for(int i=a;i<=b;i++)
#define fd(i,a,b)	for(int i=a;i>=b;i--)
#define put(x)		putchar(x)
#define eoln        put('\n')
#define space		put(' ')
inline int read(){
	int x=0,neg=1;char c=getchar();
	while(!isdigit(c)){
		if(c=='-')	neg=-1;
		c=getchar();
	}
	while(isdigit(c))	x=x*10+c-'0',c=getchar();
	return x*neg;
}
inline void print(int x){
	if(x<0){
		putchar('-');
		print(abs(x));
		return;
	}
	if(x<=9)	putchar(x+'0');
	else{
		print(x/10);
		putchar(x%10+'0');
	}
}
int n=read(),m=read(),tag[505];
int main(){
	cout<<"? ";
	for(int i=1;i<=m;i++)	cout<<i<<" ";
	puts("");
	fflush(stdout);
	int x,y;
	cin>>x>>y;
	cout<<"? ";
	for(int i=1;i<=m;i++)	if(i!=x)	cout<<i<<" ";
	cout<<m+1<<"\n";
	fflush(stdout);
	int cmp,cury,curx;
	cin>>curx>>cury;
	if(cury>y)			cmp=1;
	else			cmp=-1;
	for(int i=1;i<=m;i++){
		if(i!=x){
			cout<<"? ";
			for(int j=1;j<=m;j++)
				if(j!=i)
					cout<<j<<" ";
			cout<<m+1<<"\n";
			fflush(stdout);
			int xx=read(),yy=read();
			if(xx==x)	tag[i]=cmp;
			else		tag[i]=-cmp;
		}
	}
	int ans=1;
	for(int i=1;i<=m;i++)	ans+=(tag[i]==-1);
	cout<<"! "<<ans<<endl;
	fflush(stdout);
	return 0;
}