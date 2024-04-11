#include <stdio.h>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
const int N=100050;
struct Student
{
	int c,t,id;
	Student(){}
	Student(int a, int b, int j){ c=a,t=b,id=j;}
	inline bool operator < (const Student &b) const
	{
		if(c==b.c) return id<b.id;
		return c<b.c;
	}
};
set<Student> Set;
struct Bug
{
	int type,b,id;
	Bug(){}
	Bug(int a, int c, int j){ type=a,b=c,id=j;}
	inline bool operator < (const Bug &a) const
	{
		if(b==a.b) return type<a.type;
		return b>a.b;
	}
};
int a[N],c[N],b[N],sol[N],ans[N];
vector<Bug> bugs;
bool Solve(int t, int s, int m)
{
	Set.clear();
	int i;
	for(i=0;i<bugs.size();i++)
	{
		int j=bugs[i].id;
		if(bugs[i].type==1)
		{
			Set.insert(Student(c[j],t,j));
		}
		else
		{
			if(Set.empty()) return false;
			Student tmp=*Set.begin();
			if(tmp.c>s) return false;
			Set.erase(tmp);
			s-=tmp.c;
			tmp.c=0;
			tmp.t--;
			sol[j]=tmp.id;
			if(tmp.t>0) Set.insert(tmp);
		}
	}
	for(i=1;i<=m;i++) ans[i]=sol[i];
	return true;
}
int main()
{
	int n,m,s,i;
	scanf("%i %i %i",&n,&m,&s);
	for(i=1;i<=m;i++) scanf("%i",&a[i]),bugs.push_back(Bug(2,a[i],i));
	for(i=1;i<=n;i++) scanf("%i",&b[i]);
	for(i=1;i<=n;i++) scanf("%i",&c[i]);
	for(i=1;i<=n;i++) bugs.push_back(Bug(1,b[i],i));
	sort(bugs.begin(),bugs.end());
	int top=m,bot=1,mid,tr=m+1;
	while(top>=bot)
	{
		mid=top+bot>>1;
		if(Solve(mid,s,m)) top=mid-1,tr=mid;
		else bot=mid+1;
	}
	if(tr>m) return printf("NO\n"),0;
	printf("YES\n");
	for(i=1;i<=m;i++) printf("%i ",ans[i]);
	return 0;
}