//CF 718A
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
char ch[222222];
int main()
{
	int n,t,i,j,x,y;
	scanf("%d%d%s",&n,&t,&ch);
	n--;
	x=0;
	while(x<=n&&ch[x]!='.'){
		x++;
	}
	y=x+1;
	while(y<=n&&ch[y]=='4'){
		y++;
	}
	if(y<=n&&ch[y]>'4'){
		n=y;
		i=y-1;
		while(i>x&&t){
			ch[i]='5';
			n=i;
			t--;
			i--;
		}
		if(n==x+1&&t){
			n=x-1;
			i=n;
			while(i>=0&&ch[i]=='9'){
				ch[i]='0';
				i--;
			}
			if(i<0)
				cout<<1;
			else
				ch[i]++;
		}
		//cout<<endl<<endl<<(int)ch[n]<<endl;
		for(i=0;i<=n;i=i+1)
			cout<<ch[i];
		return 0;
	}
	while(y<=n){
		while(y<=n&&ch[y]<'4'){
			y++;
		}
		j=y;
		while(y<=n&&ch[y]=='4'){
			y++;
		}
		if(y<=n&&ch[y]>'4'){
			n=y;
			i=y-1;
			while(i>=j&&t){
				ch[i]='5';
				n=i;
				t--;
				i--;
			}
			if(n==j&&t){
				n=j-1;
				i=n;
				while(i>x&&ch[i]=='9'){
					ch[i]='0';
					i--;
				}
				ch[i]++;
			}
			for(i=0;i<=n;i=i+1)
				cout<<ch[i];
			return 0;
		}
	}
	for(i=0;i<=n;i=i+1)
		cout<<ch[i];
	return 0;
}