#include <cstdio>
#include <map>
#include <memory.h>
#include <algorithm>
#include <string>

int n,kb=1;
std::map<std::string,int> was;
bool found=true;       
std::string p,s="",a[120000];
int kg[13],b[13][13],ka,kk[13];

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		s+='0';
	was.clear();
	was[s]=true;
	while (found){
		found=false;
		a[ka++]=s;
		for (int i=0;i<n;i++){
			for (int j=0;j<=kb;j++){
				p=s;
				p[i]=j+'0';
				int kq=0;
				memset(kk,-1,sizeof(kk));
				for (int q=0;q<n;q++)
				{
					int w = p[q]-'0';
					if (kk[w]<0){
						p[q]=kq+'0';
						kk[w]=kq++;
					}else p[q]=kk[w]+'0';
				}
				kb=kq;
				if (was[p])continue;
				was[p]=true;
				s=p;
				found=true;break;
			}
			if (found)break;
		}
/*		printf("%d\n", ka);
		fflush(stdout);    */
	}
	printf("%d\n",ka);
	for (int i=0;i<ka;i++){
		s=a[i];
		memset(kg,0,sizeof(kg));
		n=0;
		for (int j=0;j<s.size();j++){
			b[s[j]-'0'][kg[s[j]-'0']++]=j;
			n=std::max(n,s[j]-'0'+1);
		}
		for (int j=0;j<n;j++){
			printf("{");
			for (int q=0;q<kg[j]-1;q++)
				printf("%d,",b[j][q]+1);
			printf("%d}",b[j][kg[j]-1]+1);
			if (j < n-1)putchar(',');
		}
		putchar('\n');
	}
}