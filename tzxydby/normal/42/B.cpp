#include<bits/stdc++.h>
using namespace std;
int dx[]={0,0,-1,1,-1,1,-1,1,0};
int dy[]={-1,1,0,0,-1,-1,1,1,0};
char a[20][20];
int R1i,R1j,R2i,R2j,Wi,Wj,Bi,Bj,ans;
string r1, r2, wk, bk;
bool check1(int i,int j)
{
	for(int k=j-1;k>=1;k--) 
	{
		if(a[i][k]=='W') 
			break;
		if(a[i][k]=='R') 
			return true;
	}
	for(int k=i-1;k>=1;k--) 
	{
		if(a[k][j]=='W') 
			break;
		if(a[k][j]=='R') 
			return true;
	}
	for(int k=j+1;k<=8;k++) 
	{
		if(a[i][k]=='W') 
			break;
		if(a[i][k]=='R') 
			return true;
	}
	for(int k=i+1;k<=8;k++) 
	{
		if(a[k][j]=='W') 
			break;
		if(a[k][j]=='R') 
			return true;
	}
	return false;
}
bool check2(int i,int j) 
{
	for(int zz=0;zz<8;zz++) 
	{
		int di=i+dx[zz];
		int dj=j+dy[zz];
		if(a[di][dj]=='W') 
			return true;
	}
	return false;
}
int main() 
{
	cin>>r1>>r2>>wk>>bk;
	R1i=r1[0]-'a'+1;
	R1j=r1[1]-'0';
	a[R1i][R1j]='R';
	R2i=r2[0]-'a'+1;
	R2j=r2[1]-'0';
	a[R2i][R2j]='R';
	Wi=wk[0]-'a'+1;
	Wj=wk[1]-'0';
	a[Wi][Wj]='W';
	Bi=bk[0]-'a'+1;
	Bj=bk[1]-'0';
	a[Bi][Bj]='B';
	for(int z=0;z<9;z++) 
	{
		int di=Bi+dx[z];
		int dj=Bj+dy[z];
		if((di<1)||(dj<1)||(di>8)||(dj>8)) 
		{
			ans++;
			continue;
		}
		if(check1(di,dj)||check2(di,dj))
			ans++;
	}
	if(ans==9) 
		cout<<"CHECKMATE\n";
	else 
		cout<<"OTHER\n";
	return 0;
}