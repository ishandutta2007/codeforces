#include <bits/stdc++.h>
using namespace std;
int n,m,q,size,blocknum;
char s[100005][12];
int to[100005][12];
int update(int k,int x,int y){
	if(to[x][y])	return to[x][y];
	if(s[x][y]=='^'){
		int xx=x-1,yy=y;
		if(xx<1+(k-1)*size)		to[x][y]=xx*(m+2)+yy;
		else					to[x][y]=update(k,xx,yy);
	}
	else if(s[x][y]=='>'){
		int xx=x,yy=y+1;
		if(yy==m+1)		to[x][y]=xx*(m+2)+yy;
		else if(s[xx][yy]=='<'){
			to[x][y]=-1;
			to[xx][yy]=-1;
		}
		else	to[x][y]=update(k,xx,yy);
	}
	else if(s[x][y]=='<'){
		int xx=x,yy=y-1;
		if(yy==0)		to[x][y]=xx*(m+2)+yy;
		else if(s[xx][yy]=='>'){
			to[x][y]=-1;
			to[xx][yy]=-1;
		}
		else	to[x][y]=update(k,xx,yy);
	}
	return to[x][y];
}
void get(int x){
	for(int r=1+(x-1)*size;r<=min(x*size,n);r++)
		for(int c=1;c<=m;c++)
			update(x,r,c);
}
void modify(int k,int x,int y,char c){
	for(int r=1+(k-1)*size;r<=min(k*size,n);r++)
		for(int c=1;c<=m;c++)
			to[r][c]=0;
	s[x][y]=c;
	get(k);
}
int query(int k,int x,int y){
	if(to[x][y]==-1)	return -1;
	if(k==1)			return to[x][y];
	int X=to[x][y]/(m+2);
	int Y=to[x][y]%(m+2);
	if(Y!=0&&Y!=m+1)	return query(k-1,X,Y);
	return to[x][y];
}
int main(){
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++)
		scanf("%s",s[i]+1);
	size=int(sqrt(n))+1;
	blocknum=n/size;
	if(n%size) blocknum++;
	for(int i=1;i<=blocknum;i++)	get(i);
	while(q--){
		char opt;cin>>opt;
		if(opt=='A'){
			int x,y;cin>>x>>y;
			int ans=query((x-1)/size+1,x,y);
			if(ans>=0)
				cout<<ans/(m+2)<<" "<<ans%(m+2)<<endl;
			else
				puts("-1 -1");
		}
		else{
			int x,y;char ch;cin>>x>>y>>ch;
			modify((x-1)/size+1,x,y,ch);
		}
	}
	return 0;
}