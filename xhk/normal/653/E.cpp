#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
using namespace std;

int n,m,k,flag;
int used[300010];
map<pair<int,int>,int> h;
set<int> t;

void dfs(int i)
{int x,y;
 set<int>::iterator p;
 vector<int> w;
 
 w.clear();
 for(p=t.begin();p!=t.end();p++)
 {	x=i;
 	y=*p;
 	if(x>y) swap(x,y);
 	if(h.find(make_pair(x,y))==h.end())
 	{	flag|=used[*p];
 		w.push_back(*p);
 	}
 }
 for(i=0;i<w.size();i++)
 	if(t.find(w[i])!=t.end())
		t.erase(w[i]);
 for(i=0;i<w.size();i++)
 	dfs(w[i]);		
}

int main()
{int i,j,s=0,x,y;
  
 scanf("%d%d%d",&n,&m,&k);
 for(i=2;i<=n;i++) used[i]=1;
 for(i=1;i<=m;i++)
 {	scanf("%d%d",&x,&y);
 	if(x>y) swap(x,y);
 	if(x==1)
	{	used[y]=0;
		s++;
	}
 	h[make_pair(x,y)]=1;
 }
 if(n-1-s<k)
 {	printf("impossible\n");
 	return 0;
 }
 s=0;
 for(i=2;i<=n;i++) t.insert(i);
 flag=1;
 for(i=2;i<=n;i++)
 {	if(t.find(i)!=t.end())
 	{	s++;
 		flag=used[i];
 		t.erase(i);
 		dfs(i);
 	}
 	if(!flag || s>k) break;
 }
 if(flag && s<=k)
 	printf("possible\n");
 else
 	printf("impossible\n");	
 return 0;
}