#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,k,f[1000015];
char ch[1000015];
int main()
{
    scanf("%d%d",&n,&k);
    scanf("%s",ch+1);
    f[1]=0;
    for (int i=2;i<=n;i++){
    	int pre=f[i-1];
        while(pre&&ch[pre+1]!=ch[i]) pre=f[pre]; if(ch[pre+1]==ch[i]) pre++;
        f[i]=pre;
    }
    for (int i=1;i<=n;i++){
    	int k1=i/(i-f[i]),k2=(i-1)/(i-f[i])+1;
    	putchar('0'+(((k2-1)/(k+1)+1)<=(k1/k)));
    }
    putchar('\n');
    return 0;
}