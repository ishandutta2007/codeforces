#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,c,i;
	scanf("%i %i",&n,&c);
	vector<int> t(n),p(n);
	for(int &i:p) scanf("%i",&i);
	for(int &i:t) scanf("%i",&i);
	int sum=0;
	int Radewoosh=0,Limak=0;
	for(int i=0;i<n;i++) sum+=t[i],Limak+=max(0,p[i]-sum*c);
	sum=0;
	for(int i=n-1;~i;i--) sum+=t[i],Radewoosh+=max(0,p[i]-sum*c);
	if(Radewoosh>Limak) printf("Radewoosh\n");
	else if(Limak>Radewoosh) printf("Limak\n");
	else printf("Tie\n");
	return 0;
}