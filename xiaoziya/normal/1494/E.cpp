#include<stdio.h>
#include<map>
#include<iostream>
using namespace std;
const int maxn=200005;
int n,T,even,odd,tot;
map<int,char>mp[maxn];
string s;
int main(){
	scanf("%d%d",&n,&T);
	while(T--){
		int x,y;
		char c;
		cin>>s;
		if(s=="+")
			scanf("%d%d",&x,&y),cin>>c,even+=mp[y].count(x)!=0&&mp[y][x]==c,mp[x][y]=c,odd+=mp[y].count(x)!=0;
		if(s=="-")
			scanf("%d%d",&x,&y),even-=mp[y].count(x)!=0&&mp[y][x]==mp[x][y],odd-=mp[y].count(x)!=0,mp[x].erase(y);
		if(s=="?")
			scanf("%d",&x),puts(((x&1)? odd:even)? "YES":"NO");
	}
	return 0;
}