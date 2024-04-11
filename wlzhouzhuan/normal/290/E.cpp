// code by Peter0701
#include <bits/stdc++.h>  
using namespace std;
int q,sq,ctr,lens;
string s,res;
bool check()
{
	int lenr=res.size();
	string wynik;
	for(int i=0;i<lenr;i++)
	{
        if(res[i]=='H')
			wynik+='H';
        else
			for(int j=0;j<lenr;j++)
				wynik+=res[j];
        if(wynik.size()>1000*1000)
			break;
	}
	return wynik==s;
}
int main()
{
	cin>>s;
	lens=s.size();
	for(int i=0;i<lens;i++)
        if(s[i]=='Q')
			q++;
	if(q==0)
	{
        printf("Yes\n");
        return 0;
	}
	sq=sqrt(q);
	if(sq*sq!=q)
	{
        printf("No\n");
        return 0;
	}
	for(int i=0;i<lens;i++)
	{
        if(s[i]=='Q')
			break;
        ctr++;
	}
	if(ctr&1)
	{
        printf("No\n");
        return 0;
	}
	for(int i=0;i<ctr/2;i++)
		res+='H';
	for(int i=ctr;i<lens&&sq;i++)
	{
        if(s[i]=='Q')
			sq--;
        res+=s[i];
	}
	ctr=0;
	for(int i=lens-1;s[i]!='Q';i--)
        ctr++;
	if(ctr&1)
	{
        printf("No\n");
        return 0;
	}
	for(int i=0;i<ctr/2;i++)
		res+='H';
	if(check())
	{
        printf("Yes\n");
        return 0;
	}
	printf("No\n");
	return 0;
}