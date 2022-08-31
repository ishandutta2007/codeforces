//CF 3D
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
char ch[111111];
priority_queue<pair<int,int> > Q;
int main()
{
	int n,i,d,x,y;
	LL ans;
	scanf("%s",ch);
	n=strlen(ch);
	d=0;
	ans=0;
	for(i=0;i<n;i=i+1){
		if(ch[i]=='(')
			d++;
		if(ch[i]==')')
			d--;
		if(ch[i]=='?'){
			scanf("%d%d",&x,&y);
			ch[i]=')';
			d--;
			ans+=y;
			Q.push(make_pair(y-x,i));
		}
		while(!Q.empty()&&d<0){
			x=Q.top().first,y=Q.top().second;
			Q.pop();
			ch[y]='(';
			d+=2;
			ans-=x;
		}
		if(d<0||(d>0&&i==n-1)){
			cout<<-1<<endl;
			return 0;
		}
	}
	cout<<ans<<endl;
	for(i=0;i<n;i=i+1)
		cout<<ch[i];
	return 0;
}