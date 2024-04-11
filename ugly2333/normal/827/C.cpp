// CF 827C
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
int T[111111][11][11][4],n,q,m;
char s[111111],c[11];
int ch(char x)
{
	if(x=='A')
		return 0;
	if(x=='T')
		return 1;
	if(x=='G')
		return 2;
	return 3;
}
int lowbit(int x){
	return x&-x;
}
void modify(int x,int y,int z,int p,int v)
{
	//cout<<p<<x<<y<<z<<endl;
	while(p<=n){
		T[p][x][y][z]+=v;
		p+=lowbit(p);
	}
}
int query(int x,int y,int z,int p)
{
	//cout<<p<<x<<y<<z<<endl;
	int res;
	res=0;
	while(p>0){
		res+=T[p][x][y][z];
		p-=lowbit(p);
	}
	return res;
}
int main()
{
	int i,j,t,l,r,x,y,ans;
	m=10;
	scanf("%s",&s);
	n=strlen(s);
	for(i=0;i<n;i=i+1){
		j=ch(s[i]);
		for(t=1;t<=m;t=t+1)
			modify(t,i%t,j,i/t+1,1);
	}
	scanf("%d",&q);
	while(q--){
		scanf("%d",&t);
		if(t==1){
			scanf("%d%s",&r,&c);
			r--;
			x=ch(s[r]);
			y=ch(c[0]);
			for(t=1;t<=m;t=t+1){
				modify(t,r%t,x,r/t+1,-1);
				modify(t,r%t,y,r/t+1,1);
			}
			s[r]=c[0];
		}
		else{
			scanf("%d%d%s",&l,&r,&c);
			l--;
			r--;
			t=strlen(c);
			ans=0;
			for(i=0;i<t;i=i+1){
				x=ch(c[i]);
				y=(i+l)%t;
				ans+=query(t,y,x,(r-y+t)/t);
				//cout<<ans<<endl;
				ans-=query(t,y,x,(l-1-y+t)/t);
				//cout<<l<<' '<<r<<endl;
				//cout<<(r-y+t)/t<<' '<<(l-1-y+t)/t<<endl;
				//cout<<ans<<"\n\n";
			}
			printf("%d\n",ans);
			//cout<<"+++"<<T[1][1][0][0]<<endl;
		}
	}
	return 0;
}
/*
A
9
1 1 A
1 1 G
1 1 A
1 1 G
1 1 G
2 1 1 AG
1 1 G
2 1 1 CATGGGCC
2 1 1 ACAAAGTA
*/