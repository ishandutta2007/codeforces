#include <cstdio>
#include <vector>
using namespace std;
#define max_n 100000
vector<int> pos[26];
char s[max_n+1];
int main(){
	int n,q;
	scanf("%d%d\n%s",&n,&q,s);
	for(int i=0; i<n; ++i)
		pos[s[i]-'a'].push_back(i);
	for(int l,r,k; q; --q){
		scanf("%d%d%d",&l,&r,&k);
		for(int i=!k*26,cur=--l; cur<r; i+=k-!k)
			for(vector<int>::iterator j=lower_bound(pos[i].begin(),pos[i].end(),l); j!=pos[i].end()&&pos[i][j-pos[i].begin()]<r; ++j)
				*j=cur++;
	}
	for(int i=0; i<26; ++i)
		for(vector<int>::iterator p=pos[i].begin(),ed=pos[i].end(); p!=ed; ++p)
			s[*p]='a'+i;
	printf("%s\n",s);
	return 0;
}