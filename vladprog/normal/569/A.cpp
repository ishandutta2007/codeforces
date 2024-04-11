#include <cstdio>

int main(int argc, char const *argv[])
{
	int at=0,t,re=1;
	double q,s;
	scanf("%d %lf %lf",&t,&s,&q);
	q = (q-1)/q;
	while(at<t){
		if(s>=t) break;
		if(at>=s-1e-6) re+=1,at=1;
		else at+=1;
		s+=q;
	//	printf("%d %lf %lf\n",at,s,q);
	}
	printf("%d ",re);
	return 0;
}