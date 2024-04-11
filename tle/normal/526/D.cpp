#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <algorithm>
using namespace std;
#define SZ 2333333
int k;
struct HashKMP
{
char s[SZ+1]; int n;
int next[SZ+3];
void gnext()
{
	n=strlen(s);
    next[0]=-1;
    int j=-1;
    for(int i=1;s[i];i++)
    {
        while(j!=-1&&s[i]!=s[j+1]) j=next[j];
        if(s[i]==s[j+1]) ++j;
        next[i]=j;
    }
    for(int i=0;s[i];i++)
    {
    	int len_s=i-next[i],len_t=(i+1)%len_s;
    	int cnt_s=(i+1-len_t)/len_s;
    	if(cnt_s/k*len_s>=cnt_s%k*len_s+len_t) putchar('1');
    	else putchar('0');
	}
}
}ha;
int main()
{
    scanf("%*d%d%s",&k,ha.s);
    ha.gnext();
}