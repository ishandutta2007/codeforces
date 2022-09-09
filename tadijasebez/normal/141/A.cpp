#include <stdio.h>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
vector<int> a,b;
char word[105];
int main()
{
	int n,i;
	bool ok=true;
	scanf("%s",&word);
	n=(unsigned) strlen(word);
	for(i=0;i<n;i++) a.push_back(word[i]);
	scanf("%s",&word);
	n=(unsigned) strlen(word);
	for(i=0;i<n;i++) a.push_back(word[i]);
	scanf("%s",&word);
	n=(unsigned) strlen(word);
	for(i=0;i<n;i++) b.push_back(word[i]);
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	if(a.size()==b.size())
	{
		for(i=0;i<a.size();i++) if(b[i]!=a[i]) ok=false;
	}
	else ok=false;
	if(ok) printf("YES\n");
	else printf("NO\n");
	return 0;
}