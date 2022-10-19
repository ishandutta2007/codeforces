#include<bits/stdc++.h>
using namespace std;
int T,n;
vector<pair<int,int> >v;
int part(int ip){
	for(int i=2;i*i<=ip;i++){
		if(ip%i)continue;
		int cnt=0;
		while(!(ip%i))ip/=i,cnt++;
		v.push_back(make_pair(i,cnt));
	}
	if(ip!=1)v.push_back(make_pair(ip,1));
}
int main(){
	scanf("%d",&T);
	while(T--){
		v.clear();
		scanf("%d",&n);
		part(n);
		if(v.size()>=3){
			puts("YES");
			int x=1;
			for(int i=0;i<v[0].second;i++)x*=v[0].first;
			printf("%d ",x);
			x=1;
			for(int i=0;i<v[1].second;i++)x*=v[1].first;
			printf("%d ",x);
			x=1;
			for(int i=2;i<v.size();i++)for(int j=0;j<v[i].second;j++)x*=v[i].first;
			printf("%d ",x);
			puts("");
			continue;
		}
		if(v.size()==2){
			int x=v[0].second,y=v[1].second;
			if((x>=2&&y>=2)||(x>=3&&y>=1)||(x>=1&&y>=3)){
				puts("YES");
				printf("%d %d ",v[0].first,v[1].first);
				int z=1;
				for(int i=1;i<x;i++)z*=v[0].first;
				for(int i=1;i<y;i++)z*=v[1].first;
				printf("%d\n",z);
				continue;
			}
			puts("NO");
			continue;
		}
		if(v.size()==1){
			if(v[0].second>=6){
				puts("YES");
				printf("%d %d ",v[0].first,v[0].first*v[0].first);
				int z=1;
				for(int i=3;i<v[0].second;i++)z*=v[0].first;
				printf("%d\n",z);
				continue;
			}
		}
		puts("NO");
		continue;
	}
	return 0;
}