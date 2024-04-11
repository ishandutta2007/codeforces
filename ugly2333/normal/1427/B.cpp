//CF1427B
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
const int N = 222222;
int n,k;
char s[N];
vector<int> v;
int main()
{
	int T,i,f,x,y,z,o;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%s",&n,&k,s+1);
		f=0;
		v.clear();
		x=0;
		y=0;
		z=0;
		o=0;
		for(i=1;i<=n;i=i+1){
			if(s[i]=='L'){
				o++;
			}
			else{
				if(f){
					if(o)
						v.push_back(o);
				}
				else
					y=o,f=1;
				o=0;
				x++;
				if(s[i-1]=='W')
					x++;
			}
		}
		if(!x){
			if(k)
				cout<<min(k,n)*2-1<<endl;
			else
				cout<<0<<endl;
			continue;
		}
		if(o)
			z=o;
		sort(v.begin(),v.end());
		for(i=0;i<v.size();i=i+1){
			while(v[i]&&k){
				v[i]--,k--;
				x+=2;
			}
			if(!v[i])
				x++;
		}
		x+=min(k,y+z)*2;
		cout<<x<<endl;
	}
	return 0;
}