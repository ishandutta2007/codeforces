#include<cstdio>
#include<cstring>

using namespace std;

char a[1010],b[1010];

int main()
{
	scanf("%s%s",a,b);
	int an=0,bn=0;
	int aln=strlen(a),bln=strlen(b);
	for(int i=0;i<aln;i++) if(a[i]=='1') an++;
	for(int i=0;i<bln;i++) if(b[i]=='1') bn++;
	if(an%2==1) an++;
	if(an>=bn) printf("YES\n");
	else printf("NO\n");
	return 0;
}