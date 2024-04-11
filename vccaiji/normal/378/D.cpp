#include<bits/stdc++.h>
using namespace std;
struct stu{
	int b;
	long long c;
	int i;
}s[110000];
bool cmp(stu aa,stu bb){
	return aa.b<bb.b;
}
struct bug{
	int a;
	int i;
}bu[110000];
bool cmp2(bug aa,bug bb){
	return aa.a<bb.a; 
}
int n,m,ss;
bool check(int l){
	long long sum=0;
	priority_queue<long long> p; 
	int j=n+1;
	for(int i=m;i>=1;i-=l){
		for(;;){
			if((j==1)||(s[j-1].b<bu[i].a)) break;
			j--;
			p.push(-s[j].c);
		}
		if(p.empty()) return false;
		sum-=p.top();
		p.pop();
	}
	return sum<=ss;
}
int ans[110000];
void print(int l){
	priority_queue< pair<long long,int> > p; 
	int j=n+1;
	for(int i=m;i>=1;i-=l){
		for(;;){
			if((j==1)||(s[j-1].b<bu[i].a)) break;
			j--;
			p.push(make_pair(-s[j].c,j));
		}
		int jj=p.top().second;
		p.pop();
		for(int k=i;k>=max(1,i-l+1);k--) ans[bu[k].i]=s[jj].i;
	}
	for(int i=1;i<=m;i++) printf("%d ",ans[i]);
}
int main(){
	scanf("%d%d%d",&n,&m,&ss);
	for(int i=1;i<=m;i++) scanf("%d",&bu[i].a);
	for(int i=1;i<=m;i++) bu[i].i=i;
	for(int i=1;i<=n;i++) scanf("%d",&s[i].b);
	for(int i=1;i<=n;i++) scanf("%lld",&s[i].c);
	for(int i=1;i<=n;i++) s[i].i=i;
	sort(s+1,s+n+1,cmp);
	sort(bu+1,bu+m+1,cmp2);
	if(!check(m)) {
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	int l=1,r=m;
	for(;l<r;){
		if(check((l+r)/2)) r=(l+r)/2;
		else l=(l+r)/2+1;
	}
	print(l);
	return 0;
}