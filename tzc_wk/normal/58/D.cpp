#include <bits/stdc++.h>
using namespace std;
struct date_time_node{
	string str;
	int l;
};
date_time_node s[10005],ans[5005];
bool cmp(date_time_node a,date_time_node b){
	return a.str<b.str;
}
bool vis[10005];
bool cmp1(date_time_node a,date_time_node b){
	string tem1=a.str+b.str;
	string tem2=b.str+a.str;
	return tem1<tem2;
}
int main()
{
	int n;
	char buf;
	cin>>n;
	int sl=0;
	for(int i=0;i<n;i++){
		cin>>s[i].str;
		s[i].l=s[i].str.size();
		sl+=s[i].l;
	}
	sl/=(n/2);
	cin>>buf;
	sort(s,s+n,cmp);
	int leng=0;
	char tem1[33],tem2[33];
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(!vis[i]&&!vis[j]&&s[i].l+s[j].l==sl){
				string tem1=s[i].str+buf+s[j].str;
				string tem2=s[j].str+buf+s[i].str;
				if(tem1<tem2){
					ans[leng++].str=tem1;
				}
				else{
					ans[leng++].str=tem2;
				}
				vis[i]=true;
				vis[j]=true;
			}
		}
	}
	sort(ans,ans+leng,cmp1);
	for(int i=0;i<leng;i++){
		cout<<ans[i].str<<endl;
	}
	return 0;
}