//CF 
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
typedef double DB;
char ch[111];
int la,lb,lc,a[8],b[8],c[8];
int f[22][8][2][8][2][8][2];
int ta[22],tb[22],tc[22],ans=111;
LL A,B,C;
void solve(int i,int x,int xx,int y,int yy,int z,int k,int w){
	if(f[i][x][xx][y][yy][z][k]&&f[i][x][xx][y][yy][z][k]<=w||ans<=w)
		return;
	if(!xx&&!yy&&!z&&!k){
		if(ans>w){
			ans=w;
			int j;
			A=0,B=0,C=0;
			for(j=i;j;j--)
				A=A*10+ta[j],B=B*10+tb[j],C=C*10+tc[j];
			//cout<<A<<' '<<B<<' '<<C<<' '<<w<<endl;
		}
		return;
	}
	f[i][x][xx][y][yy][z][k]=w;
	//cout<<i<<x<<xx<<y<<yy<<z<<k<<endl;
	if(xx&&!x)
		solve(i,x,0,y,yy,z,k,w);
	if(yy&&!y)
		solve(i,x,xx,y,0,z,k,w);
	i++;
	int aa=a[x]%10,bb=b[y]%10,cc=c[z]%10,ww=w+xx+yy+1;
	if(x&&y&&z){
		ta[i]=aa,tb[i]=bb,tc[i]=aa+bb+k;
		if((aa+bb+k)%10==cc){
			if(tc[i]<=9)
				solve(i,x-1,xx,y-1,yy,z-1,0,ww);
			else
				tc[i]-=10,solve(i,x-1,xx,y-1,yy,z-1,1,ww);
		}
	}
	if(x&&z){
		ta[i]=aa,tb[i]=-aa-k+cc,tc[i]=cc;
		if(yy||(!(tb[i]%10))){
			if(tb[i]>=0)
				solve(i,x-1,xx,y,yy,z-1,0,ww);
			else
				tb[i]+=10,solve(i,x-1,xx,y,yy,z-1,1,ww);
		}
	}
	if(y&&z){
		ta[i]=-bb-k+cc,tb[i]=bb,tc[i]=cc;
		if(xx||(!(ta[i]%10))){
			if(ta[i]>=0)
				solve(i,x,xx,y-1,yy,z-1,0,ww);
			else
				ta[i]+=10,solve(i,x,xx,y-1,yy,z-1,1,ww);
		}
	}
	if(x&&y){
		ta[i]=aa,tb[i]=bb,tc[i]=aa+bb+k;
		if(tc[i]<=9)
			solve(i,x-1,xx,y-1,yy,z,0,ww);
		else
			tc[i]-=10,solve(i,x-1,xx,y-1,yy,z,1,ww);
	}
	if(x){
		ta[i]=aa,tb[i]=0,tc[i]=aa+0+k;
		if(tc[i]<=9)
			solve(i,x-1,xx,y,yy,z,0,ww);
		else
			tc[i]-=10,solve(i,x-1,xx,y,yy,z,1,ww);
	}
	if(x&&yy){
		ta[i]=aa,tb[i]=9,tc[i]=aa+9+k;
		if(tc[i]<=9)
			solve(i,x-1,xx,y,yy,z,0,ww);
		else
			tc[i]-=10,solve(i,x-1,xx,y,yy,z,1,ww);
	}
	if(y){
		ta[i]=0,tb[i]=bb,tc[i]=0+bb+k;
		if(tc[i]<=9)
			solve(i,x,xx,y-1,yy,z,0,ww);
		else
			tc[i]-=10,solve(i,x,xx,y-1,yy,z,1,ww);
	}
	if(y&&xx){
		ta[i]=9,tb[i]=bb,tc[i]=9+bb+k;
		if(tc[i]<=9)
			solve(i,x,xx,y-1,yy,z,0,ww);
		else
			tc[i]-=10,solve(i,x,xx,y-1,yy,z,1,ww);
	}
	if(z&&xx){
		ta[i]=cc-k,tb[i]=0,tc[i]=cc;
		if(ta[i]>=0)
			solve(i,x,xx,y,yy,z-1,0,ww);
		else
			ta[i]+=10,solve(i,x,xx,y,yy,z-1,1,ww);
	}
	if(z&&yy){
		ta[i]=0,tb[i]=cc-k,tc[i]=cc;
		if(tb[i]>=0)
			solve(i,x,xx,y,yy,z-1,0,ww);
		else
			tb[i]+=10,solve(i,x,xx,y,yy,z-1,1,ww);
	}
	if(z&&xx&&yy){
		ta[i]=9,tb[i]=cc-9-k,tc[i]=cc;
		if(tb[i]>=0)
			solve(i,x,xx,y,yy,z-1,0,ww);
		else
			tb[i]+=10,solve(i,x,xx,y,yy,z-1,1,ww);
	}
	if(z&&k&&cc==1){
		ta[i]=0,tb[i]=0,tc[i]=1;
		solve(i,x,xx,y,yy,z-1,0,ww);
	}
	if(k){
		ta[i]=0,tb[i]=0,tc[i]=1;
		solve(i,x,xx,y,yy,z,0,ww);
	}
	ta[i]=0,tb[i]=0,tc[i]=0;
}
int main()
{
	int i,j,l;
	cin>>ch;
	l=strlen(ch);
	for(i=0;ch[i]!='+';i=i+1,la=la+1)
		a[la+1]=a[la]*10+ch[i]-'0';
	for(i=i+1;ch[i]!='=';i=i+1,lb=lb+1)
		b[lb+1]=b[lb]*10+ch[i]-'0';
	for(i=i+1;i<l;i=i+1,lc=lc+1)
		c[lc+1]=c[lc]*10+ch[i]-'0';
	//cout<<la<<lb<<lc<<endl;
	solve(0,la,1,lb,1,lc,0,0);
	//cout<<f[4][0][0][1][1][0][0]<<endl;
	//cout<<ans<<endl;
	cout<<A<<'+'<<B<<'='<<C<<endl;
	return 0;
}