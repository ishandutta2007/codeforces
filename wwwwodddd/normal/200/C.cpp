#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
using namespace std;
#define fr(i,n) for(int i=0;i<n;i++)
#define fo(i,n) for(int i=1;i<=n;i++)
#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
map<string,int>g;
map<int,string>rv;
int win[10];
int wl[10];
int sco[10];
int v[6][6];
int Q(string s)
{
	if(g.count(s))
		return g[s];
	int rk=g.size();
	rv[rk]=s;
	return g[s]=rk;
}
int judge(int x)
{
	int cnt=0;
	for(int i=0;i<4;i++)
		if(i!=x)
		{
			if(sco[i]>sco[x])
				cnt++;
			else if(sco[i]==sco[x])
				if(wl[i]>wl[x]||wl[i]==wl[x]&&win[i]>win[x]||wl[i]==wl[x]&&win[i]==win[x]&&rv[i]<rv[x])
					cnt++;
		}
	return cnt<=1;
}
int main()
{
	for(int i=0;i<5;i++)
	{
		string sa,sb;
		cin>>sa>>sb;
		int pa=Q(sa),pb=Q(sb);
		int x,y;
		scanf("%d:%d",&x,&y);
		v[pa][pb]=v[pb][pa]=1;
		win[pa]+=x;
		win[pb]+=y;
		wl[pa]+=x-y;
		wl[pb]+=y-x;
		if(x==y)
		{
			sco[pa]++;
			sco[pb]++;
		}
		else if(x>y)
		{
			sco[pa]+=3;
		}
		else
		{
			sco[pb]+=3;
		}
	}
	int my=Q(string("BERLAND"));
	int yr=0;
	for(int i=0;i<4;i++)
		if(i!=my)
			if(!v[i][my])
				yr=i;
	int ansx=0xffffff;
	int ansy=0;
	for(int xx=0;xx<60;xx++)
		for(int yy=0;yy<xx;yy++)
		{			
			win[my]+=xx;
			win[yr]+=yy;
			wl[my]+=xx-yy;
			wl[yr]+=yy-xx;
			if(xx==yy)
			{
				sco[my]++;
				sco[yr]++;
			}
			else if(xx>yy)
			{
				sco[my]+=3;
			}
			else
			{
				sco[yr]+=3;
			}
			if(judge(my))
			{
				if(xx-yy<ansx-ansy||xx-yy==ansx-ansy&&yy<ansy)
				{
					ansx=xx;
					ansy=yy;	
				}
			}
			win[my]-=xx;
			win[yr]-=yy;
			wl[my]-=xx-yy;
			wl[yr]-=yy-xx;
			if(xx==yy)
			{
				sco[my]--;
				sco[yr]--;
			}
			else if(xx>yy)
			{
				sco[my]-=3;
			}
			else
			{
				sco[yr]-=3;
			}
		}
	if(ansx>0xffff)
	{
		puts("IMPOSSIBLE");	
	}
	else
	{
		cout << ansx << ':' << ansy << endl;	
	}
}