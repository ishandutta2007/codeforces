#include<cstdio>

using namespace std;

int all[31];
bool taken[100100];

int main()
{
all[1]=1;
all[2]=2;
all[3]=1;
all[4]=4;
all[5]=3;
all[6]=2;
all[7]=1;
all[8]=5;
all[9]=6;
all[10]=2;
all[11]=1;
all[12]=8;
all[13]=7;
all[14]=5;
all[15]=9;
all[16]=8;
all[17]=7;
all[18]=3;
all[19]=4;
all[20]=7;
all[21]=4;
all[22]=2;
all[23]=1;
all[24]=10;
all[25]=9;
all[26]=3;
all[27]=6;
all[28]=11;
all[29]=12;
all[30]=14;
	int N;
	scanf("%d",&N);
	int cnt=0;
	int gr=0;
	gr^=all[1];
	cnt++;
	for(int i=0;i<100100;i++) taken[i]=false;
	for(int i=2;i*i<=N;i++)
	{
		if(taken[i]==false)
		{
			int c=0;
			long long tmp=i;
			while(tmp<=N)
			{
				if(tmp<100100) taken[tmp]=true;
				c++;
				tmp*=i;
			}
			gr^=all[c];
			cnt+=c;
		}
	}
	int remain=N-cnt;
	if(remain%2==1) gr^=1;
	if(gr==0) printf("Petya\n");
	else printf("Vasya\n");
	return 0;
}