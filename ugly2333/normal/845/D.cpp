//CF 845D
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
pair<int,int> st1[222222];
int st2[222222],sz1,sz2;
int main()
{
	int n,x,y,ans,v;
	scanf("%d",&n);
	ans=0;
	while(n--){
		scanf("%d",&x);
		if(x==1||x==3)
			scanf("%d",&y);
		else
			y=0;
		
		if(x==3||x==5){
			if(x==3&&y<v){
				ans++;
				continue;
			}
			sz1++;
			st1[sz1]=make_pair(x,y);
		}
		if(x==1){
			v=y;
			while(sz1&&st1[sz1].first==3&&st1[sz1].second<y){
				st1[sz1]=make_pair(0,0);
				sz1--;
				ans++;
			}
		}
		
		if(x==4||x==6){
			sz2++;
			st2[sz2]=x;
		}
		if(x==2){
			while(sz2&&st2[sz2]==6){
				st2[sz2]=0;
				sz2--;
				ans++;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}