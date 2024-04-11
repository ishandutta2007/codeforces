#include<bits/stdc++.h>
using namespace std;
#define pb push_back
int main(){
	char s[6];
	scanf("%s",&s);
	int a=(int)(s[0]-'0')+(int)(s[1]-'0')+(int)(s[2]-'0');
	int b=(int)(s[3]-'0')+(int)(s[4]-'0')+(int)(s[5]-'0');
	if(a==b){printf("0");return 0;}
	vector<pair<int,int>> v;
	for(int i=0;i<6;i++){
		if(a>b){
			if(i<3)v.pb({(int)(s[i]-'0'),i});
			else v.pb({9-(int)(s[i]-'0'),i});
		}else{
			if(i<3)v.pb({9-(int)(s[i]-'0'),i});
			else v.pb({(int)(s[i]-'0'),i});
		}
	}
	sort(v.begin(),v.end());
	reverse(v.begin(),v.end());
	bool was[6];
	for(int i=0;i<6;i++)was[i]=true;
	int diff=abs(a-b),cnt=0;
	for(int i=0;i<(int)v.size();i++){
		if(was[v[i].second]==false)continue;
		diff-=v[i].first;
		was[v[i].second]=false;
		cnt++;
		if(diff<=0){printf("%i",cnt);return 0;}
	}
}