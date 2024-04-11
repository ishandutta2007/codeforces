#include<bits/stdc++.h> 
#define N 200010
using namespace std;
int m,a[N],n,i,j,tot,ans,sg;
char s[N];
set<int>st;
set<int>::iterator it,it1;
bool cmp(int x,int y){return s[x]<s[y];}
int main()
{
	scanf("%d%s",&m,s+1);
	n=strlen(s+1);
	st.insert(0);st.insert(n+1);
	for(i=1;i<=n;i++)a[i]=i,st.insert(i);
	sort(a+1,a+n+1,cmp);
	for(i=n;i>=1;i--)
	{
		st.erase(a[i]);
		it1=it=st.lower_bound(a[i]);
		it1--;
		if((*it)-(*it1)>m)break;
	}
	tot=1;
	for(j=1;j<=n;j++)
	{
		if(tot>m)tot=j-sg,ans++;
		if(s[j]<s[a[i]])tot=0;
		if(s[j]==s[a[i]])sg=j;
		tot++;
		//printf("%d %d %d %d %d\n",j,b[j],tot,ans,sg);
	}
	if(tot>m)ans++;
	for(j=1;s[a[j]]!=s[a[i]];j++)putchar(s[a[j]]);
	for(j=1;j<=ans;j++)putchar(s[a[i]]);
	puts("");
}