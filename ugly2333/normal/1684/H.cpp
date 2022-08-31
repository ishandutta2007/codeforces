//CF1684H
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
typedef double DB;
const int N = 1111111;
char c[N];
vector<int> v;
int n,k,w,x;
int main()
{
	int T,i,j;
	scanf("%d",&T);
	while(T--){
		scanf("%s",c+1);
		n=strlen(c+1);
		k=0;
		for(i=1;i<=n;i++)
			k+=c[i]=='1';
		if(k==0){
			printf("-1\n");
			continue;
		}
		for(w=1;w<k;w<<=1);
		w-=k;
		v.clear();
		for(i=1;i<=n;i++){
			if(c[i]=='0'){
				v.push_back(i);
				continue;
			}
			if(i+2<=n){
				x=3+(c[i+1]=='1');
				if(w>=x){
					w-=x;
					v.push_back(i+2);
					i+=2;
					continue;
				}
			}
			if(i+1<=n){
				if(w>=1){
					w-=1;
					v.push_back(i+1);
					i++;
					continue;
				}
			}
			v.push_back(i);
		}
		if(k==5){
			v.clear();
			j=0;
			for(i=1;i+2<=n;i++)
				if(c[i]=='1'&&c[i+1]=='0')
					j=i;
			if(j){
				for(i=1;i<=n;i++)
					if(i!=j&&i!=j+1)
						v.push_back(i);
			}
			else{
				for(i=1;i<=n;i++)
					if(c[i]=='1')
						break;
				v.push_back(i);
				v.push_back(i+4);
				if(i+4!=n)
					v.push_back(n);
			}
		}
		printf("%d\n",v.size());
		x=0;
		for(i=0;i<v.size();i++)
			printf("%d %d\n",x+1,v[i]),x=v[i];
	}
	return 0;
}