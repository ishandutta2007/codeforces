//CF1662D
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
const int N = 222;
char c[N];
vector<int> v,v1,v2;
void ins(int x){//cout<<x<<endl;
	if(v.size()==0){
		v.push_back(x);
		return;
	}
	if(v.back()==x)
		v.pop_back();
	else
		v.push_back(x);
}
vector<int> solve(){
	int i=0,x=0;
	v.clear();
	while(c[i]){
		if(c[i]=='B')
			x^=1;
		else
			ins(c[i]=='A');
		i++;
	}
	v.push_back(x+100);
	return v;
}
int main()
{
	int T,i;
	scanf("%d",&T);
	while(T--){
		scanf("%s",c);
		v1=solve();
		scanf("%s",c);
		v2=solve();
		if(v1.size()==v2.size()){
			for(i=0;i<v1.size();i++)
				if(v1[i]!=v2[i])
					break;
			if(i>=v1.size()){
				printf("YES\n");
				continue;
			}
		}
		printf("NO\n");
	}
	return 0;
}