#include<cstdio>
#include<cstring>
#include<set>
#include<string>

using namespace std;

int fail[300];
int match(char *t,char *p)
{
//int *buildFail(char *p) {
  int m = strlen(p);
 // int *fail = new int[m+1];
  int j = fail[0] = -1;
  for (int i = 1; i <= m; ++i) {
    while (j >= 0 && p[j] != p[i-1]) j = fail[j];
    fail[i] = ++j;
  }
 // return fail;
//}
//int match(char *t, char *p, int *fail) {
  int n = strlen(t);// m = strlen(p);
  int count = 0;
  for (int i = 0, k = 0; i < n; ++i) {
    while (k >= 0 && p[k] != t[i]) k = fail[k];
    if (++k >= m) {
      ++count; // match at t[i-m+1 .. i]
      k = fail[k];
    }
  }
  return count;
}

char s[220],t[10][220];
char checked[220];
int l[10],r[10];

set<string> se;

int main()
{
	scanf("%s",s);
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		scanf("%s",t[i]);
		scanf("%d%d",l+i,r+i);
	}
	int ln=strlen(s);
	for(int a=0;a<ln;a++)
	{
		for(int b=a;b<ln;b++)
		{
			for(int i=0;i<b-a+1;i++)
			{
				checked[i]=s[a+i];
			}
			checked[b-a+1]='\0';
			bool ok=true;
			for(int k=0;k<N;k++)
			{
				int cnt=match(t[k],checked);
				if(!(l[k]<=cnt&&cnt<=r[k])) ok=false;
			}
			if(ok)
			{
				string str="";
				for(int i=0;i<b-a+1;i++) str+=s[a+i];
				se.insert(str);
			}
		}
	}
	printf("%d\n",se.size());
	return 0;
}