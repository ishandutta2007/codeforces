#include <bits/stdc++.h>
using namespace std;
int n,ans=0;
int last=-1;
int overlapped_area(int a,int b,int c,int d){
	int left,right;
	left=max(a,c);
	right=min(b,d);
	if(right-left+1<0)	return 0;
	int ans=right-left+1;
	if(left==last)	ans--;
	last=right;
	return ans;
}
int main(){
	cin>>n;
	int cur1=0,cur2=0;
	while(n--){
		int a,b;
		cin>>a>>b;
		ans+=overlapped_area(cur1,a,cur2,b);
		cur1=a,cur2=b;
	}
	cout<<ans<<endl;
}
/*
6
0 0
0 0
0 0
1 1
2 3
5 6
*/