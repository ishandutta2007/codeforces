#include<cstdio>
#include<utility>
#include<cstring>
#include<string>
#include<sstream>
#include<iostream>
#include<algorithm>

using namespace std;

typedef pair<int,int> P;

int a=0,b=0,c=0,d=0;
char ch[20];

long long valx[100100],valy[100100];
int xln,yln;

int xs[100100],ys[100100];
long long conv_x[100100],conv_y[100100];
bool valid[100100];

P ps[100100];

int dp[100100];

const int inf=1<<30;

long long det(int a,int b,int c,int d)
{
	return (long long)a*d-(long long)b*c;
}

int main()
{
	int N;
	scanf("%d",&N);
	scanf("%s",ch);
	string str1(ch);
	for(int i=0;i<str1.size();i++)
	{
		if(str1[i]=='/') str1[i]=' ';
	}
	stringstream ss1(str1);
	ss1>>a>>b;
	scanf("%s",ch);
	string str2(ch);
	for(int i=0;i<str2.size();i++)
	{
		if(str2[i]=='/') str2[i]=' ';
	}
	stringstream ss2(str2);
	ss2>>c>>d;
	int id=0;
	memset(valid,false,sizeof(valid));
	for(int i=0;i<N;i++)
	{
		scanf("%d%d",xs+i,ys+i);
		conv_x[i]=det(xs[i],d,ys[i],c);
		conv_y[i]=det(b,xs[i],a,ys[i]);
		if(conv_x[i]<0||conv_y[i]<0) continue;
		valx[id]=conv_x[i];
		valy[id]=conv_y[i];
		id++;
		valid[i]=true;
	}
	sort(valx,valx+id);
	sort(valy,valy+id);
	xln=unique(valx,valx+id)-valx;
	yln=unique(valy,valy+id)-valy;
	id=0;
	for(int i=0;i<N;i++)
	{
		if(valid[i]==false) continue;
		int cx=lower_bound(valx,valx+xln,conv_x[i])-valx;
		int cy=lower_bound(valy,valy+yln,conv_y[i])-valy;
		cx=xln-cx;
		cy=yln-cy;
		ps[id]=P(cy,-cx);
		id++;
	}
	sort(ps,ps+id);
	for(int i=0;i<id;i++)
	{
		dp[i]=inf;
	}
	for(int i=0;i<id;i++)
	{
		int x=-ps[i].second;
		*lower_bound(dp,dp+id,x)=x;
	}
	printf("%d\n",lower_bound(dp,dp+id,inf)-dp);
	return 0;
}