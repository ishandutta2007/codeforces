#include<bits/stdc++.h>
using namespace std;
const int N=1005;
vector<int> ansl,ansr;
int x,y,s[N],top=0,n,a[N];
int main()
{
	scanf("%d",&n);
	for (int i=1;i<n;i++)
	 {
		scanf("%d%d",&x,&y);
		if (x==n)a[y]++;
		else if (y==n)a[x]++; 
		else
		 {
		 	puts("NO");
			return 0;
		 }
	 }
	for (int i=1;i<n;i++)
	 if (!a[i])s[++top]=i;
	s[0]=n;
	for (int i=n-1;i;i--)
	 {
		if (!a[i]) continue;
		a[i]--;
		int u=n,v;
		while (a[i]--)
		 {
			v=s[top--];
			if (v>i){puts("NO");return 0;}
			ansl.push_back(u);
			ansr.push_back(v);
			u=v;
		 }
		ansl.push_back(u);
		ansr.push_back(i);
	 }
	puts("YES");
	for (int i=0;i<n-1;i++)printf("%d %d\n",ansl[i],ansr[i]);
	return 0;
}